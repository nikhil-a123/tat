/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>
#include <zephyr/shell/shell.h>

#include <zephyr/zbus/zbus.h>

#include "events/periodic_event.h"

#include "sensors/tat_co2_sensor.h"

#include "ui/tat_ui_controller.h"

#include <zephyr/drivers/i2c.h>
//#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/display.h>

/* LVGL includes */
#include <lvgl.h>
#include <lvgl_mem.h>
#include <lvgl_zephyr.h>

#define DISPLAY_NODE DT_CHOSEN(zephyr_display)

const struct device *display = DEVICE_DT_GET_OR_NULL(DISPLAY_NODE);

LOG_MODULE_REGISTER(main);

int main(void)
{
	int ret;

	if (!device_is_ready(display)) {
		LOG_ERR("No display found!");
		return 0;
	}

	//tat_test_sensor_init();
	tat_co2_sensor_init();

	lv_timer_handler();
	ret = display_blanking_off(display);
	if (ret < 0 && ret != -ENOSYS) {
		LOG_ERR("Failed to turn blanking off (error %d)", ret);
		return 0;
	}

	tat_ui_controller_init();
	LOG_INF("tat application started!");

	uint32_t sleep_ms;
	while (1) {
		sleep_ms = lv_timer_handler();
		k_msleep(MIN(sleep_ms, INT32_MAX));
	}
}
