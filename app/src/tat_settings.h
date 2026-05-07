#ifndef TAT_SETTINGS_H_
#define TAT_SETTINGS_H_

#include <inttypes.h>
#include <stdbool.h>

#define TAT_SETTINGS_PATH "settings"

typedef int32_t tat_settings_sensor_period_t;
#define TAT_SETTINGS_KEY_SENSOR_PERIOD "sensor_period"
#define TAT_SETTINGS_SENSOR_PERIOD (TAT_SETTINGS_PATH "/" TAT_SETTINGS_KEY_SENSOR_PERIOD)

typedef struct {
    uint8_t screen_index;
} tat_settings_env_screen_t;
#define TAT_SETTINGS_KEY_ENV_SCREEN "env_screen"
#define TAT_SETTINGS_ENV_SCREEN (TAT_SETTINGS_PATH "/" TAT_SETTINGS_KEY_ENV_SCREEN)

typedef bool tat_settings_dark_mode_t;
#define TAT_SETTINGS_KEY_DARK_MODE "dark_mode"
#define TAT_SETTINGS_DARK_MODE (TAT_SETTINGS_PATH "/" TAT_SETTINGS_KEY_DARK_MODE)

typedef bool tat_settings_onboarding_done_t;
#define TAT_SETTINGS_KEY_ONBOARDING_DONE "onboard"
#define TAT_SETTINGS_ONBOARDING_DONE (TAT_SETTINGS_PATH "/" TAT_SETTINGS_KEY_ONBOARDING_DONE)

#endif /* TAT_SETTINGS_H_ */