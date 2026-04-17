#include <lvgl.h>

#include <zephyr/logging/log.h>

#include "enviromental_data/enviromental_data_app.h"

LV_FONT_DECLARE(roboto_extra_bold_72);

LOG_MODULE_REGISTER(env_data_simple_screen, CONFIG_TAT_APPLICATIONS_LOG_LEVEL);

static lv_obj_t *env_data_simple_screen = NULL;

/* Sharp LS027 display is 400x240px */

/* 6 columns with 66-px width */
static int32_t column_dsc[] =   {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), 
                                 LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1),
                                 LV_GRID_TEMPLATE_LAST};

/* 6 40-px tall rows */
static int32_t row_dsc[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), 
                            LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), 
                            LV_GRID_TEMPLATE_LAST};

void env_data_simple_screen_show(lv_obj_t *parent)
{
    // Create a child container under root, this is your app's root element
    env_data_simple_screen = lv_obj_create(parent);
    lv_obj_set_size(env_data_simple_screen, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_border_width(env_data_simple_screen, 0, LV_PART_MAIN);
    lv_obj_set_grid_dsc_array(env_data_simple_screen, column_dsc, row_dsc);

    // Create LVGL UI under env_data_simple_screen
    // Create top row of data
    lv_obj_t *temp_label = lv_label_create(env_data_simple_screen);
    lv_label_set_text(temp_label, "20.0°C");

    lv_obj_t *pressure_label = lv_label_create(env_data_simple_screen);
    lv_label_set_text(pressure_label, "101.3kPa");

    lv_obj_t *humidity_label = lv_label_create(env_data_simple_screen);
    lv_label_set_text(humidity_label, "50%");

    lv_obj_set_grid_cell(temp_label, LV_GRID_ALIGN_CENTER, 0, 2, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_grid_cell(pressure_label, LV_GRID_ALIGN_CENTER, 2, 2, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_grid_cell(humidity_label, LV_GRID_ALIGN_CENTER, 4, 2, LV_GRID_ALIGN_CENTER, 0, 1);

    lv_obj_t *co2_bg = lv_obj_create(env_data_simple_screen);
    // Set to white BG by default, with black test
    // This becomes inverted when the CO2 level is considered "bad"
    lv_obj_set_style_bg_color(co2_bg, lv_color_white(), LV_PART_MAIN);

    lv_obj_t *co2_label = lv_label_create(co2_bg);
    lv_obj_set_style_text_font(co2_label, &roboto_extra_bold_72, LV_PART_MAIN);
    lv_obj_set_style_text_color(co2_label, lv_color_black(), LV_PART_MAIN);
    lv_label_set_text(co2_label, "1234");
    lv_obj_center(co2_label);

    lv_obj_set_grid_cell(co2_bg, LV_GRID_ALIGN_STRETCH, 0, 6, LV_GRID_ALIGN_STRETCH, 1, 3);

    lv_obj_t *battery_label = lv_label_create(env_data_simple_screen);
    lv_label_set_text(battery_label, "100%");

    lv_obj_t *ppm_label = lv_label_create(env_data_simple_screen);
    lv_label_set_text(ppm_label, "CO2 ppm");

    lv_obj_set_grid_cell(battery_label, LV_GRID_ALIGN_CENTER, 0, 2, LV_GRID_ALIGN_CENTER, 4, 1);
    lv_obj_set_grid_cell(ppm_label, LV_GRID_ALIGN_CENTER, 4, 2, LV_GRID_ALIGN_CENTER, 4, 1);

    lv_obj_t *low_co2_conc_box = lv_obj_create(env_data_simple_screen);
    lv_obj_t *med_co2_conc_box = lv_obj_create(env_data_simple_screen);
    lv_obj_t *high_co2_conc_box = lv_obj_create(env_data_simple_screen);

    lv_obj_set_style_bg_color(low_co2_conc_box, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_style_bg_color(med_co2_conc_box, lv_color_white(), LV_PART_MAIN);
    lv_obj_set_style_bg_color(high_co2_conc_box, lv_color_white(), LV_PART_MAIN);

    lv_obj_set_grid_cell(low_co2_conc_box, LV_GRID_ALIGN_STRETCH, 0, 2, LV_GRID_ALIGN_STRETCH, 5, 1);
    lv_obj_set_grid_cell(med_co2_conc_box, LV_GRID_ALIGN_STRETCH, 2, 2, LV_GRID_ALIGN_STRETCH, 5, 1);
    lv_obj_set_grid_cell(high_co2_conc_box, LV_GRID_ALIGN_STRETCH, 4, 2, LV_GRID_ALIGN_STRETCH, 5, 1);

    LOG_INF("simple screen show!");
}

static void env_data_simple_screen_remove(void)
{
    if (!env_data_simple_screen) {
        return;
    }

    //lv_indev_remove_event_cb_with_user_data(lv_indev_active(), env_data_simple_screen_event_handler, NULL);
    //lv_display_remove_event_cb_with_user_data(lv_screen_active(), env_data_simple_screen_event_handler, NULL);
    lv_obj_del(env_data_simple_screen);
    env_data_simple_screen = NULL;
}

static enviromental_data_ui_api_t ui_api = {
    .show = env_data_simple_screen_show,
    .remove = env_data_simple_screen_remove,
    //.set_battery_percent = NULL,
    //.ui_invalidate_cached = NULL,
    //.get_preview_img = NULL,
    .name = "Simple"
};

static int env_data_simple_screen_init(void)
{
    enviromental_data_app_register_ui(&ui_api);
    LOG_INF("Registering simple screen!");
    return 0;
}

SYS_INIT(env_data_simple_screen_init, APPLICATION, ENVIROMENTAL_DATA_UI_INIT_PRIO);
