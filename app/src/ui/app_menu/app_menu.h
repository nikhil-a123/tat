#ifndef APP_MENU_H_
#define APP_MENU_H_

#include <lvgl.h>
#include "tat_app_manager.h"

// Callback function when app is selected
typedef void (*app_menu_on_app_selected_cb)(application_t *app);

// Callback function when app menu is closed
typedef void (*app_menu_on_close_cb)(void);

lv_obj_t *app_menu_create(lv_obj_t *root, lv_group_t *group,
                          app_menu_on_app_selected_cb on_app_selected,
                          const tat_app_folder_info_t *folders);

void app_menu_delete(void);

void app_menu_on_app_clicked(lv_event_t *e);

bool app_menu_is_folder_open(void);

void app_menu_close_folder(void);

#endif /* APP_MENU_H_ */