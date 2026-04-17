/*
 * This file is part of ZSWatch project <https://github.com/zswatch/>.
 * Copyright (c) 2025 ZSWatch Project.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <zephyr/input/input.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include <stdint.h>
#include <string.h>

#include <lvgl.h>
#include <lvgl_input_device.h>

#include "enviromental_data/enviromental_data_app.h"
//#include "tat_application_manager.h"
#include "tat_ui_controller.h"
#include "tat_ui.h"

// Declare external fonts
LV_FONT_DECLARE(roboto_medium_16);

//static void run_input_work(struct k_work *item);

/* static struct input_worker_item_t {
    struct k_work work;
    struct input_event event;
}  */

/* input_worker_item = {
    .work = Z_WORK_INITIALIZER(run_input_work),
}; */
/* 
static struct input_event last_input_event; */

/* static bool is_buttons_for_lvgl = false; */

#define KEYS_NODE DT_CHOSEN(zephyr_display)

static const struct device *const keys = DEVICE_DT_GET(DT_COMPAT_GET_ANY_STATUS_OKAY(zephyr_lvgl_keypad_input));

//static struct input_event last_input_event;

static lv_obj_t *root_screen;
static lv_group_t *input_group;
static lv_indev_t *keys_indev;
//static uint8_t last_pressed;

//static void encoder_read(lv_indev_t *indev, lv_indev_data_t *data);
static void on_input_subsys_callback(struct input_event *evt, void *user_data);
/* static void on_watchface_app_event_callback(watchface_app_evt_t evt); */
/* static void async_turn_off_buttons_allocation(void *unused);
static void open_application_manager_page(void *app_name);
static void on_application_manager_close(void);
static void on_onboarding_done(void); */

INPUT_CALLBACK_DEFINE(NULL, on_input_subsys_callback, NULL);

LOG_MODULE_REGISTER(tat_ui_controller, CONFIG_TAT_UI_LOG_LEVEL);

/* static void run_input_work(struct k_work *item)
{
    struct input_worker_item_t *container = CONTAINER_OF(item, struct input_worker_item_t, work);

    LOG_DBG("Input worker code: %u", container->event.code);

    // Don't process the press if it caused wakeup.
    if (zsw_power_manager_reset_idle_timout()) {
        return;
    }

    // Handled by LVGL
    if (container->event.type == INPUT_EV_KEY) {
        if (is_buttons_for_lvgl) {
            memcpy(&last_input_event, &container->event, sizeof(struct input_event));
            return;
        }
    }
} */

/* static void on_input_subsys_callback(struct input_event *evt, void *user_data)
{
    LOG_DBG("Input event received: type=%u, code=%u, value=%d", evt->type, evt->code, evt->value);

    // The following events are ignored (will block a wakeup of the display):
    //  - Generic touch events (INPUT_BTN_TOUCH, INPUT_ABS_X, INPUT_ABS_Y)
    //  - Raw button codes before longpress processing (INPUT_KEY_KP0, INPUT_KEY_KP1)
    //  - Quick-record long-press code (INPUT_KEY_F1) — handled by zsw_quick_record
    if ((evt->code == INPUT_ABS_X) || (evt->code == INPUT_ABS_Y) || (evt->code == INPUT_BTN_TOUCH) ||
        (evt->code == INPUT_KEY_KP0) || (evt->code == INPUT_KEY_KP1) ||
#ifdef CONFIG_APPLICATIONS_USE_VOICE_MEMO
        (evt->code == INPUT_KEY_F1) ||
#endif
        ((evt->code != INPUT_EV_DEVICE) && (evt->value == 1))) {
        return;
    }

    input_worker_item.event = *evt;
    k_work_submit(&input_worker_item.work);
} */

/* static void encoder_read(lv_indev_t *indev, lv_indev_data_t *data)
{
    if (!is_buttons_for_lvgl) {
        return;
    } 

    if (last_input_event.code == INPUT_KEY_4) {
        data->key = LV_KEY_LEFT;
        data->state = LV_INDEV_STATE_PR;
        last_pressed = 2;
    } else if (last_input_event.code == INPUT_KEY_1) {
        data->key = LV_KEY_ENTER;
        data->state = LV_INDEV_STATE_PR;
        last_pressed = 1;
    } else if (last_input_event.code == INPUT_KEY_2) {
        data->key = LV_KEY_RIGHT;
        data->state = LV_INDEV_STATE_PR;
        last_pressed = 3;
    } else if (last_input_event.code == INPUT_KEY_3) {
        // Not used for now. TODO exit/back button.
    } else {
        if (last_pressed == 0xFF) {
            return;
        }
        data->state = LV_INDEV_STATE_REL;
        switch (last_pressed) {
            case 2:
                data->key = LV_KEY_RIGHT;
                break;
            case 1:
                data->key = LV_KEY_ENTER;
                break;
            case 3:
                data->key = LV_KEY_LEFT;
                break;
            default:
                break;
        }
        last_pressed = 0xFF;
    }

    last_input_event.code = 0xFF;
} */

