#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/logging/log.h>

#include <lvgl.h>

#include "tat_app_manager.h"

LOG_MODULE_REGISTER(hello_world_app, CONFIG_TAT_APPLICATIONS_LOG_LEVEL);
LV_IMAGE_DECLARE(material_icons_waving_hand_32_black);

static lv_obj_t *hello_world_screen = NULL;

static void hello_world_app_start(lv_obj_t *root, lv_group_t *group);
static void hello_world_app_stop(void);

static application_t app = {
    .name = "Hello World",
    .icon = &material_icons_waving_hand_32_black,
    .start_func = hello_world_app_start,
    .stop_func = hello_world_app_stop,
    .category = TAT_APP_CATEGORY_SYSTEM
};

void hello_world_app_start(lv_obj_t *parent, lv_group_t *group)
{
    // Create a child container under root, this is your app's root element
    hello_world_screen = lv_obj_create(parent);
    lv_obj_set_size(hello_world_screen, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_border_width(hello_world_screen, 0, LV_PART_MAIN);

    // Create LVGL UI under env_data_simple_screen
    // Create top row of data
    lv_obj_t *label = lv_label_create(hello_world_screen);
    lv_label_set_text(label, "Hello world!");
}

static void hello_world_app_stop(void)
{
    lv_obj_del(hello_world_screen);
    hello_world_screen = NULL;
}

static int hello_world_app_add(void)
{
    tat_app_manager_add_application(&app);
    LOG_INF("Registering hello world screen!");
    return 0;
}

SYS_INIT(hello_world_app_add, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
