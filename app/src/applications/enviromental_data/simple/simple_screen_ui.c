#include <zephyr/logging/log.h>
#include <stdio.h>
#include "simple_screen_ui.h"

LV_FONT_DECLARE(roboto_medium_12);
LV_FONT_DECLARE(roboto_extra_bold_64);

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

lv_obj_t *temp_label;
lv_obj_t *pressure_label;
lv_obj_t *humidity_label;

lv_obj_t *co2_bg;
lv_obj_t *co2_label;

lv_obj_t *battery_label;
lv_obj_t *ppm_label;

lv_obj_t *low_co2_conc_box;
lv_obj_t *med_co2_conc_box;
lv_obj_t *high_co2_conc_box;

void simple_screen_ui_show(lv_obj_t *parent)
{
    // Create a child container under root, this is your app's root element
    env_data_simple_screen = lv_obj_create(parent);
    lv_obj_set_size(env_data_simple_screen, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_border_width(env_data_simple_screen, 0, LV_PART_MAIN);
    lv_obj_set_grid_dsc_array(env_data_simple_screen, column_dsc, row_dsc);
    // Set the default font for the child widgets
    lv_obj_set_style_text_font(env_data_simple_screen, &roboto_medium_12, LV_PART_MAIN);

    // Create LVGL UI under env_data_simple_screen
    // Create top row of data
    temp_label = lv_label_create(env_data_simple_screen);
    lv_label_set_text(temp_label, "20.0°C");

    pressure_label = lv_label_create(env_data_simple_screen);
    lv_label_set_text(pressure_label, "101.3kPa");

    humidity_label = lv_label_create(env_data_simple_screen);
    lv_label_set_text(humidity_label, "50%");

    lv_obj_set_grid_cell(temp_label, LV_GRID_ALIGN_CENTER, 0, 2, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_grid_cell(pressure_label, LV_GRID_ALIGN_CENTER, 2, 2, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_grid_cell(humidity_label, LV_GRID_ALIGN_CENTER, 4, 2, LV_GRID_ALIGN_CENTER, 0, 1);

    co2_bg = lv_obj_create(env_data_simple_screen);
    // Set to white BG by default, with black test
    // This becomes inverted when the CO2 level is considered "bad"
    lv_obj_set_style_bg_color(co2_bg, lv_color_white(), LV_PART_MAIN);

    co2_label = lv_label_create(co2_bg);
    lv_obj_set_style_text_font(co2_label, &roboto_extra_bold_64, LV_PART_MAIN);
    lv_obj_set_style_text_color(co2_label, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_style_text_align(co2_label , LV_TEXT_ALIGN_CENTER, 0);
    lv_label_set_text(co2_label, "1234");
    lv_obj_center(co2_label);

    lv_obj_set_grid_cell(co2_bg, LV_GRID_ALIGN_STRETCH, 0, 6, LV_GRID_ALIGN_STRETCH, 1, 3);

    battery_label = lv_label_create(env_data_simple_screen);
    lv_label_set_text(battery_label, "100%");

    ppm_label = lv_label_create(env_data_simple_screen);
    lv_label_set_text(ppm_label, "CO2 ppm");

    lv_obj_set_grid_cell(battery_label, LV_GRID_ALIGN_CENTER, 0, 2, LV_GRID_ALIGN_CENTER, 4, 1);
    lv_obj_set_grid_cell(ppm_label, LV_GRID_ALIGN_CENTER, 4, 2, LV_GRID_ALIGN_CENTER, 4, 1);

    low_co2_conc_box = lv_obj_create(env_data_simple_screen);
    med_co2_conc_box = lv_obj_create(env_data_simple_screen);
    high_co2_conc_box = lv_obj_create(env_data_simple_screen);

    lv_obj_set_style_bg_color(low_co2_conc_box, lv_color_white(), LV_PART_MAIN);
    lv_obj_set_style_bg_color(med_co2_conc_box, lv_color_white(), LV_PART_MAIN);
    lv_obj_set_style_bg_color(high_co2_conc_box, lv_color_white(), LV_PART_MAIN);

    lv_obj_set_grid_cell(low_co2_conc_box, LV_GRID_ALIGN_STRETCH, 0, 2, LV_GRID_ALIGN_STRETCH, 5, 1);
    lv_obj_set_grid_cell(med_co2_conc_box, LV_GRID_ALIGN_STRETCH, 2, 2, LV_GRID_ALIGN_STRETCH, 5, 1);
    lv_obj_set_grid_cell(high_co2_conc_box, LV_GRID_ALIGN_STRETCH, 4, 2, LV_GRID_ALIGN_STRETCH, 5, 1);

    LOG_INF("simple screen show!");
}

void simple_screen_ui_remove(void)
{
    if (!env_data_simple_screen) {
        return;
    }

    lv_obj_del(env_data_simple_screen);
    env_data_simple_screen = NULL;
}

void simple_screen_ui_set_co2(uint32_t co2)
{
    // First set the label text
    char co2_text[10];
    snprintf(co2_text, sizeof(co2_text), "%d", co2);
    lv_label_set_text(co2_label, co2_text);

    // If the CO2 concentration is >2000ppm change the background color
    if (co2 > 2000) {
        lv_obj_set_style_bg_color(co2_bg, lv_color_black(), LV_PART_MAIN);
        lv_obj_set_style_text_color(co2_label, lv_color_white(), LV_PART_MAIN);
    } else {
        lv_obj_set_style_bg_color(co2_bg, lv_color_white(), LV_PART_MAIN);
        lv_obj_set_style_text_color(co2_label, lv_color_black(), LV_PART_MAIN);
    }

    // Set the color of the CO2 indicator box depending on the range
    lv_obj_set_style_bg_color(low_co2_conc_box, lv_color_white(), LV_PART_MAIN);
    lv_obj_set_style_bg_color(med_co2_conc_box, lv_color_white(), LV_PART_MAIN);
    lv_obj_set_style_bg_color(high_co2_conc_box, lv_color_white(), LV_PART_MAIN);

    if (co2 < 1000) {
        lv_obj_set_style_bg_color(low_co2_conc_box, lv_color_black(), LV_PART_MAIN);
    } else if (co2 < 2000) {
        lv_obj_set_style_bg_color(med_co2_conc_box, lv_color_black(), LV_PART_MAIN);
    } else {
        lv_obj_set_style_bg_color(high_co2_conc_box, lv_color_black(), LV_PART_MAIN);
    }
}

void simple_screen_ui_set_temp(float temp)
{
    char temp_text[10];
    snprintf(temp_text, sizeof(temp_text), "%.1f°C", (double)temp);
    lv_label_set_text(temp_label, temp_text);
}

void simple_screen_ui_set_humid(float humid)
{
    char humid_text[10];
    snprintf(humid_text, sizeof(humid_text), "%.1f%%", (double)humid);
    lv_label_set_text(humidity_label, humid_text);
}