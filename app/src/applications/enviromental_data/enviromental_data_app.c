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

#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/logging/log.h>

#include <lvgl.h>
#include <stdbool.h>

#include "enviromental_data_app.h"

#define MAX_ENV_SCREENS 8

static lv_obj_t *root_page = NULL;

static bool running;
static bool views_created;

static enviromental_data_ui_api_t *screens[MAX_ENV_SCREENS];
static uint8_t num_screens;
static uint8_t current_screen_index;

/* For sending work to enviromental screens */
typedef enum work_type {
    OPEN_SCREEN,
    UPDATE_CLOCK,
    UPDATE_ENVIROMENTAL_DATA
} work_type_t;

typedef struct delayed_work_item {
    struct k_work_delayable work;
    work_type_t             type;
} delayed_work_item_t;

static delayed_work_item_t clock_work = { .type = UPDATE_CLOCK };
static delayed_work_item_t general_work_item;
static struct k_work_sync cancel_work_sync;

static void general_work(struct k_work *item);

LOG_MODULE_REGISTER(enviromental_data_app);


//#define NORMAL_TIME_UPDATE_INTERVAL   K_MSEC(1000)
//#define SMOOTH_TIME_UPDATE_INTERVAL   K_MSEC(50)

//#define WORK_STACK_SIZE 3000
//#define WORK_PRIORITY   5

//static watchface_app_evt_listener watchface_evt_cb;

static int enviromental_data_app_init(void)
{
    k_work_init_delayable(&general_work_item.work, general_work);
    k_work_init_delayable(&clock_work.work, general_work);
    running = false;
    views_created = false;
    LOG_INF("enviromental data app init!");
    return 0;
}

void enviromental_data_app_register_ui(enviromental_data_ui_api_t *ui_api)
{
    __ASSERT(num_screens < MAX_ENV_SCREENS, "Too many screens, increase MAX_ENV_SCREENS");
    screens[num_screens] = ui_api;
    LOG_INF("Registering screen %d", num_screens);
    num_screens++;
}

void enviromental_data_app_start(lv_obj_t *root_screen, lv_group_t *group)
{
    LOG_INF("Enviromental data start!");
    __ASSERT(num_screens > 0, "Must enable at least one screen!");

    // Here we would load the enviromental screen settings which
    // contains which screen to use
    // For now just default to screen 0
    current_screen_index = 0;

    root_page = root_screen;
    //watchface_evt_cb = evt_cb;
    views_created = false;

    //lv_obj_add_event_cb(watchface_root_screen, watchface_gesture_cb, LV_EVENT_GESTURE, NULL);

    // Place work on workqueue to open a new enviromental screen
    general_work_item.type = OPEN_SCREEN;
    __ASSERT(0 <= k_work_schedule(&general_work_item.work, K_MSEC(100)), "FAIL schedule");
}

void enviromental_data_app_stop(void)
{
    running = false;
    //is_suspended = false;
    k_work_cancel_delayable_sync(&clock_work.work, &cancel_work_sync);
    k_work_cancel_delayable_sync(&general_work_item.work, &cancel_work_sync);

    if (views_created) {
        screens[current_screen_index]->remove();
    }

    // remove screen callback, enable when that's implemented
/*     if (root_page != NULL && lv_obj_is_valid(root_page)) {
        lv_obj_remove_event_cb(root_page, watchface_gesture_cb);
    } */

    views_created = false;
    root_page = NULL;
}

void enviromental_data_app_screen_change(int index)
{
    if (num_screens == 1) {
        return;
    }

    if ((index < 0) || (index >= num_screens)) {
        return;
    }

    screens[current_screen_index]->remove();

    // Make sure we have the latest settings
/*     int err = settings_load_subtree_direct(ZSW_SETTINGS_WATCHFACE, settings_load_handler_watchface, &watchface_settings);
    if (err != 0) {
        LOG_ERR("Failed loading watchface settings");
    } */

    current_screen_index = index;

/*     err = settings_save_one(ZSW_SETTINGS_WATCHFACE, &watchface_settings, sizeof(watchface_settings));
    if (err != 0) {
        LOG_ERR("Failed saving watchface settings");
    } */

    if (running) {
        general_work_item.type = OPEN_SCREEN;
        __ASSERT(0 <= k_work_schedule(&general_work_item.work, K_MSEC(100)), "FAIL schedule");
        __ASSERT(-1, "test!");
    }
}

