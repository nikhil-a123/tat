/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS 		1000

#define MAX_TEST_TIME_MS 	15000

#if !DT_HAS_COMPAT_STATUS_OKAY(bosch_bmi160)
#error "No bosch,bmi160 compatible node found in the device tree"
#endif


/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)

/* The devicetree node identifier for the "accel0" alias. */
#define ACCEL0_NODE DT_NODELABEL(accel0)

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

const struct device *const accel = DEVICE_DT_GET(ACCEL0_NODE);

static void print_gyro_data(const struct device *accel)
{
	struct sensor_value val[3];

	if (sensor_channel_get(accel, SENSOR_CHAN_GYRO_XYZ, val) < 0) {
		printk("Cannot read accelerometer gyro channels.\n");
		return;
	}

	printk("Gyro (rad/s): X=%f, Y=%f, Z=%f\n",
	       val[0].val1 + val[0].val2 / 1000000.0,
	       val[1].val1 + val[1].val2 / 1000000.0,
	       val[2].val1 + val[2].val2 / 1000000.0);
}

static void test_polling_mode(const struct device *accel)
{
	int32_t remaining_test_time = MAX_TEST_TIME_MS;

	do {
		if (sensor_sample_fetch(accel) < 0) {
			printk("Gyro sample update error.\n");
		}

		print_gyro_data(accel);

		//print_temp_data(bmi160);

		/* wait a while */
		k_msleep(SLEEP_TIME_MS);

		remaining_test_time -= SLEEP_TIME_MS;
	} while (remaining_test_time > 0);
}

int main(void)
{
	int ret;
	bool led_state = true;

	if (!gpio_is_ready_dt(&led)) {
		return 0;
	}

	if (!device_is_ready(accel)) {
        /* Not ready, do not use */
		printk("Device %s is not ready!\n", accel->name);
        return -ENODEV;
	}

	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}

	/* Test the accelerometer */
	test_polling_mode(accel);

	while (1) {
		ret = gpio_pin_toggle_dt(&led);
		if (ret < 0) {
			return 0;
		}

		led_state = !led_state;
		printk("LED state: %s\n", led_state ? "ON" : "OFF");
		k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}
