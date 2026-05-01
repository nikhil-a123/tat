
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#elif defined(LV_LVGL_H_INCLUDE_SYSTEM)
#include <lvgl.h>
#elif defined(LV_BUILD_TEST)
#include "../lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_MATERIAL_ICONS_WAVING_HAND_20_BLACK
#define LV_ATTRIBUTE_MATERIAL_ICONS_WAVING_HAND_20_BLACK
#endif

static const
LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_MATERIAL_ICONS_WAVING_HAND_20_BLACK
uint8_t material_icons_waving_hand_20_black_map[] = {

    0x00,0x00,0x00,0xdb,0x00,0x00,0x00,0x03,

    0xff,0xff,0xf0,
    0xf3,0xff,0xf0,
    0xc3,0xff,0xf0,
    0xcf,0xef,0xf0,
    0x9f,0xcc,0xf0,
    0x9d,0x89,0xf0,
    0xf8,0x12,0x70,
    0xf2,0x24,0x70,
    0xe4,0x48,0xf0,
    0xec,0xd1,0x70,
    0xcc,0xe2,0x70,
    0xce,0x74,0xf0,
    0xee,0xf9,0xf0,
    0xe6,0xf3,0xf0,
    0xe3,0xe7,0x90,
    0xf0,0x8f,0x90,
    0xfc,0x1f,0x30,
    0xff,0xfc,0x30,
    0xff,0xfc,0xf0,
    0xff,0xff,0xf0,

};

const lv_image_dsc_t material_icons_waving_hand_20_black = {
  .header = {
    .magic = LV_IMAGE_HEADER_MAGIC,
    .cf = LV_COLOR_FORMAT_I1,
    .flags = 0,
    .w = 20,
    .h = 20,
    .stride = 3,
    .reserved_2 = 0,
  },
  .data_size = sizeof(material_icons_waving_hand_20_black_map),
  .data = material_icons_waving_hand_20_black_map,
  .reserved = NULL,
};