/* static void on_watchface_app_event_callback(watchface_app_evt_t evt)
{
    if (watch_state != WATCHFACE_STATE) {
        return;
    }
    if (evt.type == WATCHFACE_APP_EVENT_GESTURE) {
        handle_screen_gesture(evt.data.gesture_direction);
        return;
    }

    if (watch_state == WATCHFACE_STATE && !zsw_notification_popup_is_shown()
#ifdef CONFIG_APPLICATIONS_USE_VOICE_MEMO
        && !zsw_recording_overlay_is_shown()
        && !zsw_voice_memo_popup_is_shown()
#endif
       ) {
        switch (evt.type) {
            case WATCHFACE_APP_EVENT_OPEN_APP:
                handle_watchface_open_app_event(evt.data.app);
                break;
            case WATCHFACE_APP_EVENT_SET_BRIGHTNESS:
                zsw_display_control_set_brightness(evt.data.brightness);
                zsw_settings_brightness_t brightness = evt.data.brightness;
                if (evt.data.store_brightness) {
                    settings_save_one(ZSW_SETTINGS_BRIGHTNESS, &brightness, sizeof(brightness));
                }
                break;
            case WATCHFACE_APP_EVENT_RESTART:
                sys_reboot(SYS_REBOOT_COLD);
                break;
            case WATCHFACE_APP_EVENT_SHUTDOWN:
#if CONFIG_DT_HAS_NORDIC_NPM1300_ENABLED
                int ret = zsw_pmic_power_down();
                if (ret == -ENOTSUP) {
                    // If the nPM1300 is charging thenpowering down/entering ship mode is not possible
                    // Instead we just do a reset
                    ret = zsw_pmic_reset();
                    if (ret) {
                        LOG_ERR("Failed to power down or reset the PMIC");
                    }
                }
#endif
                break;
            default:
                break;
        }
    }
} */

static void on_input_subsys_callback(struct input_event *evt, void *user_data)
{
    LOG_INF("Input event received: type=%u, code=%u, value=%d", evt->type, evt->code, evt->value);

    // The following events are ignored (will block a wakeup of the display):
    //  - Generic touch events (INPUT_BTN_TOUCH, INPUT_ABS_X, INPUT_ABS_Y)
    //  - Raw button codes before longpress processing (INPUT_KEY_KP0, INPUT_KEY_KP1)
/*     if ((evt->code == INPUT_ABS_X) || (evt->code == INPUT_ABS_Y) || (evt->code == INPUT_BTN_TOUCH) ||
        (evt->code == INPUT_KEY_KP0) || (evt->code == INPUT_KEY_KP1) ||
#ifdef CONFIG_APPLICATIONS_USE_VOICE_MEMO
        (evt->code == INPUT_KEY_F1) ||
#endif
        ((evt->code != INPUT_EV_DEVICE) && (evt->value == 1))) {
        return;
    } */

    //input_worker_item.event = *evt;
    //k_work_submit(&input_worker_item.work);
}

int tat_ui_controller_init(void)
{
    root_screen = lv_screen_active();

    // Set roboto as default text font
    lv_obj_set_style_text_font(root_screen, &roboto_medium_16, LV_PART_MAIN);

    /* Associate the user input keys with the widget group */
    keys_indev = lvgl_input_get_indev(keys);
    lv_indev_set_group(keys_indev, input_group);

    input_group = lv_group_create();
    lv_group_set_default(input_group);
    lv_indev_set_group(keys_indev, input_group);

    // Start the enviromental data screen here...
    enviromental_data_app_start(root_screen, input_group);

    LOG_INF("UI Controller initialized");

    return 0;
}

/* void zsw_ui_controller_launch_app(const char *app_name)
{
    static char launch_app_name_buf[64];
    strncpy(launch_app_name_buf, app_name, sizeof(launch_app_name_buf) - 1);
    launch_app_name_buf[sizeof(launch_app_name_buf) - 1] = '\0';
    lv_async_call(open_application_manager_page, launch_app_name_buf);
} */

/* zsw_ui_state_t zsw_ui_controller_get_state(void)
{
    switch (watch_state) {
        case INIT_STATE:
            return ZSW_UI_STATE_INIT;
        case WATCHFACE_STATE:
            return ZSW_UI_STATE_WATCHFACE;
        case APPLICATION_MANAGER_STATE:
            return ZSW_UI_STATE_APP_MANAGER;
        default:
            return ZSW_UI_STATE_INIT;
    }
} */

/* const char *zsw_ui_controller_get_running_app_name(void)
{
    if (watch_state != APPLICATION_MANAGER_STATE) {
        return NULL;
    }
    int num_apps = zsw_app_manager_get_num_apps();
    for (int i = 0; i < num_apps; i++) {
        application_t *app = zsw_app_manager_get_app(i);
        if (app && app->current_state != ZSW_APP_STATE_STOPPED) {
            return app->name;
        }
    }
    return NULL;
} */
