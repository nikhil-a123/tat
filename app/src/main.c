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

/* static lv_obj_t *main_screen;
static lv_obj_t *button;
static lv_obj_t *my_label; */

int main(void)
{
	int ret;

	if (!device_is_ready(display)) {
		LOG_ERR("No display found!");
		return 0;
	}

	tat_test_sensor_init();

	/* Setup LVGL stuff */
/* 	main_screen = lv_obj_create(NULL);
	lv_obj_set_style_bg_color(main_screen, lv_color_hex(0xffffff), LV_PART_MAIN); */

/* 	button = lv_button_create(main_screen);
	lv_obj_set_size(button, lv_pct(25), LV_SIZE_CONTENT);
	lv_obj_align(button, LV_ALIGN_RIGHT_MID, -20, 0); */

/* 	my_label = lv_label_create(button);
	lv_label_set_text_fmt(my_label, "Click me!");
	lv_obj_set_style_text_color(my_label, lv_color_hex(0xffffff), 0); */

/* 	my_label = lv_label_create(main_screen);
	lv_label_set_text(my_label, "Click me!");
	lv_obj_set_style_text_color(my_label, lv_color_hex(0x00), 0); */

    /*Change the active screen's background color*/
/* 	main_screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(main_screen, lv_color_hex(0xffffff), LV_PART_MAIN); */

    /*Create a white label, set its text and align it to the center*/
/*     my_label = lv_label_create(main_screen);
    lv_label_set_text(my_label, "Hello world");
    lv_obj_set_style_text_color(main_screen, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_align(my_label, LV_ALIGN_CENTER, 0, 0); */

/* 	lv_screen_load(main_screen); */

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
