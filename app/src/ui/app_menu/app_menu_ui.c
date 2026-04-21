#include "app_menu_ui.h"

lv_obj_t *app_menu_ui_create(lv_obj_t *root)
{
    lv_obj_t *menu_ui_root = lv_obj_create(root);
    lv_obj_set_name(menu_ui_root, "app_menu");
    lv_obj_set_size(menu_ui_root, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_border_width(menu_ui_root, 0, LV_PART_MAIN);

    lv_obj_t *app_list = lv_list_create(menu_ui_root);
    lv_obj_set_name(app_list, "app_list");
    lv_obj_set_size(app_list, LV_PCT(100), LV_PCT(100));
    lv_obj_center(app_list);

    // Create 6 buttons in the list
    lv_obj_t *button0 = lv_list_add_button(app_list, NULL, "Button 0");
    lv_obj_set_name(button0, "button0");

    lv_obj_t *button1 = lv_list_add_button(app_list, NULL, "Button 1");
    lv_obj_set_name(button1, "button1");

    lv_obj_t *button2 = lv_list_add_button(app_list, NULL, "Button 2");
    lv_obj_set_name(button2, "button2");

    lv_obj_t *button3 = lv_list_add_button(app_list, NULL, "Button 3");
    lv_obj_set_name(button3, "button3");

    lv_obj_t *button4 = lv_list_add_button(app_list, NULL, "Button 4");
    lv_obj_set_name(button4, "button4");

    lv_obj_t *button5 = lv_list_add_button(app_list, NULL, "Button 5");
    lv_obj_set_name(button5, "button5");

    return menu_ui_root;
}