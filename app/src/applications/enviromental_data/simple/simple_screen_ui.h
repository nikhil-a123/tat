#ifndef SIMPLE_SCREEN_UI_H_
#define SIMPLE_SCREEN_UI_H_

#include <inttypes.h>
#include <lvgl.h>

void simple_screen_ui_show(lv_obj_t *root);

void simple_screen_ui_remove(void);

void simple_screen_ui_set_co2(uint32_t co2);

void simple_screen_ui_set_temp(float temp);

void simple_screen_ui_set_humid(float humid);

#endif /* SIMPLE_SCREEN_UI_H_ */