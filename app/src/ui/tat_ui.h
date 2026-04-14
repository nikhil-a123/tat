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

#ifndef TAT_UI_H_
#define TAT_UI_H_

#include <lvgl.h>

static inline lv_color_t tat_color_black(void)
{
    return lv_color_make(0xff, 0xff, 0xff);
}

static inline lv_color_t tat_color_white(void)
{
    return lv_color_make(0x00, 0x00, 0x00);
}

static inline lv_color_t tat_color_bg(void)
{
    return tat_color_black();
}

#endif /* TAT_UI_H_ */