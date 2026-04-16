/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --no-compress --stride 1 --align 1 --font Roboto-Medium.ttf --range 32-255 --format lvgl -o roboto_medium_16.c
 ******************************************************************************/

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif



#ifndef ROBOTO_MEDIUM_16
#define ROBOTO_MEDIUM_16 1
#endif

#if ROBOTO_MEDIUM_16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0x3,

    /* U+0022 "\"" */
    0xff, 0xff,

    /* U+0023 "#" */
    0x1a, 0xd, 0x4, 0x8f, 0xf1, 0x20, 0xb0, 0xd8,
    0x68, 0xff, 0x12, 0x9, 0x5, 0x80,

    /* U+0024 "$" */
    0x8, 0x8, 0x3c, 0xfe, 0xc7, 0xc3, 0xc0, 0x78,
    0xe, 0x3, 0xc3, 0xe3, 0x7f, 0x3c, 0x8, 0x8,

    /* U+0025 "%" */
    0x70, 0x1b, 0x23, 0x64, 0x6d, 0x7, 0x20, 0x8,
    0x1, 0x0, 0x5e, 0x16, 0x62, 0xcc, 0x99, 0x81,
    0xe0,

    /* U+0026 "&" */
    0x3c, 0x19, 0x86, 0x61, 0xb8, 0x7c, 0xe, 0x7,
    0x83, 0xb6, 0xcf, 0xb1, 0xc6, 0x78, 0xf6,

    /* U+0027 "'" */
    0xff,

    /* U+0028 "(" */
    0x11, 0x98, 0xc4, 0x63, 0x18, 0xc6, 0x31, 0x86,
    0x30, 0x82, 0x0,

    /* U+0029 ")" */
    0x43, 0xc, 0x61, 0xc, 0x63, 0x18, 0xc6, 0x33,
    0x19, 0x88, 0x0,

    /* U+002A "*" */
    0x10, 0x23, 0x53, 0xe3, 0x85, 0x13, 0x0,

    /* U+002B "+" */
    0x18, 0x18, 0x18, 0x18, 0xff, 0x18, 0x18, 0x18,
    0x18,

    /* U+002C "," */
    0x6d, 0xe0,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0xc, 0x20, 0x86, 0x10, 0x43, 0x8, 0x21, 0x84,
    0x10, 0xc0,

    /* U+0030 "0" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0x66, 0x3c,

    /* U+0031 "1" */
    0x1b, 0xfe, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x30,

    /* U+0032 "2" */
    0x3c, 0x66, 0xc6, 0xc6, 0x6, 0xe, 0x1c, 0x18,
    0x30, 0x70, 0xe0, 0xff,

    /* U+0033 "3" */
    0x3c, 0x63, 0xc3, 0x3, 0xf, 0x1e, 0x1f, 0x3,
    0x3, 0x43, 0x66, 0x3c,

    /* U+0034 "4" */
    0x6, 0x7, 0x7, 0x83, 0xc3, 0x61, 0x31, 0x99,
    0x8c, 0xff, 0x83, 0x1, 0x80, 0xc0,

    /* U+0035 "5" */
    0x7f, 0x60, 0x60, 0x60, 0x7c, 0x66, 0x3, 0x3,
    0x3, 0x43, 0x66, 0x3c,

    /* U+0036 "6" */
    0x1c, 0x30, 0x60, 0x40, 0xdc, 0xe6, 0xc3, 0xc3,
    0xc3, 0xc3, 0x66, 0x3c,

    /* U+0037 "7" */
    0xff, 0x3, 0x6, 0x6, 0xc, 0xc, 0xc, 0x18,
    0x18, 0x30, 0x30, 0x30,

    /* U+0038 "8" */
    0x7c, 0xc6, 0xc6, 0xc6, 0xee, 0x7c, 0x7e, 0xc3,
    0xc3, 0xc3, 0x66, 0x3c,

    /* U+0039 "9" */
    0x38, 0xdb, 0x1e, 0x3c, 0x78, 0xdb, 0xbf, 0x6,
    0x18, 0x31, 0x80,

    /* U+003A ":" */
    0xc0, 0x0, 0xc0,

    /* U+003B ";" */
    0xc0, 0xf, 0xe0,

    /* U+003C "<" */
    0x6, 0x3d, 0xe7, 0xf, 0x7, 0x83, 0x81,

    /* U+003D "=" */
    0xfe, 0x0, 0x0, 0xf, 0xe0,

    /* U+003E ">" */
    0x81, 0xc0, 0xf0, 0x71, 0xef, 0x38, 0x0,

    /* U+003F "?" */
    0x3c, 0xcf, 0x98, 0x30, 0x61, 0xc7, 0xc, 0x18,
    0x0, 0x0, 0xc0,

    /* U+0040 "@" */
    0xf, 0x80, 0xc3, 0xc, 0x4, 0xc7, 0x26, 0x4c,
    0xe6, 0x67, 0x32, 0x39, 0x11, 0xc8, 0x8e, 0x44,
    0x73, 0x64, 0xcc, 0xc6, 0x0, 0x1c, 0x0, 0x3e,
    0x0,

    /* U+0041 "A" */
    0xc, 0x3, 0x81, 0xe0, 0x78, 0x13, 0xc, 0xc3,
    0x30, 0xc6, 0x7f, 0x98, 0x66, 0xf, 0x3,

    /* U+0042 "B" */
    0xfe, 0xc3, 0xc3, 0xc3, 0xc6, 0xfc, 0xc7, 0xc3,
    0xc3, 0xc3, 0xc6, 0xfc,

    /* U+0043 "C" */
    0x1e, 0x31, 0x90, 0x78, 0x3c, 0x6, 0x3, 0x1,
    0x80, 0xc1, 0xa0, 0xd8, 0xc7, 0xc0,

    /* U+0044 "D" */
    0xf8, 0xc6, 0xc6, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc6, 0xc6, 0xf8,

    /* U+0045 "E" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc0, 0xc0,
    0xc0, 0xc0, 0xc0, 0xff,

    /* U+0046 "F" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0047 "G" */
    0x3e, 0x31, 0x98, 0x78, 0xc, 0x6, 0x3, 0x1f,
    0x83, 0xc1, 0xb0, 0xd8, 0x63, 0xe0,

    /* U+0048 "H" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1f, 0xff, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x30,

    /* U+0049 "I" */
    0xff, 0xff, 0xff,

    /* U+004A "J" */
    0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83, 0x7,
    0x8f, 0x33, 0xc0,

    /* U+004B "K" */
    0xc3, 0x63, 0xb3, 0x99, 0x8d, 0x87, 0xc3, 0xe1,
    0xd8, 0xce, 0x63, 0x30, 0xd8, 0x70,

    /* U+004C "L" */
    0xc1, 0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1,
    0x83, 0x7, 0xf0,

    /* U+004D "M" */
    0xe0, 0x7e, 0x7, 0xf0, 0xff, 0xf, 0xd0, 0xbd,
    0x9b, 0xd9, 0xbc, 0x93, 0xcf, 0x3c, 0xf3, 0xc6,
    0x3c, 0x63,

    /* U+004E "N" */
    0xc1, 0xf0, 0xf8, 0x7e, 0x3d, 0x9e, 0xcf, 0x37,
    0x9b, 0xc7, 0xe1, 0xf0, 0xf8, 0x30,

    /* U+004F "O" */
    0x3e, 0x31, 0x98, 0xd8, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xb1, 0x98, 0xc7, 0xc0,

    /* U+0050 "P" */
    0xfc, 0xc6, 0xc3, 0xc3, 0xc3, 0xc6, 0xfc, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0051 "Q" */
    0x3e, 0x31, 0x98, 0xd8, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xb1, 0x98, 0xc7, 0xc0, 0x38, 0x8,

    /* U+0052 "R" */
    0xfc, 0xc6, 0xc3, 0xc3, 0xc3, 0xc6, 0xfc, 0xcc,
    0xc6, 0xc6, 0xc3, 0xc3,

    /* U+0053 "S" */
    0x1e, 0x19, 0x98, 0x6c, 0x7, 0x81, 0xf0, 0x7c,
    0x7, 0x1, 0xb0, 0xd8, 0x47, 0xc0,

    /* U+0054 "T" */
    0xff, 0xc3, 0x0, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30,

    /* U+0055 "U" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xd8, 0xc7, 0xc0,

    /* U+0056 "V" */
    0xc0, 0xd8, 0x36, 0x19, 0x86, 0x31, 0x8c, 0xc3,
    0x30, 0x6c, 0x1e, 0x7, 0x80, 0xe0, 0x30,

    /* U+0057 "W" */
    0xc7, 0x1e, 0x38, 0xf1, 0xcd, 0x8e, 0x66, 0xd3,
    0x36, 0xd9, 0xb6, 0x8d, 0xbc, 0x78, 0xe1, 0xc7,
    0xe, 0x38, 0x61, 0x80,

    /* U+0058 "X" */
    0x61, 0x98, 0x63, 0x30, 0xec, 0x1e, 0x3, 0x81,
    0xe0, 0x78, 0x3b, 0xc, 0xc6, 0x19, 0x87,

    /* U+0059 "Y" */
    0xe1, 0xd8, 0x67, 0x38, 0xcc, 0x33, 0x7, 0x81,
    0xe0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30,

    /* U+005A "Z" */
    0xff, 0x81, 0xc0, 0xc0, 0xc0, 0xe0, 0x60, 0x60,
    0x70, 0x30, 0x30, 0x38, 0x1f, 0xf0,

    /* U+005B "[" */
    0xfb, 0x6d, 0xb6, 0xdb, 0x6d, 0xb7,

    /* U+005C "\\" */
    0xc0, 0xc1, 0x83, 0x3, 0x6, 0x4, 0xc, 0x18,
    0x18, 0x30, 0x60, 0x60,

    /* U+005D "]" */
    0xf3, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3f,

    /* U+005E "^" */
    0x10, 0xe2, 0x9a, 0x6d, 0x10,

    /* U+005F "_" */
    0xfe,

    /* U+0060 "`" */
    0xe6, 0x30,

    /* U+0061 "a" */
    0x7d, 0xcf, 0x18, 0x37, 0xf8, 0xf1, 0xe3, 0x7e,

    /* U+0062 "b" */
    0xc1, 0x83, 0x7, 0xcc, 0xd8, 0xf1, 0xe3, 0xc7,
    0x8f, 0x37, 0xc0,

    /* U+0063 "c" */
    0x3c, 0x66, 0xc2, 0xc0, 0xc0, 0xc0, 0xc2, 0x66,
    0x3c,

    /* U+0064 "d" */
    0x6, 0xc, 0x19, 0xf6, 0x78, 0xf1, 0xe3, 0xc7,
    0x8d, 0x99, 0xf0,

    /* U+0065 "e" */
    0x38, 0xdb, 0x1e, 0x3f, 0xf8, 0x30, 0x33, 0x3c,

    /* U+0066 "f" */
    0x3b, 0x19, 0xf6, 0x31, 0x8c, 0x63, 0x18, 0xc0,

    /* U+0067 "g" */
    0x3f, 0x67, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x67,
    0x3f, 0x3, 0x46, 0x7c,

    /* U+0068 "h" */
    0xc1, 0x83, 0x6, 0xee, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x30,

    /* U+0069 "i" */
    0xc3, 0xff, 0xff,

    /* U+006A "j" */
    0x30, 0x3, 0x33, 0x33, 0x33, 0x33, 0x33, 0xe0,

    /* U+006B "k" */
    0xc0, 0xc0, 0xc0, 0xc6, 0xcc, 0xd8, 0xf0, 0xf8,
    0xf8, 0xcc, 0xce, 0xc6,

    /* U+006C "l" */
    0xff, 0xff, 0xff,

    /* U+006D "m" */
    0xdd, 0xee, 0x63, 0xc6, 0x3c, 0x63, 0xc6, 0x3c,
    0x63, 0xc6, 0x3c, 0x63, 0xc6, 0x30,

    /* U+006E "n" */
    0xdd, 0xcf, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6,

    /* U+006F "o" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66,
    0x3c,

    /* U+0070 "p" */
    0xfd, 0x9b, 0x1e, 0x3c, 0x78, 0xf1, 0xe6, 0xf9,
    0x83, 0x6, 0x0,

    /* U+0071 "q" */
    0x7e, 0xcf, 0x1e, 0x3c, 0x78, 0xf1, 0xb3, 0x7e,
    0xc, 0x18, 0x30,

    /* U+0072 "r" */
    0xff, 0x31, 0x8c, 0x63, 0x18, 0xc0,

    /* U+0073 "s" */
    0x3c, 0x8f, 0x1f, 0x87, 0xc3, 0xf1, 0xe3, 0x7c,

    /* U+0074 "t" */
    0x63, 0x3e, 0xc6, 0x31, 0x8c, 0x63, 0xe,

    /* U+0075 "u" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe7, 0x7e,

    /* U+0076 "v" */
    0xc7, 0x8d, 0x9b, 0x66, 0xc5, 0x8e, 0x1c, 0x18,

    /* U+0077 "w" */
    0xcc, 0x79, 0x8b, 0x3b, 0x67, 0x65, 0xac, 0xe5,
    0x1c, 0xe3, 0x8c, 0x31, 0x80,

    /* U+0078 "x" */
    0x66, 0x66, 0x3c, 0x3c, 0x18, 0x3c, 0x3c, 0x66,
    0x67,

    /* U+0079 "y" */
    0xc3, 0x66, 0x66, 0x66, 0x34, 0x3c, 0x3c, 0x18,
    0x18, 0x18, 0x10, 0x60,

    /* U+007A "z" */
    0xfe, 0x1c, 0x30, 0xc3, 0x86, 0x18, 0x70, 0xfe,

    /* U+007B "{" */
    0x0, 0xcc, 0x63, 0x18, 0xce, 0xe7, 0x8c, 0x63,
    0x18, 0xc3, 0x8,

    /* U+007C "|" */
    0xff, 0xfc,

    /* U+007D "}" */
    0x6, 0x18, 0xc6, 0x31, 0x8e, 0x3b, 0x98, 0xc6,
    0x31, 0x98, 0x0,

    /* U+007E "~" */
    0x71, 0xe4, 0xf1, 0xc0,

    /* U+00A0 " " */
    0x0,

    /* U+00A1 "¡" */
    0xc3, 0xff, 0xfc,

    /* U+00A2 "¢" */
    0x18, 0x18, 0x3c, 0x7e, 0xe6, 0xc0, 0xc0, 0xc0,
    0xe6, 0x7e, 0x3c, 0x18, 0x18,

    /* U+00A3 "£" */
    0x1e, 0x23, 0x63, 0x60, 0x60, 0x60, 0xf8, 0x60,
    0x60, 0x60, 0x60, 0xff,

    /* U+00A4 "¤" */
    0xde, 0xdc, 0xe6, 0x1b, 0x3, 0xc0, 0xf0, 0x3c,
    0xd, 0x86, 0x73, 0xb7, 0xb0,

    /* U+00A5 "¥" */
    0xc3, 0x67, 0x66, 0x66, 0x3c, 0x3c, 0x7e, 0x18,
    0x7e, 0x18, 0x18, 0x18,

    /* U+00A6 "¦" */
    0xff, 0xf0, 0xff, 0xf0,

    /* U+00A7 "§" */
    0x3c, 0xc7, 0xc3, 0xe0, 0x7c, 0xfe, 0xc7, 0xc3,
    0xfb, 0x7e, 0x1f, 0x3, 0xc3, 0xe3, 0x3c,

    /* U+00A8 "¨" */
    0xcc,

    /* U+00A9 "©" */
    0x1f, 0x6, 0x31, 0x39, 0x68, 0xb9, 0x3, 0x20,
    0x64, 0xc, 0x89, 0xce, 0x68, 0x8, 0xc6, 0xf,
    0x80,

    /* U+00AA "ª" */
    0x72, 0x5e, 0x94, 0xbc,

    /* U+00AB "«" */
    0x2d, 0x2d, 0x16, 0x48, 0xb0,

    /* U+00AC "¬" */
    0xfe, 0xc, 0x18,

    /* U+00AD "­" */
    0xf0,

    /* U+00AE "®" */
    0x1f, 0x6, 0x31, 0x79, 0x68, 0xb9, 0x13, 0x22,
    0x67, 0x8c, 0x89, 0xd1, 0x68, 0x8, 0xc6, 0xf,
    0x80,

    /* U+00AF "¯" */
    0xf8,

    /* U+00B0 "°" */
    0x69, 0x96,

    /* U+00B1 "±" */
    0x18, 0x30, 0x60, 0xcf, 0xe3, 0x6, 0xc, 0x18,
    0x3, 0xf8,

    /* U+00B2 "²" */
    0x76, 0xc6, 0x66, 0x7c,

    /* U+00B3 "³" */
    0x70, 0x4e, 0x14, 0xb8,

    /* U+00B4 "´" */
    0x76, 0xc0,

    /* U+00B5 "µ" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xff,
    0x83, 0x6, 0x0,

    /* U+00B6 "¶" */
    0x3e, 0xfd, 0xff, 0xf7, 0xef, 0xcf, 0x83, 0x6,
    0xc, 0x18, 0x30,

    /* U+00B7 "·" */
    0xc0,

    /* U+00B8 "¸" */
    0x99, 0x60,

    /* U+00B9 "¹" */
    0x7c, 0x92, 0x40,

    /* U+00BA "º" */
    0x74, 0x63, 0x18, 0xb8,

    /* U+00BB "»" */
    0x91, 0x26, 0xda, 0xda, 0x40,

    /* U+00BC "¼" */
    0x70, 0x16, 0x20, 0xcc, 0x19, 0x3, 0x60, 0x69,
    0x83, 0x70, 0x4e, 0x1a, 0xc2, 0x7c, 0x3, 0x0,
    0x60,

    /* U+00BD "½" */
    0x70, 0x1e, 0x20, 0xc8, 0x1b, 0x3, 0x40, 0x7b,
    0x82, 0xd8, 0xc3, 0x10, 0xc6, 0x30, 0xf, 0x80,

    /* U+00BE "¾" */
    0x78, 0x4, 0xc8, 0x1c, 0x83, 0x98, 0xd, 0x4,
    0xf0, 0x7a, 0x60, 0x6e, 0x4, 0xe0, 0xd6, 0x9,
    0xf0, 0x6, 0x0, 0x60,

    /* U+00BF "¿" */
    0x30, 0x0, 0x1, 0x83, 0xe, 0x18, 0x60, 0xc1,
    0x8f, 0x3b, 0xe0,

    /* U+00C0 "À" */
    0x18, 0x3, 0x0, 0x40, 0x30, 0xe, 0x7, 0x81,
    0xe0, 0x4c, 0x33, 0xc, 0xc3, 0x19, 0xfe, 0x61,
    0x98, 0x3c, 0xc,

    /* U+00C1 "Á" */
    0x6, 0x1, 0x80, 0xc0, 0x30, 0xe, 0x7, 0x81,
    0xe0, 0x4c, 0x33, 0xc, 0xc3, 0x19, 0xfe, 0x61,
    0x98, 0x3c, 0xc,

    /* U+00C2 "Â" */
    0xc, 0x6, 0x80, 0x0, 0x30, 0xe, 0x7, 0x81,
    0xe0, 0x4c, 0x33, 0xc, 0xc3, 0x19, 0xfe, 0x61,
    0x98, 0x3c, 0xc,

    /* U+00C3 "Ã" */
    0x19, 0xd, 0x80, 0x0, 0x30, 0xe, 0x7, 0x81,
    0xe0, 0x4c, 0x33, 0xc, 0xc3, 0x19, 0xfe, 0x61,
    0x98, 0x3c, 0xc,

    /* U+00C4 "Ä" */
    0x33, 0x0, 0x0, 0xc0, 0x78, 0x1e, 0x7, 0x83,
    0x30, 0xcc, 0x33, 0x18, 0x67, 0xf9, 0x86, 0x40,
    0xf0, 0x30,

    /* U+00C5 "Å" */
    0xc, 0x4, 0x81, 0x20, 0x30, 0xc, 0x7, 0x81,
    0xe0, 0x78, 0x33, 0xc, 0xc3, 0x31, 0x86, 0x7f,
    0x98, 0x66, 0xf, 0x3,

    /* U+00C6 "Æ" */
    0x3, 0xfc, 0x1e, 0x0, 0x58, 0x3, 0x60, 0x9,
    0x80, 0x67, 0xe1, 0x98, 0xc, 0x60, 0x3f, 0x81,
    0x86, 0xe, 0x18, 0x30, 0x7f,

    /* U+00C7 "Ç" */
    0x1e, 0x31, 0x98, 0x78, 0x3c, 0x6, 0x3, 0x1,
    0x80, 0xc1, 0xa0, 0xd8, 0xc3, 0xc0, 0xc0, 0x30,
    0x30,

    /* U+00C8 "È" */
    0x60, 0x30, 0x18, 0xff, 0xc0, 0xc0, 0xc0, 0xc0,
    0xfe, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xff,

    /* U+00C9 "É" */
    0xc, 0x18, 0x10, 0xff, 0xc0, 0xc0, 0xc0, 0xc0,
    0xfe, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xff,

    /* U+00CA "Ê" */
    0x18, 0x2c, 0x0, 0xff, 0xc0, 0xc0, 0xc0, 0xc0,
    0xfe, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xff,

    /* U+00CB "Ë" */
    0x66, 0x0, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xff,

    /* U+00CC "Ì" */
    0x62, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x30,

    /* U+00CD "Í" */
    0x64, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xc0,

    /* U+00CE "Î" */
    0x31, 0x20, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0xc, 0x30, 0xc3, 0x0,

    /* U+00CF "Ï" */
    0xcc, 0x3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0xc, 0x30, 0xc0,

    /* U+00D0 "Ð" */
    0x7c, 0x31, 0x98, 0xcc, 0x36, 0x1f, 0xcd, 0x86,
    0xc3, 0x61, 0xb1, 0x98, 0xcf, 0x80,

    /* U+00D1 "Ñ" */
    0x32, 0x17, 0x0, 0x18, 0x3e, 0x1f, 0xf, 0xc7,
    0xb3, 0xd9, 0xe6, 0xf3, 0x78, 0xfc, 0x3e, 0x1f,
    0x6,

    /* U+00D2 "Ò" */
    0x30, 0xc, 0x2, 0x0, 0x3, 0xe3, 0x19, 0x8d,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1b, 0x19,
    0x8c, 0x7c,

    /* U+00D3 "Ó" */
    0x6, 0x6, 0x2, 0x0, 0x3, 0xe3, 0x19, 0x8d,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1b, 0x19,
    0x8c, 0x7c,

    /* U+00D4 "Ô" */
    0x8, 0xe, 0xd, 0x80, 0x3, 0xe3, 0x19, 0x8d,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1b, 0x19,
    0x8c, 0x7c,

    /* U+00D5 "Õ" */
    0x32, 0x17, 0x0, 0x7, 0xc6, 0x33, 0x1b, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x36, 0x33, 0x18,
    0xf8,

    /* U+00D6 "Ö" */
    0x33, 0x0, 0xf, 0x8c, 0x66, 0x36, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x6c, 0x66, 0x31, 0xf0,

    /* U+00D7 "×" */
    0xc5, 0x99, 0xe1, 0x87, 0x99, 0xb1, 0x80,

    /* U+00D8 "Ø" */
    0x3f, 0xb1, 0x98, 0xd8, 0x7c, 0x5e, 0x6f, 0x27,
    0xb3, 0xd1, 0xb1, 0x98, 0xcf, 0xcc, 0x0,

    /* U+00D9 "Ù" */
    0x30, 0xc, 0x0, 0x18, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1b, 0x18,
    0xf8,

    /* U+00DA "Ú" */
    0x6, 0x6, 0x0, 0x18, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1b, 0x18,
    0xf8,

    /* U+00DB "Û" */
    0x1c, 0x1b, 0x0, 0x18, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1b, 0x18,
    0xf8,

    /* U+00DC "Ü" */
    0x66, 0x0, 0x30, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x36, 0x31, 0xf0,

    /* U+00DD "Ý" */
    0x6, 0x1, 0x0, 0x3, 0x87, 0x61, 0x9c, 0xe3,
    0x30, 0xcc, 0x1e, 0x7, 0x80, 0xc0, 0x30, 0xc,
    0x3, 0x0, 0xc0,

    /* U+00DE "Þ" */
    0xc0, 0xc0, 0xc0, 0xfc, 0xc7, 0xc3, 0xc3, 0xc7,
    0xfc, 0xc0, 0xc0, 0xc0,

    /* U+00DF "ß" */
    0x3c, 0xc6, 0xc6, 0xc6, 0xcc, 0xcc, 0xcc, 0xc6,
    0xc3, 0xc3, 0xc3, 0xde,

    /* U+00E0 "à" */
    0x30, 0x20, 0x3, 0xec, 0x60, 0xc1, 0xbf, 0xc7,
    0x8f, 0x1b, 0xf0,

    /* U+00E1 "á" */
    0xc, 0x30, 0x3, 0xee, 0x78, 0xc1, 0xbf, 0xc7,
    0x8f, 0x1b, 0xf0,

    /* U+00E2 "â" */
    0x18, 0xd8, 0x3, 0xee, 0x78, 0xc1, 0xbf, 0xc7,
    0x8f, 0x1b, 0xf0,

    /* U+00E3 "ã" */
    0x7c, 0x0, 0x3, 0xee, 0x78, 0xc1, 0xbf, 0xc7,
    0x8f, 0x1b, 0xf0,

    /* U+00E4 "ä" */
    0x6c, 0x0, 0x3, 0xee, 0x78, 0xc1, 0xbf, 0xc7,
    0x8f, 0x3b, 0xb0,

    /* U+00E5 "å" */
    0x38, 0x50, 0xe0, 0x7, 0xd8, 0xf1, 0x83, 0x7f,
    0x8f, 0x1e, 0x77, 0x60,

    /* U+00E6 "æ" */
    0x3d, 0xe3, 0x39, 0xb1, 0x86, 0xc, 0x37, 0xff,
    0xe3, 0x3, 0x18, 0x18, 0xe2, 0x79, 0xf0,

    /* U+00E7 "ç" */
    0x3c, 0x66, 0xc2, 0xc0, 0xc0, 0xc6, 0xe6, 0x7e,
    0x3c, 0x18, 0xc, 0x18,

    /* U+00E8 "è" */
    0x20, 0x60, 0x1, 0xc6, 0xd8, 0xf1, 0xff, 0xc1,
    0x81, 0x99, 0xe0,

    /* U+00E9 "é" */
    0x8, 0x20, 0x1, 0xc6, 0xd8, 0xf1, 0xff, 0xc1,
    0x81, 0x99, 0xe0,

    /* U+00EA "ê" */
    0x30, 0xd0, 0x1, 0xc6, 0xd8, 0xf1, 0xff, 0xc1,
    0x81, 0x99, 0xe0,

    /* U+00EB "ë" */
    0x6c, 0x0, 0x1, 0xc6, 0xd8, 0xf1, 0xff, 0xc1,
    0x81, 0x99, 0xe0,

    /* U+00EC "ì" */
    0x63, 0x3, 0x33, 0x33, 0x33, 0x33,

    /* U+00ED "í" */
    0x6c, 0xc, 0xcc, 0xcc, 0xcc, 0xcc,

    /* U+00EE "î" */
    0x31, 0x20, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0xc,

    /* U+00EF "ï" */
    0xcc, 0x0, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0xc,

    /* U+00F0 "ð" */
    0x20, 0x7e, 0x1c, 0x3e, 0x6, 0x3f, 0x63, 0xc3,
    0xc3, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+00F1 "ñ" */
    0x7c, 0x0, 0x6, 0xee, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x30,

    /* U+00F2 "ò" */
    0x30, 0x18, 0x0, 0x3c, 0x66, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0x66, 0x3c,

    /* U+00F3 "ó" */
    0xc, 0x18, 0x0, 0x3c, 0x66, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0x66, 0x3c,

    /* U+00F4 "ô" */
    0x18, 0x24, 0x0, 0x3c, 0x66, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0x66, 0x3c,

    /* U+00F5 "õ" */
    0x7e, 0x0, 0x0, 0x3c, 0x66, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0x66, 0x3c,

    /* U+00F6 "ö" */
    0x66, 0x0, 0x0, 0x3c, 0x66, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0x66, 0x3c,

    /* U+00F7 "÷" */
    0x18, 0x0, 0x0, 0xff, 0x0, 0x0, 0x0, 0x18,

    /* U+00F8 "ø" */
    0x2, 0x3e, 0x66, 0xcf, 0xcb, 0xdb, 0xd3, 0xf3,
    0x66, 0x3c, 0x40,

    /* U+00F9 "ù" */
    0x60, 0x60, 0x6, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x3b, 0xf0,

    /* U+00FA "ú" */
    0xc, 0x30, 0x6, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x3b, 0xf0,

    /* U+00FB "û" */
    0x38, 0xd8, 0x6, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x3b, 0xf0,

    /* U+00FC "ü" */
    0x6c, 0x0, 0x6, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x3b, 0xf0,

    /* U+00FD "ý" */
    0xc, 0x8, 0x0, 0xc3, 0x66, 0x66, 0x66, 0x34,
    0x3c, 0x3c, 0x18, 0x18, 0x18, 0x10, 0x60,

    /* U+00FE "þ" */
    0xc1, 0x83, 0x7, 0xec, 0xd8, 0xf1, 0xe3, 0xc7,
    0x8f, 0x37, 0xcc, 0x18, 0x30, 0x0,

    /* U+00FF "ÿ" */
    0x66, 0x0, 0x0, 0xc3, 0xc6, 0x66, 0x66, 0x6c,
    0x3c, 0x3c, 0x38, 0x18, 0x10, 0x30, 0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 64, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 68, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 82, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 6, .adv_w = 154, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 20, .adv_w = 146, .box_w = 8, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 36, .adv_w = 189, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 53, .adv_w = 164, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 68, .adv_w = 43, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 69, .adv_w = 89, .box_w = 5, .box_h = 17, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 80, .adv_w = 90, .box_w = 5, .box_h = 17, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 91, .adv_w = 114, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 98, .adv_w = 142, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 107, .adv_w = 57, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 109, .adv_w = 87, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 110, .adv_w = 71, .box_w = 2, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 111, .adv_w = 100, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 121, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 146, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 153, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 146, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 179, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 191, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 215, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 227, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 68, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 241, .adv_w = 61, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 244, .adv_w = 130, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 251, .adv_w = 144, .box_w = 7, .box_h = 5, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 256, .adv_w = 133, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 263, .adv_w = 125, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 274, .adv_w = 230, .box_w = 13, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 299, .adv_w = 170, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 314, .adv_w = 162, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 326, .adv_w = 167, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 340, .adv_w = 167, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 352, .adv_w = 145, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 141, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 376, .adv_w = 174, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 390, .adv_w = 182, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 73, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 407, .adv_w = 142, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 418, .adv_w = 162, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 432, .adv_w = 138, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 443, .adv_w = 224, .box_w = 12, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 461, .adv_w = 182, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 475, .adv_w = 176, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 489, .adv_w = 163, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 501, .adv_w = 176, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 517, .adv_w = 161, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 529, .adv_w = 155, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 543, .adv_w = 156, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 558, .adv_w = 168, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 572, .adv_w = 165, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 587, .adv_w = 225, .box_w = 13, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 607, .adv_w = 162, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 622, .adv_w = 156, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 637, .adv_w = 154, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 651, .adv_w = 70, .box_w = 3, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 657, .adv_w = 107, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 669, .adv_w = 70, .box_w = 4, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 677, .adv_w = 110, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 682, .adv_w = 115, .box_w = 7, .box_h = 1, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 683, .adv_w = 82, .box_w = 4, .box_h = 3, .ofs_x = 0, .ofs_y = 10},
    {.bitmap_index = 685, .adv_w = 138, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 693, .adv_w = 144, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 704, .adv_w = 134, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 713, .adv_w = 144, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 724, .adv_w = 137, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 732, .adv_w = 90, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 740, .adv_w = 145, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 752, .adv_w = 142, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 763, .adv_w = 65, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 766, .adv_w = 64, .box_w = 4, .box_h = 15, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 774, .adv_w = 134, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 786, .adv_w = 65, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 789, .adv_w = 223, .box_w = 12, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 803, .adv_w = 143, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 811, .adv_w = 145, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 820, .adv_w = 144, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 831, .adv_w = 145, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 842, .adv_w = 91, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 848, .adv_w = 132, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 856, .adv_w = 85, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 863, .adv_w = 142, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 871, .adv_w = 127, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 879, .adv_w = 190, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 892, .adv_w = 129, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 901, .adv_w = 125, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 913, .adv_w = 129, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 921, .adv_w = 85, .box_w = 5, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 932, .adv_w = 64, .box_w = 1, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 934, .adv_w = 85, .box_w = 5, .box_h = 17, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 945, .adv_w = 170, .box_w = 9, .box_h = 3, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 949, .adv_w = 64, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 950, .adv_w = 68, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 953, .adv_w = 144, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 966, .adv_w = 151, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 978, .adv_w = 180, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 991, .adv_w = 136, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1003, .adv_w = 63, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1007, .adv_w = 159, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1022, .adv_w = 114, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = 11},
    {.bitmap_index = 1023, .adv_w = 201, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1040, .adv_w = 114, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 1044, .adv_w = 124, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 1049, .adv_w = 141, .box_w = 7, .box_h = 3, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 1052, .adv_w = 87, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 1053, .adv_w = 201, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1070, .adv_w = 123, .box_w = 5, .box_h = 1, .ofs_x = 1, .ofs_y = 11},
    {.bitmap_index = 1071, .adv_w = 98, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 1073, .adv_w = 137, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1083, .adv_w = 95, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 1087, .adv_w = 95, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 1091, .adv_w = 83, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 1093, .adv_w = 152, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1104, .adv_w = 125, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1115, .adv_w = 73, .box_w = 2, .box_h = 1, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 1116, .adv_w = 66, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1118, .adv_w = 95, .box_w = 3, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 1121, .adv_w = 117, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 1125, .adv_w = 124, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 1130, .adv_w = 185, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1147, .adv_w = 196, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1163, .adv_w = 204, .box_w = 12, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1183, .adv_w = 125, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1194, .adv_w = 170, .box_w = 10, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1213, .adv_w = 170, .box_w = 10, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1232, .adv_w = 170, .box_w = 10, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1251, .adv_w = 170, .box_w = 10, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1270, .adv_w = 170, .box_w = 10, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1288, .adv_w = 170, .box_w = 10, .box_h = 16, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1308, .adv_w = 240, .box_w = 14, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1329, .adv_w = 167, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1346, .adv_w = 145, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1361, .adv_w = 145, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1376, .adv_w = 145, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1391, .adv_w = 145, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1405, .adv_w = 73, .box_w = 4, .box_h = 15, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1413, .adv_w = 73, .box_w = 4, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1421, .adv_w = 73, .box_w = 6, .box_h = 15, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1433, .adv_w = 73, .box_w = 6, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1444, .adv_w = 171, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1458, .adv_w = 182, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1475, .adv_w = 176, .box_w = 9, .box_h = 16, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1493, .adv_w = 176, .box_w = 9, .box_h = 16, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1511, .adv_w = 176, .box_w = 9, .box_h = 16, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1529, .adv_w = 176, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1546, .adv_w = 176, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1562, .adv_w = 136, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 1569, .adv_w = 176, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1584, .adv_w = 168, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1601, .adv_w = 168, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1618, .adv_w = 168, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1635, .adv_w = 168, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1651, .adv_w = 156, .box_w = 10, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1670, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1682, .adv_w = 157, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1694, .adv_w = 138, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1705, .adv_w = 138, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1716, .adv_w = 138, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1727, .adv_w = 138, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1738, .adv_w = 138, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1749, .adv_w = 138, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1761, .adv_w = 216, .box_w = 13, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1776, .adv_w = 134, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1788, .adv_w = 137, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1799, .adv_w = 137, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1810, .adv_w = 137, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1821, .adv_w = 137, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1832, .adv_w = 67, .box_w = 4, .box_h = 12, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1838, .adv_w = 67, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1844, .adv_w = 67, .box_w = 6, .box_h = 12, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1853, .adv_w = 67, .box_w = 6, .box_h = 12, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1862, .adv_w = 149, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1875, .adv_w = 143, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1886, .adv_w = 145, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1898, .adv_w = 145, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1910, .adv_w = 145, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1922, .adv_w = 145, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1934, .adv_w = 145, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1946, .adv_w = 146, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 1954, .adv_w = 145, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1965, .adv_w = 142, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1976, .adv_w = 142, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1987, .adv_w = 142, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1998, .adv_w = 142, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2009, .adv_w = 125, .box_w = 8, .box_h = 15, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 2024, .adv_w = 146, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 2038, .adv_w = 125, .box_w = 8, .box_h = 15, .ofs_x = 0, .ofs_y = -3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 160, .range_length = 96, .glyph_id_start = 96,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 1, 0, 2, 0, 0, 0, 0,
    2, 3, 0, 0, 0, 4, 0, 4,
    5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 6, 7, 8, 9, 10, 11,
    0, 12, 12, 13, 14, 15, 12, 12,
    9, 16, 17, 18, 0, 19, 13, 20,
    21, 22, 23, 24, 25, 0, 0, 0,
    0, 0, 26, 27, 28, 0, 29, 30,
    0, 31, 0, 0, 32, 0, 31, 31,
    33, 27, 0, 34, 0, 35, 0, 36,
    37, 38, 36, 39, 40, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    6, 6, 6, 6, 6, 6, 0, 8,
    10, 10, 10, 10, 12, 12, 12, 12,
    9, 12, 9, 9, 9, 9, 9, 0,
    0, 13, 13, 13, 13, 23, 0, 0,
    26, 26, 26, 26, 26, 26, 0, 28,
    29, 29, 29, 29, 0, 0, 0, 0,
    0, 31, 33, 33, 33, 33, 33, 0,
    0, 0, 0, 0, 0, 36, 27, 36
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 1, 0, 2, 0, 0, 0, 3,
    2, 0, 4, 5, 0, 6, 7, 6,
    8, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    9, 0, 10, 0, 11, 0, 0, 0,
    11, 0, 0, 12, 0, 0, 0, 0,
    11, 0, 11, 0, 13, 14, 15, 16,
    17, 18, 19, 20, 0, 0, 21, 0,
    0, 0, 22, 0, 23, 23, 23, 24,
    23, 0, 0, 0, 0, 0, 25, 25,
    26, 25, 23, 27, 28, 29, 30, 31,
    32, 33, 31, 34, 0, 0, 35, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 36, 0, 7, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 37, 0, 0, 0, 0,
    10, 10, 10, 10, 10, 10, 38, 11,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 11, 11, 11, 11, 11, 0,
    11, 15, 15, 15, 15, 19, 0, 0,
    22, 22, 22, 22, 22, 22, 39, 23,
    23, 23, 23, 23, 0, 0, 0, 0,
    0, 25, 26, 26, 26, 26, 26, 0,
    40, 30, 30, 30, 30, 31, 0, 31
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -10, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -26, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -29,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -15, 0, 0, 0, 0, 0, 0,
    -8, 0, -2, 0, 0, -16, -2, -10,
    -7, 0, -14, 0, 0, 0, 0, 0,
    -2, -1, 0, 0, -2, -1, -6, -4,
    0, 2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, -3,
    0, 0, -7, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -4, 0, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -14, 0, 0,
    0, -3, 0, 0, 0, -6, 0, -3,
    0, -3, -5, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 3, 0, 0,
    0, 0, 0, 0, 0, 0, -2, -2,
    0, -2, 0, 0, 0, -2, -3, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -31, 0, 0,
    0, -22, 0, -30, 0, 3, 0, 0,
    0, 0, 0, 0, 0, -4, -3, 0,
    0, -3, -3, 0, 0, -3, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 2, 0, 0, 0, -4, 0, 0,
    0, 2, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -13, 0,
    0, 0, -4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -3, 0,
    -2, -3, 0, 0, 0, -3, -5, -8,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 2, -8, 0, 0, -31, -5, -23,
    -16, 0, -32, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -4, -16, -10,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -44, 0, 0,
    0, -19, 0, -24, 0, 0, 0, 0,
    0, -5, 0, -4, 0, -1, -2, 0,
    0, -2, 0, 0, 2, 0, 2, 0,
    0, 0, 0, 0, 0, -21, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -5, 0, -3,
    -2, 0, -4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -9, 0, -2,
    0, 0, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -6, 0, 0, 0, 0, -29, -31, 0,
    0, -12, -3, -29, -2, 2, 0, 2,
    2, 0, 2, 0, 0, -17, -12, 0,
    -13, -17, -9, -13, 0, -10, -9, -7,
    -10, -7, 0, -33, -24, -23, -13, -12,
    0, 0, 0, 3, 0, -28, -10, 0,
    0, -9, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 2, -6, -5, 0,
    0, -6, -4, 0, 0, -3, -1, 0,
    0, 0, 2, 0, 0, 0, 0, 0,
    0, 0, 0, 2, 0, -16, -7, 0,
    0, -5, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 2, -4, -4, 0,
    0, -4, -3, 0, 0, -2, 0, 0,
    0, 0, 2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -11, 0,
    0, 0, -3, 0, 0, 0, 0, 2,
    0, 0, 0, 0, 0, 0, -3, 0,
    0, -3, 0, 0, 0, -3, -4, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -4, 3, -6, -27, -11, 0,
    0, -14, -4, -12, -2, 2, -12, 2,
    2, 2, 2, 0, 2, -9, -8, -3,
    -5, -8, -5, -7, -3, -5, -2, 0,
    -3, -4, 2, -10, -6, -12, -8, -8,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 2, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -3, 0,
    0, -3, 0, 0, 0, -2, -3, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -6, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    -2, -2, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 2, 0, 3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 2, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 2, 0, 0, 0, 0, 0,
    0, -12, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -15, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    -3, -2, 0, 0, 0, 0, 0, 0,
    0, 2, 0, 0, 0, -18, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -4, -2, 2,
    0, -3, 0, 0, 6, 0, 2, 2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 2, 0, 0, 0, -16, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, -2, 2,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -15, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    0, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 40,
    .right_class_cnt     = 40,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif

};

extern const lv_font_t lv_font_montserrat_16;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t roboto_medium_16 = {
#else
lv_font_t roboto_medium_16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 20,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .static_bitmap = 0,
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = &lv_font_montserrat_16,
#endif
    .user_data = NULL,
};



#endif /*#if ROBOTO_MEDIUM_16*/
