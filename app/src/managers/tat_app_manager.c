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
#include <zephyr/zbus/zbus.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>

//#include "ui/zsw_ui.h"
//#include "ui/app_picker/app_picker_ui.h"
#include "tat_app_manager.h"
//#include "events/activity_event.h"

LOG_MODULE_REGISTER(app_manager, LOG_LEVEL_INF);

#define MAX_APPS        8
#define INVALID_APP_ID  0xFF

static void async_app_start(lv_timer_t *timer);
static void async_app_close(lv_timer_t *timer);

static application_t *apps[MAX_APPS];
static uint8_t num_apps;
static uint8_t current_app;

static lv_obj_t *root_obj;
static lv_group_t *group_obj;

// TODO: Add icons for app folders
/* static const tat_app_folder_info_t app_folders[TAT_APP_CATEGORY_NUM_OF] = {
    [TAT_APP_CATEGORY_ROOT] = {
        .name = "Root",
        .category = TAT_APP_CATEGORY_ROOT
    },
    [TAT_APP_CATEGORY_TOOLS] = {
        .name = "Tools",
        .category = TAT_APP_CATEGORY_TOOLS
    },
    [TAT_APP_CATEGORY_SYSTEM] = {
        .name = "System",
        .category = TAT_APP_CATEGORY_SYSTEM
    },
    [TAT_APP_CATEGORY_SENSORS] = {
        .name = "Sensors",
        .category = TAT_APP_CATEGORY_SENSORS
    },
    [TAT_APP_CATEGORY_GAMES] = {
        .name = "Games",
        .category = TAT_APP_CATEGORY_GAMES
    },
    [TAT_APP_CATEGORY_OTHER] = {
        .name = "Other",
        .category = TAT_APP_CATEGORY_OTHER
    },
}; */

/* static void async_app_start(lv_timer_t *timer)
{
    async_app_start_timer = NULL;
    LOG_DBG("Start %d", current_app);
    delete_root_object();

    application_t *app = apps[current_app];
    __ASSERT(screen_is_on, "Screen expected to be on when starting app.");
    app->current_state = ZSW_APP_STATE_UI_VISIBLE;

    app->start_func(root_obj, group_obj);
} */

/* static void async_app_close(lv_timer_t *timer)
{
    if (current_app < num_apps) {
        LOG_DBG("Stop %d", current_app);
        bool back_button_consumed = false;
        if (apps[current_app]->back_func) {
            back_button_consumed = apps[current_app]->back_func();
        }

        if (!back_button_consumed) {
            apps[current_app]->current_state = ZSW_APP_STATE_STOPPED;
            apps[current_app]->stop_func();
            current_app = INVALID_APP_ID;
            if (app_launch_only) {
                zsw_app_manager_delete();
                close_cb_func();
            } else {
                draw_app_and_folder_view();
            }
        }
    } else {
        // No app running, check if we are in a folder
        if (app_picker_root != NULL && app_picker_ui_is_folder_open()) {
            LOG_DBG("Close folder in picker");
            app_picker_ui_close_folder();
        } else {
            LOG_DBG("Exit application manager");
            zsw_app_manager_delete();
            close_cb_func();
        }
    }
    async_app_close_timer = NULL;
} */

void tat_app_manager_add_application(application_t *app)
{
    __ASSERT_NO_MSG(num_apps < MAX_APPS);

    apps[num_apps] = app;
    LOG_INF("Added application %d", num_apps);
    num_apps++;
}

int tat_app_manager_get_num_apps(void)
{
    return num_apps;
}

application_t *tat_app_manager_get_app(int index)
{
    if (index < 0 || index >= num_apps) {
        return NULL;
    }
    return apps[index];
}

static int app_manager_init(void)
{
    memset(apps, 0, sizeof(apps));
    num_apps = 0;
    current_app = INVALID_APP_ID;
    LOG_INF("Initializing application manager!");

    return 0;
}

SYS_INIT(app_manager_init, POST_KERNEL, CONFIG_APPLICATION_INIT_PRIORITY);