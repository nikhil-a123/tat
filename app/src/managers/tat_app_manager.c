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
#include "ui/app_menu/app_menu.h"
#include "tat_app_manager.h"
//#include "events/activity_event.h"

LOG_MODULE_REGISTER(app_manager, CONFIG_TAT_MANAGERS_LOG_LEVEL);

#define MAX_APPS        32
#define INVALID_APP_ID  0xFF

//static void draw_app_and_folder_view(void);
static void on_app_selected(application_t *app);
static void async_app_start(lv_timer_t *timer);
static void async_app_close(lv_timer_t *timer);
static void draw_app_menu(void);

static application_t *apps[MAX_APPS];
static uint8_t num_apps;
static uint8_t num_visible_apps;
static uint8_t current_app;

static lv_obj_t *root_obj;
static lv_group_t *group_obj;
static on_app_manager_cb_fn close_cb_func;
static lv_obj_t *app_menu_root;
static bool app_launch_only;
static lv_timer_t *async_app_start_timer;
static lv_timer_t *async_app_close_timer;

// TODO: Add icons for app folders
static const tat_app_folder_info_t app_folders[TAT_APP_CATEGORY_NUM_OF] = {
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
};

static void delete_root_object(void)
{
    if (app_menu_root != NULL) {
        app_menu_delete();
        app_menu_root = NULL;
    }
}

static void on_app_selected(application_t *app)
{
    if (app == NULL) {
        return;
    }

    for (int i = 0; i < num_apps; i++) {
        if (apps[i] == app) {
            current_app = i;

            if (async_app_start_timer == NULL) {
                async_app_start_timer = lv_timer_create(async_app_start, 50, NULL);
                lv_timer_set_repeat_count(async_app_start_timer, 1);
            }
            return;
        }
    }

    LOG_WRN("Selected app not found in registry");
}

static void async_app_start(lv_timer_t *timer)
{
    async_app_start_timer = NULL;
    LOG_DBG("Start %d", current_app);
    delete_root_object();

    application_t *app = apps[current_app];
    app->current_state = TAT_APP_STATE_UI_VISIBLE;

    app->start_func(root_obj, group_obj);
}

static void async_app_close(lv_timer_t *timer)
{
    if (current_app < num_apps) {
        LOG_DBG("Stop %d", current_app);

        apps[current_app]->current_state = TAT_APP_STATE_STOPPED;
        apps[current_app]->stop_func();
        current_app = INVALID_APP_ID;
        if (app_launch_only) {
            // if we skipped the app menu, delete this
            tat_app_manager_delete();
        } else {
            // go back to app menu
            draw_app_menu();
        }
    }
    async_app_close_timer = NULL;
}

static void draw_app_menu(void)
{
    /* Use new circular app picker UI */
    app_menu_root = app_menu_create(root_obj, group_obj, on_app_selected);

    LOG_DBG("Created app menu UI");
}

int tat_app_manager_show(on_app_manager_cb_fn close_cb, lv_obj_t *root, lv_group_t *group, char *app_name)
{
    int err = 0;
    bool app_found;
    close_cb_func = close_cb;
    root_obj = root;
    group_obj = group;
    app_launch_only = false;

    if (app_name == NULL) {
        draw_app_menu();
    } else {
        app_found = false;
        for (int i = 0; i < num_apps; i++) {
            if (strcmp(apps[i]->name, app_name) == 0) {
                app_found = true;
                app_launch_only = true;
                current_app = i;
                if (async_app_start_timer == NULL) {
                    async_app_start_timer = lv_timer_create(async_app_start, 1,  NULL);
                    lv_timer_set_repeat_count(async_app_start_timer, 1);
                }
                break;
            }
        }
    }

    if (app_name != NULL && !app_found) {
        LOG_INF("Couldn't find app!");
        err = -ENOENT;
    }

    return err;
}

void tat_app_manager_delete(void)
{
    if (current_app < num_apps) {
        LOG_DBG("Stop force %d", current_app);
        apps[current_app]->current_state = TAT_APP_STATE_STOPPED;
        apps[current_app]->stop_func();
    }
    delete_root_object();
}

void tat_app_manager_add_application(application_t *app)
{
    __ASSERT_NO_MSG(num_apps < MAX_APPS);

    app->current_state = TAT_APP_STATE_STOPPED;
    apps[num_apps] = app;
    LOG_INF("Added application %d", num_apps);
    num_apps++;
    if (!app->hidden) {
        app->private_list_index = num_visible_apps;
        num_visible_apps++;
    }
}

void tat_app_manager_exit_app(void)
{
    if (async_app_close_timer != NULL) {
        return;
    }
    async_app_close_timer = lv_timer_create(async_app_close, 500,  NULL);
    lv_timer_set_repeat_count(async_app_close_timer, 1);
}

void tat_app_manager_app_close_request(application_t *app)
{
    LOG_DBG("tat_app_manager_app_close_request");
    tat_app_manager_exit_app();
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

tat_app_state_t tat_app_manager_get_app_state(application_t *app)
{
    __ASSERT_NO_MSG(app != NULL);
    return app->current_state;
}

static int app_manager_init(void)
{
    memset(apps, 0, sizeof(apps));
    num_apps = 0;
    current_app = INVALID_APP_ID;
    async_app_start_timer = NULL;
    LOG_INF("Initializing application manager!");

    return 0;
}

SYS_INIT(app_manager_init, POST_KERNEL, CONFIG_APPLICATION_INIT_PRIORITY);