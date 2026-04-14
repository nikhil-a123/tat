#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/logging/log.h>

#include <lvgl.h>
#include <stdbool.h>

#include "managers/tat_app_manager.h"

LOG_MODULE_REGISTER(enviromental_data_app, LOG_LEVEL_INF);

static void enviromental_data_app_start(lv_obj_t *root, lv_group_t *group);
static void enviromental_data_app_stop(void);
static bool enviromental_data_app_back(void);
static void enviromental_data_app_ui_unavailable(void);
static void enviromental_data_app_ui_available(void);

static lv_obj_t *root_page = NULL;

static application_t app = {
    .name = "Enviromental Data",
    .start_func = enviromental_data_app_start,
    .stop_func = enviromental_data_app_stop,
    //.back_func = enviromental_data_app_back,                     // Optional
    //.ui_unavailable_func = enviromental_data_app_ui_unavailable, // Optional
    //.ui_available_func = enviromental_data_app_ui_available,     // Optional
    .category = TAT_APP_CATEGORY_TOOLS,
};

static void enviromental_data_app_start(lv_obj_t *root, lv_group_t *group)
{
    // Create a child container under root, this is your app's root element
    root_page = lv_obj_create(root);
    lv_obj_set_size(root_page, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_border_width(root_page, 0, LV_PART_MAIN);

    // Create your LVGL UI under root_page
    lv_obj_t *label = lv_label_create(root_page);
    lv_label_set_text(label, "Hello from Enviromental Data!");
    lv_obj_center(label);
}

static void enviromental_data_app_stop(void)
{
    // Delete the app's root element, this removes all child widgets too
    lv_obj_del(root_page);
    root_page = NULL;
}

static bool enviromental_data_app_back(void)
{
    // Optional: handle the back button.
    // Return true to consume the event (stay in app).
    // Return false to exit the app.
    return false;
}

static void enviromental_data_app_ui_unavailable(void)
{
    // Optional: called when the screen turns off.
    // Stop timers and pause UI updates here.
    return;
}

static void enviromental_data_app_ui_available(void)
{
    // Optional: called when the screen turns back on.
    // Resume UI updates here.
    return;
}

static int enviromental_data_app_add(void)
{
    tat_app_manager_add_application(&app);
    return 0;
}

SYS_INIT(enviromental_data_app_add, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);