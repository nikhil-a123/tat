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

#include "sensors/tat_test_sensor.h"

//#include <zephyr/drivers/i2c.h>
//#include <zephyr/drivers/gpio.h>
//#include <zephyr/drivers/sensor.h>
//#include <zephyr/drivers/display.h>

/* LVGL includes */
//#include <lvgl.h>
//#include <lvgl_mem.h>
//#include <lvgl_zephyr.h>
//#include <lv_demos.h>

//#define DISPLAY_NODE DT_NODELABEL(sdl_dc)

//const struct device *display = DEVICE_DT_GET(DISPLAY_NODE);

LOG_MODULE_REGISTER(main);

/* zbus listener callbacks, executes synchronously from caller context
   so we should execute as fast as possible */
/* void slow_listener_callback(const struct zbus_channel *chan)
{
	const struct periodic_event *acc;
	if (&periodic_event_10s_chan == chan) {
		LOG_DBG("Hello from slow listener callback!");
	}	
}

void medium_listener_callback(const struct zbus_channel *chan)
{
	const struct acc_msg *acc;
	if (&periodic_event_1s_chan == chan) {
		LOG_DBG("Hello from medium listener callback!");
	}	
}

void fast_listener_callback(const struct zbus_channel *chan)
{
	const struct acc_msg *acc;
	if (&periodic_event_100ms_chan == chan) {
		LOG_DBG("Hello from fast listener callback!");
	}	
}

ZBUS_LISTENER_DEFINE(slow_listener, slow_listener_callback);
ZBUS_LISTENER_DEFINE(medium_listener, medium_listener_callback);
ZBUS_LISTENER_DEFINE(fast_listener, fast_listener_callback); */

int main(void)
{
	//int ret;

/* 	if (!device_is_ready(display)) {
		LOG_ERR("Device not ready, aborting test");
		return 0;
	} */

/* 	lvgl_lock();

	lv_demo_widgets(); */

	//lv_demo_render(0, 255);

/* 	lv_timer_handler();

	lvgl_unlock(); */

/* 	ret = display_blanking_off(display);
	if (ret < 0 && ret != -ENOSYS) {
		//LOG_ERR("Failed to turn blanking off (error %d)", ret);
		return 0;
	} */

	tat_test_sensor_init();

	while (1) {
/* 		uint32_t sleep_ms;

		lvgl_lock();
		sleep_ms = lv_timer_handler();
		lvgl_unlock(); */

		/* k_msleep(MIN(sleep_ms, INT32_MAX)); */
		//LOG_INF("Info");
		//LOG_WRN("Warning");
		//LOG_ERR("Error");
		//LOG_DBG("Debug");

		k_msleep(1000);
	}

	/* Test the accelerometer */
	//test_polling_mode(accel);

/* 	while (1) {
		ret = gpio_pin_toggle_dt(&led);
		if (ret < 0) {
			return 0;
		}

		led_state = !led_state;
		printk("LED state: %s\n", led_state ? "ON" : "OFF");
		k_msleep(SLEEP_TIME_MS);
	}
	return 0; */
}
