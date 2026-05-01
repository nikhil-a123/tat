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

#include "drivers/tat_display_control.h"
#include "sensors/tat_co2_sensor.h"
#include "ui/tat_ui_controller.h"

LOG_MODULE_REGISTER(main);

static void run_init_work(struct k_work *item);

K_WORK_DEFINE(init_work, run_init_work);

// The init code requires a bit of stack.
// So in order to not increase CONFIG_MAIN_STACK_SIZE and loose
// this RAM forever, instead re-use the system workqueue for init
// it has the required amount of stack.
static void run_init_work(struct k_work *item)
{
	int ret;

	tat_display_control_init();
	tat_display_control_sleep_ctrl(true);

	//tat_test_sensor_init();
	tat_co2_sensor_init();

	tat_ui_controller_init();
	LOG_INF("tat application started!");
}

int main(void)
{
	k_work_submit(&init_work);
	
	return 0;
}
