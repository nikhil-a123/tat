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

static enviromental_data_ui_api_t *screens[MAX_ENV_SCREENS];
static uint8_t num_screens;

LOG_MODULE_REGISTER(enviromental_data_app, LOG_LEVEL_WRN);


//#define NORMAL_TIME_UPDATE_INTERVAL   K_MSEC(1000)
//#define SMOOTH_TIME_UPDATE_INTERVAL   K_MSEC(50)

//#define WORK_STACK_SIZE 3000
//#define WORK_PRIORITY   5



//static watchface_app_evt_listener watchface_evt_cb;

void enviromental_data_app_start(lv_obj_t *root_screen, lv_group_t *group)
{
    __ASSERT(num_screens > 0, "Must enable at least one screen!");

    root_screen = root_screen;
    //watchface_evt_cb = evt_cb;
    screen_views_created = false;

    //lv_obj_add_event_cb(watchface_root_screen, watchface_gesture_cb, LV_EVENT_GESTURE, NULL);

    //general_work_item.type = OPEN_WATCHFACE;
    //__ASSERT(0 <= k_work_schedule(&general_work_item.work, K_MSEC(100)), "FAIL schedule");
}

void enviromental_data_app_stop(void)
{
    running = false;
    is_suspended = false;
    //k_work_cancel_delayable_sync(&clock_work.work, &cancel_work_sync);
    //k_work_cancel_delayable_sync(&update_work.work, &cancel_work_sync);
    //k_work_cancel_delayable_sync(&date_work.work, &cancel_work_sync);
    //k_work_cancel_delayable_sync(&general_work_item.work, &cancel_work_sync);

    if (screen_views_created) {
        screens[watchface_settings.watchface_index]->remove();
        zsw_watchface_dropdown_ui_remove();
    }

    if (watchface_root_screen != NULL && lv_obj_is_valid(watchface_root_screen)) {
        lv_obj_remove_event_cb(watchface_root_screen, watchface_gesture_cb);
    }

    watchface_views_created = false;
    watchface_root_screen = NULL;
}

static int enviromental_data_app_init(void)
{
    running = false;
    is_suspended = false;
    watchface_views_created = false;

    return 0;
}

void enviromental_data_app_register_ui(enviromental_data_ui_api_t *ui_api)
{
    __ASSERT(num_screens < MAX_ENV_SCREENS, "Too many screens, increase MAX_ENV_SCREENS");
    screens[num_screens] = ui_api;
    num_screens++;
}

void watchface_change(int index)
{
    if (num_watchfaces == 1) {
        return;
    }

    if ((index < 0) || (index >= num_watchfaces)) {
        return;
    }

    watchfaces[watchface_settings.watchface_index]->remove();

    // Make sure we have the latest settings
    int err = settings_load_subtree_direct(ZSW_SETTINGS_WATCHFACE, settings_load_handler_watchface, &watchface_settings);
    if (err != 0) {
        LOG_ERR("Failed loading watchface settings");
    }

    watchface_settings.watchface_index = index;

    err = settings_save_one(ZSW_SETTINGS_WATCHFACE, &watchface_settings, sizeof(watchface_settings));
    if (err != 0) {
        LOG_ERR("Failed saving watchface settings");
    }
    if (running) {
        general_work_item.type = OPEN_WATCHFACE;
        __ASSERT(0 <= k_work_schedule(&general_work_item.work, K_MSEC(100)), "FAIL schedule");
    }
}

int watchface_app_get_current_face(void)
{
    return watchface_settings.watchface_index;
}

int watchface_app_get_num_faces(void)
{
    return num_watchfaces;

}

int watchface_app_get_face_info(int index, const lv_img_dsc_t **preview,  const char **name)
{
    if (index >= num_watchfaces) {
        return -EEXIST;
    }

    *name = watchfaces[index]->name;
    *preview = watchfaces[index]->get_preview_img();

    return 0;
}

SYS_INIT(enviromental_data_app_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);