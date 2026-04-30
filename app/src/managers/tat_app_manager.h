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

#ifndef TAT_APP_MANAGER_H_
#define TAT_APP_MANAGER_H_

#include <lvgl.h>

typedef void(*application_start_fn)(lv_obj_t *root, lv_group_t *group);
typedef void(*application_stop_fn)(void);

typedef void(*on_app_manager_cb_fn)(void);

typedef enum {
    TAT_APP_CATEGORY_ROOT = 0,
    TAT_APP_CATEGORY_SYSTEM,
    TAT_APP_CATEGORY_SENSORS,
    TAT_APP_CATEGORY_OTHER,
    TAT_APP_CATEGORY_NUM_OF,
    TAT_APP_CATEGORY_INVALID
} tat_app_category_t;

typedef struct {
    const char *name;
    tat_app_category_t category;
    //const void *icon;
} tat_app_folder_info_t;

typedef enum {
    TAT_APP_STATE_STOPPED,      // App is not running
    TAT_APP_STATE_UI_VISIBLE,   // App UI is visible and safe to use
    //TAT_APP_STATE_UI_HIDDEN     // App is running but UI is not safe to call
} tat_app_state_t;

typedef struct application_t {
    application_start_fn            start_func;
    application_stop_fn             stop_func;
    char                            *name;
    const void                      *icon;
    bool                            hidden;
    tat_app_category_t              category;
    uint8_t                         private_list_index;
    tat_app_state_t                 current_state;
} application_t;

int tat_app_manager_show(on_app_manager_cb_fn close_cb, lv_obj_t *root, lv_group_t *group, char *app_name);
void tat_app_manager_delete(void);
void tat_app_manager_add_application(application_t *app);
void tat_app_manager_exit_app(void);
void tat_app_manager_app_close_request(application_t *app);
int tat_app_manager_get_num_apps(void);
application_t *tat_app_manager_get_app(int index);
tat_app_state_t tat_app_manager_get_app_state(application_t *app);

#endif /* TAT_APP_MANAGER_H_ */