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

#ifndef TAT_UI_CONTROLLER_H_
#define TAT_UI_CONTROLLER_H_

typedef enum {
    TAT_UI_STATE_INIT = 0,
    TAT_UI_STATE_ENVIROMENTAL_DATA,
    TAT_UI_STATE_APP_MANAGER,
} tat_ui_state_t;

int tat_ui_controller_init();

void tat_ui_controller_launch_app(const char *app_name);

tat_ui_state_t tat_ui_controller_get_state(void);

const char *tat_ui_controller_get_running_app_name(void);

#endif /* TAT_UI_CONTROLLER_H_ */