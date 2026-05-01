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
// Number of items per page
#define ITEMS_PER_PAGE 6

typedef enum {
    MENU_ITEM_INVALID = 0,
    MENU_ITEM_APP,
    MENU_ITEM_FOLDER
} menu_item_type_t;

// Menu item can either be a folder or an application
typedef struct {
    menu_item_type_t type;
    union {
        application_t *app;
        struct {
            tat_app_category_t category;
            const char *name;
            const void *icon;
        } folder;
    };
} menu_item_t;

static const tat_app_folder_info_t *folder_info;

static lv_obj_t *menu_root;
static app_menu_on_app_selected_cb app_selected_cb;

static lv_obj_t *app_list;
static lv_obj_t *list_buttons[NUM_SLOTS];
static lv_obj_t *list_icons[NUM_SLOTS];
static lv_obj_t *list_labels[NUM_SLOTS];

//static menu_item_t menu_items[MAX_MENU_ITEMS];
//static int num_menu_items;

static menu_item_t button_items[NUM_SLOTS];

static tat_app_category_t open_folder = TAT_APP_CATEGORY_INVALID;
static tat_app_category_t last_folder = TAT_APP_CATEGORY_INVALID;

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

static bool folder_has_apps(tat_app_category_t category)
{
    int num_apps = tat_app_manager_get_num_apps();

    for (int i = 0; i < num_apps; i++) {
        application_t *app = tat_app_manager_get_app(i);
        if (app && !app->hidden && app->category == category) {
            return true;
        }
    }

    return false;
}

static void populate_button(int button_index)
{
    if (button_index < 0 || button_index >= NUM_SLOTS) {
        return;
    }

    if (button_items[button_index].type == MENU_ITEM_INVALID) {
        // No item to display
        lv_obj_add_flag(list_buttons[button_index], LV_OBJ_FLAG_HIDDEN);
        return;
    }

    // There is an item to populate
    lv_obj_remove_flag(list_buttons[button_index], LV_OBJ_FLAG_HIDDEN);
    if (button_items[button_index].type == MENU_ITEM_APP) {
        application_t *app = button_items[button_index].app;
        if (list_icons[button_index] && app->icon) {
            lv_image_set_src(list_icons[button_index], app->icon);
        }

        if (list_labels[button_index] && app->name) {
            lv_label_set_text(list_labels[button_index], app->name);
        }
    } else {
        if (list_icons[button_index] && button_items[button_index].folder.icon) {
            lv_image_set_src(list_icons[button_index], button_items[button_index].folder.icon);
        }

        if (list_labels[button_index] && button_items[button_index].folder.name) {
            lv_label_set_text(list_labels[button_index], button_items[button_index].folder.name);
        }
    }
}

static void populate_page(void)
{
    for (int i = 0; i < NUM_SLOTS; i++) {
        populate_button(i);
    }
}

static void draw_root_app_menu(void)
{
    int button_index = 0;
    int num_apps = tat_app_manager_get_num_apps();

    // Clear the button items
    memset(button_items, 0, sizeof(button_items));

    // Add apps in root category
    for (int i = 0; i < num_apps; i++) {
        application_t *app = tat_app_manager_get_app(i);
        if (app && !app->hidden && app->category == TAT_APP_CATEGORY_ROOT) {
            button_items[button_index].type = MENU_ITEM_APP;
            button_items[button_index].app = app;
            button_index++;
        }
    }

    // Add folders
    for (int cat = TAT_APP_CATEGORY_SYSTEM; cat < TAT_APP_CATEGORY_NUM_OF && button_index < NUM_SLOTS; cat++) {
        if (folder_has_apps((tat_app_category_t)cat)) {
            button_items[button_index].type = MENU_ITEM_FOLDER;
            button_items[button_index].folder.category = (tat_app_category_t)cat;
            button_items[button_index].folder.name = folder_info[cat].name;
            button_items[button_index].folder.icon = folder_info[cat].icon;
            button_index++;
        }
    }

    // Draw the page
    populate_page();
}

static void draw_apps_in_folder(tat_app_category_t category)
{
    int button_index = 0;
    int num_apps = tat_app_manager_get_num_apps();

    // Clear the button items
    memset(button_items, 0, sizeof(button_items));

    // Add apps that match the requested category
    for (int i = 0; i < num_apps; i++) {
        application_t *app = tat_app_manager_get_app(i);
        if (app && !app->hidden && app->category == category) {
            button_items[button_index].type = MENU_ITEM_APP;
            button_items[button_index].app = app;
            button_index++;
        }
    }

    // Draw the page
    populate_page();
}

lv_obj_t *app_menu_create(lv_obj_t *root, lv_group_t *group,
                          app_menu_on_app_selected_cb on_app_selected,
                          const tat_app_folder_info_t *folders)
{
    app_selected_cb = on_app_selected;
    folder_info = folders;
    open_folder = TAT_APP_CATEGORY_INVALID;

    memset(button_items, 0, sizeof(button_items));
    menu_root = app_menu_ui_create(root);
    if (menu_root == NULL) {
        LOG_ERR("Failed to create app menu UI");
        return NULL;
    }

    cache_object_references();

    if (last_folder != TAT_APP_CATEGORY_INVALID && folder_has_apps(last_folder)) {
        draw_apps_in_folder(last_folder);
    } else {
        draw_root_app_menu();
    }
    
    return menu_root;
}

void app_menu_delete(void)
{
    /* Save folder state before deleting */
    last_folder = open_folder;

    if (menu_root) {
        lv_obj_del(menu_root);
        menu_root = NULL;
    }

    app_list = NULL;
    memset(list_buttons, 0, sizeof(list_buttons));
    memset(list_labels, 0, sizeof(list_labels));
    memset(button_items, 0, sizeof(button_items));

    app_selected_cb = NULL;
}

void app_menu_on_app_clicked(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e);
    int button_index = (int)(intptr_t)lv_obj_get_user_data(target);

    if (button_index < 0 || button_index >= NUM_SLOTS || button_items[button_index].type == MENU_ITEM_INVALID) {
        LOG_WRN("Click on invalid/empty button %d", button_index);
        return;
    }

    //menu_item_t *item = button_items[button_index];
    if (button_items[button_index].type == MENU_ITEM_APP) {
        LOG_DBG("App clicked: %s (slot %d)", button_items[button_index].app->name, button_index);
        if (app_selected_cb) {
            app_selected_cb(button_items[button_index].app);
        }
    } else {
        LOG_DBG("Folder clicked: %s (slot %d)", button_items[button_index].folder.name, button_index);
        draw_apps_in_folder(button_items[button_index].folder.category);
    }
}
