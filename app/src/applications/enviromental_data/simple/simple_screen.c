#include <lvgl.h>

#include "enviromental_data/enviromental_data_app.h"
#include "simple_screen_ui.h"

void env_data_simple_screen_show(lv_obj_t *parent)
{
    simple_screen_ui_show(parent);
    // Set the variables on screen
}

static void env_data_simple_screen_remove(void)
{
    simple_screen_ui_remove();
}

static void env_data_simple_screen_set_co2_conc(uint32_t co2_ppm)
{
    simple_screen_ui_set_co2(co2_ppm);
}

static void env_data_simple_screen_set_temperature(float temperature)
{
    simple_screen_ui_set_temp(temperature);
}

static void env_data_simple_screen_set_humidity(float humidity)
{
    simple_screen_ui_set_humid(humidity);
}

static enviromental_data_ui_api_t ui_api = {
    .show = env_data_simple_screen_show,
    .remove = env_data_simple_screen_remove,
    .set_co2_conc = env_data_simple_screen_set_co2_conc,
    .set_temperature = env_data_simple_screen_set_temperature,
    .set_humidity = env_data_simple_screen_set_humidity,
    //.set_battery_percent = NULL,
    //.ui_invalidate_cached = NULL,
    //.get_preview_img = NULL,
    .name = "Simple"
};

static int env_data_simple_screen_init(void)
{
    enviromental_data_app_register_ui(&ui_api);
    return 0;
}

SYS_INIT(env_data_simple_screen_init, APPLICATION, ENVIROMENTAL_DATA_UI_INIT_PRIO);
