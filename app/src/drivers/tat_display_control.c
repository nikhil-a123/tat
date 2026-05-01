
#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>
#include <zephyr/logging/log.h>
#include "lvgl.h"

#include "tat_display_control.h"

static const struct device *display = DEVICE_DT_GET_OR_NULL(DT_CHOSEN(zephyr_display));

K_MUTEX_DEFINE(display_mutex);

static void lvgl_render(struct k_work *item);
K_WORK_DELAYABLE_DEFINE(lvgl_work, lvgl_render);
static struct k_work_sync cancel_work_sync;

typedef enum display_state {
    DISPLAY_STATE_AWAKE,
    DISPLAY_STATE_SLEEPING
} display_state_t;

static display_state_t display_state;

LOG_MODULE_REGISTER(display_control, LOG_LEVEL_WRN);

void tat_display_control_init(void)
{
	if (!device_is_ready(display)) {
		LOG_ERR("Display is not ready!");
	}

    display_state = DISPLAY_STATE_SLEEPING;
}

int tat_display_control_sleep_ctrl(bool on)
{
    int res = -EALREADY;

    k_mutex_lock(&display_mutex, K_FOREVER);

    switch (display_state) {
        case DISPLAY_STATE_AWAKE:
            if (on) {
                LOG_DBG("Display already awake");
                res = -EALREADY;
            } else {
                LOG_DBG("Put display to sleep");
                // Cancel pending call to lv_task_handler
                // Or let it finish if it's running.
                k_work_cancel_delayable_sync(&lvgl_work, &cancel_work_sync);
                display_state = DISPLAY_STATE_SLEEPING;
                display_blanking_on(display);
                // Prepare for next call to lv_task_handler when screen is enabled again,
                // Since the display will have been powered off, we need to tell LVGL
                // to rerender the complete display.
                lv_obj_invalidate(lv_scr_act());
                // Disable XIP when display sleeps
                res = 0;
            }
            break;
        case DISPLAY_STATE_SLEEPING:
            if (on) {
                LOG_DBG("Wake up display");
                // Enable XIP before waking display
                display_state = DISPLAY_STATE_AWAKE;
                display_blanking_off(display);
                k_work_schedule(&lvgl_work, K_MSEC(250));
                res = 0;
            } else {
                LOG_DBG("Display already sleeping");
                res = -EALREADY;
            }
            break;
    }

    k_mutex_unlock(&display_mutex);

    return res;
}

static void lvgl_render(struct k_work *item)
{
    const int64_t next_update_in_ms = lv_task_handler();
    k_work_schedule(&lvgl_work, K_MSEC(next_update_in_ms));
}