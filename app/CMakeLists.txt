#
# Copyright (c) 2025 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(app)

add_subdirectory(src/applications)
add_subdirectory(src/drivers)
add_subdirectory(src/events)
add_subdirectory(src/managers)
add_subdirectory(src/sensors)
add_subdirectory(src/ui)

include_directories(src)
include_directories(src/ui)
include_directories(src/applications)
include_directories(src/drivers)
include_directories(src/managers)
include_directories(src/events)
include_directories(src/sensors)

target_sources(app PRIVATE 
    src/main.c
    src/ui/app_menu/app_menu.c
    src/ui/app_menu/app_menu_ui.c
)