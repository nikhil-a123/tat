#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/sys/reboot.h>
#include <zephyr/logging/log.h>
#include <zephyr/settings/settings.h>

#include "tat_app_manager.h"
#include "settings_ui.h"
#include "tat_settings.h"

LOG_MODULE_REGISTER(settings_app, CONFIG_TAT_SETTINGS_APP_LOG_LEVEL);

LV_IMAGE_DECLARE(material_icons_settings_20_black);

// Add function declarations here
static void settings_app_start(lv_obj_t *root, lv_group_t *group);
static void settings_app_stop(void);
static bool settings_app_back(void);

static void on_close_settings(void);

static void on_sensor_period_changed(lv_setting_value_t value, bool final);
static void on_dark_mode_changed(lv_setting_value_t value, bool final);
//static void on_env_data_screen_index_changed(lv_setting_value_t value, bool final);

// Add struct declarations here
typedef struct setting_app {
    tat_settings_sensor_period_t    sensor_period;
    tat_settings_env_screen_t       env_screen;
    tat_settings_dark_mode_t        dark_mode;
} setting_app_t;

// Add static variables here

// Default settings values
static setting_app_t settings_app = {
    .sensor_period = 10,
    .env_screen = {
        .screen_index = 0
    },
    .dark_mode = true
};

static application_t app = {
    .name = "Settings",
    .icon = &material_icons_settings_20_black,
    .start_func = settings_app_start,
    .stop_func = settings_app_stop,
    .back_func = settings_app_back,
    .category = TAT_APP_CATEGORY_ROOT,
};

#define MIN_SENSOR_PERIOD 10
#define MAX_SENSOR_PERIOD 60

// Arrays of settings corresponding to each settings category
static lv_settings_item_t sensors_page_items[] = {
    {
        .type = LV_SETTINGS_TYPE_SLIDER,
        .change_callback = on_sensor_period_changed,
        .item = {
            .slider = {
                .name = "Reading Period",
                .inital_val = &settings_app.sensor_period,
                .min_val = MIN_SENSOR_PERIOD,
                .max_val = MAX_SENSOR_PERIOD
            }
        }
    }
};

static lv_settings_item_t general_page_items[] = {
    {
        .type = LV_SETTINGS_TYPE_SWITCH,
        .change_callback = on_dark_mode_changed,
        .item = {
            .sw = {
                .name = "Dark Mode",
                .inital_val = &settings_app.dark_mode
            }
        }
    }
};

static lv_settings_page_t settings_menu[] = {
    {
        .name = "Sensors",
        .icon = &material_icons_settings_20_black,
        .num_items = ARRAY_SIZE(sensors_page_items),
        .items = sensors_page_items
    },
    {
        .name = "General",
        .icon = &material_icons_settings_20_black,
        .num_items = ARRAY_SIZE(general_page_items),
        .items = general_page_items
    }
};

// Callbacks and other static functions
static void on_sensor_period_changed(lv_setting_value_t value, bool final)
{
    settings_app.sensor_period = value.item.slider;
    if (final) {
        settings_save_one(TAT_SETTINGS_SENSOR_PERIOD, &settings_app.sensor_period, sizeof(settings_app.sensor_period));
    }
}

static void on_dark_mode_changed(lv_setting_value_t value, bool final)
{
    settings_app.dark_mode = value.item.sw;
    settings_save_one(TAT_SETTINGS_DARK_MODE, &settings_app.dark_mode, sizeof(settings_app.dark_mode));
}

/* static void on_env_data_screen_index_changed(lv_setting_value_t value, bool final)
{

} */

// Main application functions here
static void settings_app_start(lv_obj_t *root, lv_group_t *group)
{
    settings_load_subtree(TAT_SETTINGS_PATH); // Update any values that may have changed outside of the settings app.
    lv_settings_create(root, settings_menu, ARRAY_SIZE(settings_menu), group, on_close_settings);
}

static void settings_app_stop(void)
{
    settings_ui_remove();
}

static bool settings_app_back(void)
{
    return settings_ui_back();
}

static void on_close_settings(void)
{
    tat_app_manager_app_close_request(&app);
}

static int settings_load_cb(const char *name, size_t len,
                            settings_read_cb read_cb, void *cb_arg)
{
    const char *next;
    int rc;

    if (settings_name_steq(name, TAT_SETTINGS_KEY_SENSOR_PERIOD, &next) && !next) {
        if (len != sizeof(settings_app.sensor_period)) {
            return -EINVAL;
        }

        tat_settings_sensor_period_t period;
        rc = read_cb(cb_arg, &period, sizeof(period));
        if (rc >= 0) {
            if (period >= MIN_SENSOR_PERIOD && period <= MAX_SENSOR_PERIOD) {
                settings_app.sensor_period = period;
            }
            return 0;
        }
        return rc;
    }

    if (settings_name_steq(name, TAT_SETTINGS_KEY_DARK_MODE, &next) && !next) {
        if (len != sizeof(settings_app.dark_mode)) {
            return -EINVAL;
        }

        rc = read_cb(cb_arg, &settings_app.dark_mode, sizeof(settings_app.dark_mode));
        if (rc >= 0) {
            return 0;
        }
        return rc;
    }

    return 0;
}

static int settings_app_add(void)
{
    settings_subsys_init();
    tat_app_manager_add_application(&app);

    return 0;
}

SETTINGS_STATIC_HANDLER_DEFINE(settings_app_handler, TAT_SETTINGS_PATH, NULL,
                               settings_load_cb, NULL, NULL);

SYS_INIT(settings_app_add, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);