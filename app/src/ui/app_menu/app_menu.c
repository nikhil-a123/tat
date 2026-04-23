#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include "app_menu.h"
#include "app_menu_ui.h"
#include "tat_app_manager.h"

LOG_MODULE_REGISTER(app_menu, LOG_LEVEL_DBG);

/* Maximum number of menu items (apps + folders) */
#define MAX_MENU_ITEMS 32
// Number of buttons in the list
#define NUM_SLOTS 6

typedef struct {
    application_t *app;
} menu_item_t;

static lv_obj_t *menu_root;

static app_menu_on_app_selected_cb app_selected_cb;

static lv_obj_t *app_list;
static lv_obj_t *list_buttons[NUM_SLOTS];
static lv_obj_t *list_icons[NUM_SLOTS];
static lv_obj_t *list_labels[NUM_SLOTS];

static menu_item_t menu_items[MAX_MENU_ITEMS];
static int num_menu_items;

static menu_item_t *button_items[NUM_SLOTS];

static void cache_object_references(void)
{
    if (menu_root == NULL) {
        LOG_ERR("menu_root is NULL");
        return;
    }

    // Get reference to the app list object
    app_list = lv_obj_find_by_name(menu_root, "app_list");
    if (app_list == NULL) {
        LOG_ERR("app_list not found!");
        return;
    }

    // Get references to all the buttons within the list
    for (int i = 0; i < NUM_SLOTS; i++) {
        list_buttons[i] = lv_obj_get_child(app_list, i);

        if (list_buttons[i] != NULL) {
            // Get reference to the button's label
            list_icons[i] = lv_obj_get_child(list_buttons[i], 0);
            list_labels[i] = lv_obj_get_child(list_buttons[i], 1);
            // Save the index in the button object
            lv_obj_set_user_data(list_buttons[i], (void *)(intptr_t)i);
        }
    }
}

static void build_menu_items(void)
{
    num_menu_items = 0;
    int num_apps = tat_app_manager_get_num_apps();

    /* Add all apps, ignoring folders for now */
    for (int i = 0; i < num_apps && num_menu_items < MAX_MENU_ITEMS; i++) {
        application_t *app = tat_app_manager_get_app(i);
        if (app && !app->hidden) {
            menu_items[num_menu_items].app = app;
            num_menu_items++;
        }
    }
}

static void populate_slot(int button_index, menu_item_t *item)
{
    if (button_index < 0 || button_index >= NUM_SLOTS) {
        return;
    }

    button_items[button_index] = item;

    if (list_buttons[button_index] == NULL) {
        return;
    }

    if (item == NULL) {
        lv_obj_add_flag(list_buttons[button_index], LV_OBJ_FLAG_HIDDEN);
        return;
    }

    // There is an item to populate
    lv_obj_remove_flag(list_buttons[button_index], LV_OBJ_FLAG_HIDDEN);

    application_t *app = item->app;
    if (list_icons[button_index] && app->icon) {
        lv_image_set_src(list_icons[button_index], app->icon);
        //lv_obj_set_style_image_recolor_opa(list_icons[slot_index], LV_OPA_TRANSP, LV_PART_MAIN);
    }

    if (list_labels[button_index] && app->name) {
        lv_label_set_text(list_labels[button_index], app->name);
    }
    
}

static void populate_page(void)
{
    for (int i = 0; i < NUM_SLOTS; i++) {
        menu_item_t *item = NULL;

        if (i < num_menu_items) {
            item = &menu_items[i];
        }
        populate_slot(i, item);
    }
}

lv_obj_t *app_menu_create(lv_obj_t *root, lv_group_t *group,
                          app_menu_on_app_selected_cb on_app_selected)
{
    app_selected_cb = on_app_selected;
    build_menu_items();

    memset(button_items, 0, sizeof(button_items));
    menu_root = app_menu_ui_create(root);
    cache_object_references();

    populate_page();

    if (menu_root == NULL) {
        LOG_ERR("Failed to create app menu UI");
        return NULL;
    }

    return menu_root;
}

void app_menu_delete(void)
{
    /* Save state before deleting */
    if (menu_root) {
        lv_obj_del(menu_root);
        menu_root = NULL;
    }

    app_list = NULL;
    memset(list_buttons, 0, sizeof(list_buttons));
    memset(list_labels, 0, sizeof(list_labels));
    memset(button_items, 0, sizeof(button_items));

    num_menu_items = 0;

    app_selected_cb = NULL;
}

void app_menu_on_app_clicked(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e);
    int button_index = (int)(intptr_t)lv_obj_get_user_data(target);

    if (button_index < 0 || button_index >= NUM_SLOTS || button_items[button_index] == NULL) {
        LOG_WRN("Click on invalid/empty button %d", button_index);
        return;
    }

    menu_item_t *item = button_items[button_index];
    LOG_DBG("App clicked: %s (slot %d)", item->app->name, button_index);
    if (app_selected_cb) {
        app_selected_cb(item->app);
    }
}
