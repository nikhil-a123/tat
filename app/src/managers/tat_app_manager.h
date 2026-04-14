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

typedef enum {
    TAT_APP_CATEGORY_ROOT = 0,
    TAT_APP_CATEGORY_TOOLS,
    TAT_APP_CATEGORY_SYSTEM,
    TAT_APP_CATEGORY_SENSORS,
    TAT_APP_CATEGORY_GAMES,
    TAT_APP_CATEGORY_OTHER,
    TAT_APP_CATEGORY_NUM_OF,
    TAT_APP_CATEGORY_INVALID
} tat_app_category_t;

typedef struct application_t {
    application_start_fn            start_func;
    application_stop_fn             stop_func;
    char                            *name;
    tat_app_category_t              category;
} application_t;

/** @brief
 *  @param app
*/
void tat_app_manager_add_application(application_t *app);

/** @brief Get number of registrated applications
*/
int tat_app_manager_get_num_apps(void);

/** @brief Get application by index
 *  @param index Index of the application (0 to num_apps-1)
 *  @return Pointer to application or NULL if index is invalid
 */
application_t *tat_app_manager_get_app(int index);

#endif /* TAT_APP_MANAGER_H_ */