int enviromental_data_app_get_current_screen(void)
{
    return current_screen_index;
}

int enviromental_data_app_get_num_screens(void)
{
    return num_screens;

}

int enviromental_data_app_get_screen_info(int index, const char **name)
{
    if (index >= num_screens) {
        return -EEXIST;
    }

    *name = screens[index]->name;

    return 0;
}

static void refresh_ui(void)
{
/*     uint32_t steps;
    watchfaces[watchface_settings.watchface_index]->set_ble_connected(is_connected);
    watchfaces[watchface_settings.watchface_index]->set_battery_percent(last_batt_evt.percent, last_batt_evt.mV);
    if (watchfaces[watchface_settings.watchface_index]->set_charging) {
        watchfaces[watchface_settings.watchface_index]->set_charging(last_batt_evt.is_charging);
    }
    zsw_watchface_dropdown_ui_set_battery_info(last_batt_evt.percent, last_batt_evt.is_charging, last_batt_evt.tte,
                                               last_batt_evt.ttf);
    if (strlen(last_weather_data.report_text) > 0) {
        watchfaces[watchface_settings.watchface_index]->set_weather(last_weather_data.temperature_c,
                                                                    last_weather_data.weather_code);
    }
    if (zsw_imu_fetch_num_steps(&steps) == 0) {
        // TODO: Add calculation for distance and kcal
        watchfaces[watchface_settings.watchface_index]->set_step(steps, 0, 0);
    }
    if (strlen(last_music_info.track_name) > 0) {
        zsw_watchface_dropdown_ui_set_music_info(last_music_info.track_name, last_music_info.artist);
    } */
}

static void general_work(struct k_work *item)
{
    LOG_INF("general work called!");
    struct k_work_delayable *delayable_work = CONTAINER_OF(item, struct k_work_delayable, work);

    delayed_work_item_t *the_work = CONTAINER_OF(delayable_work, delayed_work_item_t, work);

    switch (the_work->type) {
        case OPEN_SCREEN: {
            //LOG_INF("general work: OPEN_SCREEN");
            // Open a new enviromental data screen
            running = true;
            // Dropdown
            screens[current_screen_index]->show(root_page);
            //zsw_watchface_dropdown_ui_add(watchface_root_screen, watchface_evt_cb, zsw_display_control_get_brightness());
            views_created = true;
            refresh_ui();

            // Update clock immediately
            //__ASSERT(0 <= k_work_schedule(&clock_work.work, K_NO_WAIT), "FAIL clock_work");
            // Update enviromental data after a delay
            general_work_item.type = UPDATE_ENVIROMENTAL_DATA;
            __ASSERT(0 <= k_work_schedule(&general_work_item.work, K_MSEC(500)), "FAIL schedule");
            break;
        }
        case UPDATE_CLOCK: {
/*             zsw_timeval_t time;
            zsw_clock_get_time(&time);

            if (watchfaces[watchface_settings.watchface_index]->set_datetime) {
                // TODO: Add support for AM and 12/24 h mode
                watchfaces[watchface_settings.watchface_index]->set_datetime(time.tm.tm_wday, time.tm.tm_mday, time.tm.tm_mday,
                                                                             time.tm.tm_mon,
                                                                             time.tm.tm_year, time.tm.tm_wday, time.tm.tm_hour, time.tm.tm_min, time.tm.tm_sec, time.tv_usec, false, false);
            }

            __ASSERT(0 <= k_work_schedule(&clock_work.work,
                                          watchface_settings.smooth_second_hand ? SMOOTH_TIME_UPDATE_INTERVAL : NORMAL_TIME_UPDATE_INTERVAL), "FAIL clock_work"); */
            break;
        }
        case UPDATE_ENVIROMENTAL_DATA: {
            //LOG_INF("general work: UPDATE_ENVIROMENTAL_DATA");
            // Update the enviromental data
/*             float pressure = 0.0;

            zsw_pressure_sensor_get_pressure(&pressure);
            screens[current_screen_index]->set_watch_env_sensors((int)pressure);

            __ASSERT(0 <= k_work_schedule(&date_work.work, SLOW_UPDATE_INTERVAL), "FAIL date_work"); */
            break;
        }
    }
}

SYS_INIT(enviromental_data_app_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);