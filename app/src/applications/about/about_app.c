#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <stdio.h>
#include <zephyr/app_version.h>
#include <version.h>
#include <ncs_version.h>
#include "about_ui.h"
#include "managers/tat_app_manager.h"

static void about_app_start(lv_obj_t *root, lv_group_t *group);
static void about_app_stop(void);

LV_IMAGE_DECLARE(material_icons_info_20_black);

static application_t app = {
    .name = "About",
    .icon = &material_icons_info_20_black,
    .start_func = about_app_start,
    .stop_func = about_app_stop,
    .category = TAT_APP_CATEGORY_SYSTEM,
};

static void about_app_start(lv_obj_t *root, lv_group_t *group)
{
    char sdk_version[50];
    char version[50];

    snprintf(sdk_version, sizeof(sdk_version), "NCS: %s - Zephyr: %s", NCS_VERSION_STRING, KERNEL_VERSION_STRING);
    snprintf(version, sizeof(version), "v%s-%s", APP_VERSION_STRING, STRINGIFY(APP_BUILD_VERSION));
    about_ui_show(root, CONFIG_BOARD_TARGET, version, sdk_version, tat_app_manager_get_num_apps());
}

static void about_app_stop(void)
{
    about_ui_remove();
}

static int about_app_add(void)
{
    tat_app_manager_add_application(&app);

    return 0;
}

SYS_INIT(about_app_add, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);