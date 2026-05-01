#ifndef ABOUT_UI_H_
#define ABOUT_UI_H_

#include <inttypes.h>
#include <lvgl.h>

void about_ui_show(lv_obj_t *root, char *board, char *fw_version, char *sdk_version, int num_apps);

void about_ui_remove(void);

#endif /* ABOUT_UI_H_ */