#
# Copyright (c) 2025 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(tat)

set(LVGL_DIR ${ZEPHYR_LVGL_MODULE_DIR})

target_sources(app PRIVATE 
    src/main.c
    ${LVGL_DIR}/demos/lv_demos.c
    ${LVGL_DIR}/demos/widgets/assets/img_clothes.c
    ${LVGL_DIR}/demos/widgets/assets/img_demo_widgets_avatar.c
    ${LVGL_DIR}/demos/widgets/assets/img_demo_widgets_needle.c
    ${LVGL_DIR}/demos/widgets/assets/img_lvgl_logo.c
    ${LVGL_DIR}/demos/widgets/lv_demo_widgets.c
    #${LVGL_DIR}/demos/widgets/lv_demo_widgets_analytics.c
    #${LVGL_DIR}/demos/widgets/lv_demo_widgets_components.c
    #${LVGL_DIR}/demos/widgets/lv_demo_widgets_profile.c
    #${LVGL_DIR}/demos/widgets/lv_demo_widgets_shop.c
)

target_include_directories(app PRIVATE
    ${LVGL_DIR}/demos/
)