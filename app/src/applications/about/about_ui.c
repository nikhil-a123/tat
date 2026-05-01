#include "about_ui.h"
#include "assert.h"

static lv_obj_t *root_page = NULL;

static lv_obj_t *ui_fw_version;
static lv_obj_t *ui_num_applications;
static lv_obj_t *ui_hw_revision;
static lv_obj_t *ui_sdk_versions;

LV_FONT_DECLARE(roboto_medium_12);

void about_ui_show(lv_obj_t *root, char *board, char *fw_version, char *sdk_version, int num_apps)
{
    assert(root_page == NULL);

    root_page = lv_obj_create(root);
    lv_obj_set_style_border_width(root_page, 0, LV_PART_MAIN);
    lv_obj_set_size(root_page, LV_PCT(100), LV_PCT(100));
    lv_obj_set_scrollbar_mode(root_page, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_width(root_page, lv_pct(100));
    lv_obj_set_height(root_page, lv_pct(100));
    lv_obj_set_align(root_page, LV_ALIGN_CENTER);
    lv_obj_clear_flag(root_page, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    // Set up flex layout for vertical arrangement
    lv_obj_set_flex_flow(root_page, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(root_page, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_gap(root_page, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_top(root_page, 25, LV_PART_MAIN);

    // Create a container for hardware info with icon and text
    lv_obj_t *hw_container = lv_obj_create(root_page);
    lv_obj_set_size(hw_container, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_flex_flow(hw_container, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(hw_container, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_gap(hw_container, 10, LV_PART_MAIN);

    ui_hw_revision = lv_label_create(hw_container);
    lv_obj_set_width(ui_hw_revision, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_hw_revision, LV_SIZE_CONTENT);
    lv_label_set_text_fmt(ui_hw_revision, "%s", board);
    lv_obj_set_style_text_align(ui_hw_revision, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_hw_revision, &roboto_medium_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_num_applications = lv_label_create(root_page);
    lv_obj_set_width(ui_num_applications, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_num_applications, LV_SIZE_CONTENT);
    lv_label_set_text_fmt(ui_num_applications, "%d Applications", num_apps);
    lv_obj_set_style_text_align(ui_num_applications, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_num_applications, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_sdk_versions = lv_label_create(root_page);
    lv_obj_set_width(ui_sdk_versions, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_sdk_versions, LV_SIZE_CONTENT);
    lv_label_set_text(ui_sdk_versions, sdk_version);
    lv_obj_set_style_text_align(ui_sdk_versions, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_fw_version = lv_label_create(root_page);
    lv_obj_set_width(ui_fw_version, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_fw_version, LV_SIZE_CONTENT);
    lv_label_set_text(ui_fw_version, fw_version);
    lv_obj_set_style_text_align(ui_fw_version, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void about_ui_remove(void)
{
    lv_obj_del(root_page);
    root_page = NULL;
}
