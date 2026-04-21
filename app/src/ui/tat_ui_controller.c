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
#include "tat_app_manager.h"
#include "tat_ui_controller.h"
#include "tat_ui.h"

// Declare external fonts
LV_FONT_DECLARE(roboto_medium_16);

static void run_input_work(struct k_work *item);

static struct input_worker_item_t {
    struct k_work work;
    struct input_event event;
} 

input_worker_item = {
    .work = Z_WORK_INITIALIZER(run_input_work),
};

typedef enum ui_state {
    INIT_STATE,
    ENVIROMENTAL_DATA_STATE,
    APP_MENU_STATE,
} ui_state_t;

static struct input_event last_input_event;

static bool is_buttons_for_lvgl = false;
static ui_state_t ui_state = INIT_STATE;

#define KEYS_NODE DT_CHOSEN(zephyr_display)

static lv_obj_t *root_screen;
static lv_group_t *input_group;
static lv_indev_t *enc_indev;
static uint8_t last_pressed;

static void encoder_read(lv_indev_t *indev, lv_indev_data_t *data);
static void on_input_subsys_callback(struct input_event *evt, void *user_data);
static void open_appplication(void *app_name);
static void on_app_menu_close(void);
static void async_turn_off_buttons_allocation(void *unused);
/* static void on_watchface_app_event_callback(watchface_app_evt_t evt); */
/* static void async_turn_off_buttons_allocation(void *unused);
static void open_application_manager_page(void *app_name);
static void on_application_manager_close(void);
static void on_onboarding_done(void); */

INPUT_CALLBACK_DEFINE(NULL, on_input_subsys_callback, NULL);

LOG_MODULE_REGISTER(tat_ui_controller, CONFIG_TAT_UI_LOG_LEVEL);

static void run_input_work(struct k_work *item)
{
    struct input_worker_item_t *container = CONTAINER_OF(item, struct input_worker_item_t, work);

    LOG_DBG("Input worker code: %u", container->event.code);

    if (container->event.type == INPUT_EV_KEY) {
        switch (container->event.code) {
            case INPUT_KEY_1: 
                // Open app menu
                open_appplication(NULL);
                break;
        }
    }

    // Handled by LVGL
    if (container->event.type == INPUT_EV_KEY) {
        if (is_buttons_for_lvgl) {
            memcpy(&last_input_event, &container->event, sizeof(struct input_event));
            return;
        }
    }
}

static void encoder_read(lv_indev_t *indev, lv_indev_data_t *data)
{
    if (!is_buttons_for_lvgl) {
        return;
    } 

    if (last_input_event.code == INPUT_KEY_1) {
        data->key = LV_KEY_ENTER;
        data->state = LV_INDEV_STATE_PR;
        last_pressed = 1;
    } else if (last_input_event.code == INPUT_KEY_2) {
        data->key = LV_KEY_PREV;
        data->state = LV_INDEV_STATE_PR;
        last_pressed = 2;
    } else if (last_input_event.code == INPUT_KEY_3) {
        data->key = LV_KEY_UP;
        data->state = LV_INDEV_STATE_PR;
        last_pressed = 3;
    } else if (last_input_event.code == INPUT_KEY_4) {
        data->key = LV_KEY_DOWN;
        data->state = LV_INDEV_STATE_PR;
        last_pressed = 4;
    } else {
        if (last_pressed == 0xFF) {
            return;
        }
        data->state = LV_INDEV_STATE_REL;
        switch (last_pressed) {
            case 1:
                data->key = LV_KEY_ENTER;
                break;
            case 2:
                data->key = LV_KEY_PREV;
                break;
            case 3:
                data->key = LV_KEY_UP;
                break;
            case 4:
                data->key = LV_KEY_DOWN;
                break;
            default:
                break;
        }
        last_pressed = 0xFF;
    }

    last_input_event.code = 0xFF;
}

static void on_input_subsys_callback(struct input_event *evt, void *user_data)
{
    LOG_INF("Input event received: type=%u, code=%u, value=%d", evt->type, evt->code, evt->value);

    // The following events are ignored (will block a wakeup of the display):
    //  - Other input events
    if (((evt->code != INPUT_EV_DEVICE) && (evt->value == 1))) {
        return;
    }

    input_worker_item.event = *evt;
    k_work_submit(&input_worker_item.work);
}

// Functions for opening applications
// Pass NULL to open the app menu screen so the user can manually
// pick an app to open, or pass an applications name to directly
// open the app without going through the app menu
static void open_appplication(void *app_name)
{
    if (ui_state != ENVIROMENTAL_DATA_STATE) {
        return;
    }
    // Stop the enviromental data screen and tell LVGL to use the button inputs
    enviromental_data_app_stop();
    is_buttons_for_lvgl = true;
    ui_state = APP_MENU_STATE;
    tat_app_manager_show(on_app_menu_close, root_screen, input_group, (char *)app_name);
}

// Callback function executed when the app menu is closed
static void on_app_menu_close(void)
{
    tat_app_manager_delete();
    ui_state = ENVIROMENTAL_DATA_STATE;
    enviromental_data_app_start(root_screen, input_group);
    lv_async_call(async_turn_off_buttons_allocation, NULL);
}

static void async_turn_off_buttons_allocation(void *unused)
{
    is_buttons_for_lvgl = false;
}

int tat_ui_controller_init(void)
{
    root_screen = lv_screen_active();

    // Set roboto as default text font
    lv_obj_set_style_text_font(root_screen, &roboto_medium_16, LV_PART_MAIN);

    /* Associate the user input encoder with the widget group */
    enc_indev = lv_indev_create();
    lv_indev_set_type(enc_indev, LV_INDEV_TYPE_ENCODER);
    lv_indev_set_read_cb(enc_indev, encoder_read);

    input_group = lv_group_create();
    lv_group_set_default(input_group);
    lv_indev_set_group(enc_indev, input_group);

    // Start the enviromental data screen here...
    enviromental_data_app_start(root_screen, input_group);
    ui_state = ENVIROMENTAL_DATA_STATE;

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
