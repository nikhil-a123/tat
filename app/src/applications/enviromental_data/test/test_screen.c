#include <lvgl.h>

#include <zephyr/logging/log.h>

#include "enviromental_data/enviromental_data_app.h"

LOG_MODULE_REGISTER(env_data_test_screen, CONFIG_TAT_APPLICATIONS_LOG_LEVEL);

static lv_obj_t *env_data_test_screen = NULL;

/* Sharp LS027 display is 400x240px */

void env_data_test_screen_show(lv_obj_t *parent)
{
    // Create a child container under root, this is your app's root element
    env_data_test_screen = lv_obj_create(parent);
    lv_obj_set_size(env_data_test_screen, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_border_width(env_data_test_screen, 0, LV_PART_MAIN);
    //lv_obj_set_grid_dsc_array(env_data_test_screen, column_dsc, row_dsc);

    // Create LVGL UI under env_data_simple_screen

    // Create top row of data
    lv_obj_t *temp_button = lv_button_create(env_data_test_screen);
    lv_obj_t *temp_label = lv_label_create(temp_button);
    lv_label_set_text(temp_label, "Hello from test screen!");
    lv_obj_center(temp_label);

    LOG_INF("test screen show!");
}

static void env_data_test_screen_remove(void)
{
    if (!env_data_test_screen) {
        return;
    }

    lv_obj_del(env_data_test_screen);
    env_data_test_screen = NULL;
}

static enviromental_data_ui_api_t ui_api = {
    .show = env_data_test_screen_show,
    .remove = env_data_test_screen_remove,
    //.set_battery_percent = NULL,
    //.ui_invalidate_cached = NULL,
    //.get_preview_img = NULL,
    .name = "Test"
};

static int env_data_test_screen_init(void)
{
    enviromental_data_app_register_ui(&ui_api);
    LOG_INF("Registering test screen!");
    return 0;
}

SYS_INIT(env_data_test_screen_init, APPLICATION, ENVIROMENTAL_DATA_UI_INIT_PRIO);
