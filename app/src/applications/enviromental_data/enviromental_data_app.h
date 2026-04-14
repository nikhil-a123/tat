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

#pragma once

#include <lvgl.h>
#include <zephyr/init.h>

// UI need to be initialized after enviromental_data_app
#define ENVIROMENTAL_DATA_UI_INIT_PRIO 99

/* typedef enum enviromental_data_app_evt_type_t {
    ENVIROMENTAL_DATA_APP_EVENT_OPEN_APP,
    ENVIROMENTAL_DATA_APP_EVENT_SET_BRIGHTNESS,
    ENVIROMENTAL_DATA_APP_EVENT_RESTART,
    ENVIROMENTAL_DATA_APP_EVENT_SHUTDOWN,
    ENVIROMENTAL_DATA_APP_EVENT_GESTURE
} enviromental_data_app_evt_type_t; */

/* typedef enum enviromental_data_app_evt_open_app_t {
    ENVIROMENTAL_DATA_APP_EVT_CLICK_BATT,
    ENVIROMENTAL_DATA_APP_EVT_CLICK_STEP,
    ENVIROMENTAL_DATA_APP_EVT_CLICK_WEATHER,
    ENVIROMENTAL_DATA_APP_EVT_CLICK_MUSIC,
    ENVIROMENTAL_DATA_APP_EVT_CLICK_SETTINGS,
    ENVIROMENTAL_DATA_APP_EVT_CLICK_FLASHLIGHT
} enviromental_data_app_evt_open_app_t; */

/* typedef struct enviromental_data_app_evt_t {
    enviromental_data_app_evt_type_t type;
    union enviromental_data_app_evt_data_t {
        enviromental_data_app_evt_open_app_t app;
        struct {
            uint16_t brightness;
            bool store_brightness;
        };
        lv_dir_t gesture_direction;
    } data;
} enviromental_data_app_evt_t; */

/* typedef void(*enviromental_data_app_evt_listener)(enviromental_data_app_evt_t); */

typedef struct enviromental_data_ui_api_t {
    //void (*show)(lv_obj_t *root_screen, enviromental_data_app_evt_listener, zsw_settings_enviromental_data_t *settings);
    void (*show)(lv_obj_t *root_screen);
    void (*remove)(void);
    //void (*set_battery_percent)(int32_t percent, int32_t battery);
    //void (*set_co2_conc)(int32_t conc);
    //void (*set_charging)(bool is_charging);
    //void (*ui_invalidate_cached)(void);
    const char *name;
} enviromental_data_ui_api_t;

void enviromental_data_app_start(lv_obj_t *root_screen, lv_group_t *group, enviromental_data_app_evt_listener evt_cb);
void enviromental_data_app_stop(void);
//void enviromental_data_change(int index);
int enviromental_data_app_get_current_face(void);
void enviromental_data_app_register_ui(enviromental_data_ui_api_t *ui);

int enviromental_data_app_get_num_faces(void);
int enviromental_data_app_get_face_info(int index, const char **name);
