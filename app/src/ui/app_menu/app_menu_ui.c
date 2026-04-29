#include "app_menu_ui.h"
#include "app_menu.h"

LV_FONT_DECLARE(roboto_semibold_16);

lv_obj_t *app_menu_ui_create(lv_obj_t *root)
{
    lv_obj_t *menu_ui_root = lv_obj_create(root);
    lv_obj_set_name(menu_ui_root, "app_menu");
    lv_obj_set_size(menu_ui_root, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_border_width(menu_ui_root, 0, LV_PART_MAIN);
    lv_obj_set_style_text_font(menu_ui_root, &roboto_semibold_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *app_list = lv_list_create(menu_ui_root);
    lv_obj_set_name(app_list, "app_list");
    lv_obj_set_size(app_list, LV_PCT(100), LV_PCT(100));
    lv_obj_center(app_list);

    // Create 6 buttons in the list
    lv_obj_t *button0 = lv_list_add_button(app_list, NULL, NULL);
    lv_obj_set_name(button0, "button0");
    lv_obj_t *icon0 = lv_image_create(button0);
    lv_obj_t *label0 = lv_label_create(button0);
    lv_obj_add_event_cb(button0, app_menu_on_app_clicked, LV_EVENT_SINGLE_CLICKED, NULL);

    lv_obj_t *button1 = lv_list_add_button(app_list, NULL, NULL);
    lv_obj_set_name(button1, "button1");
    lv_obj_t *icon1 = lv_image_create(button1);
    lv_obj_t *label1 = lv_label_create(button1);
    lv_obj_add_event_cb(button1, app_menu_on_app_clicked, LV_EVENT_SINGLE_CLICKED, NULL);

    lv_obj_t *button2 = lv_list_add_button(app_list, NULL, NULL);
    lv_obj_set_name(button2, "button2");
    lv_obj_t *icon2 = lv_image_create(button2);
    lv_obj_t *label2 = lv_label_create(button2);
    lv_obj_add_event_cb(button2, app_menu_on_app_clicked, LV_EVENT_SINGLE_CLICKED, NULL);

    lv_obj_t *button3 = lv_list_add_button(app_list, NULL, NULL);
    lv_obj_set_name(button3, "button3");
    lv_obj_t *icon3 = lv_image_create(button3);
    lv_obj_t *label3 = lv_label_create(button3);
    lv_obj_add_event_cb(button3, app_menu_on_app_clicked, LV_EVENT_SINGLE_CLICKED, NULL);

    lv_obj_t *button4 = lv_list_add_button(app_list, NULL, NULL);
    lv_obj_set_name(button4, "button4");
    lv_obj_t *icon4 = lv_image_create(button4);
    lv_obj_t *label4 = lv_label_create(button4);
    lv_obj_add_event_cb(button4, app_menu_on_app_clicked, LV_EVENT_SINGLE_CLICKED, NULL);

    lv_obj_t *button5 = lv_list_add_button(app_list, NULL, NULL);
    lv_obj_set_name(button5, "button5");
    lv_obj_t *icon5 = lv_image_create(button5);
    lv_obj_t *label5 = lv_label_create(button5);
    lv_obj_add_event_cb(button5, app_menu_on_app_clicked, LV_EVENT_SINGLE_CLICKED, NULL);

    lv_obj_update_layout(menu_ui_root);

    return menu_ui_root;
}