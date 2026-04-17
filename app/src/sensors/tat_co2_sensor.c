#include <zephyr/logging/log.h>
#include <zephyr/zbus/zbus.h>

#include "tat_periodic_event.h"
#include "co2_event.h"
#include "tat_co2_sensor.h"

// For testing below
#include <zephyr/random/random.h>

static uint32_t conc = 800;
static float temp = 20.0f;
static float humid = 50.0f;

LOG_MODULE_REGISTER(tat_co2_sensor, CONFIG_TAT_SENSORS_LOG_LEVEL);

static void zbus_periodic_10s_callback(const struct zbus_channel *chan);

ZBUS_CHAN_DECLARE(co2_data_chan);
ZBUS_CHAN_DECLARE(periodic_event_10s_chan);
ZBUS_LISTENER_DEFINE(co2_sensor_periodic_slow_lis, zbus_periodic_10s_callback);

/*
 *  To get the STCC4 to read at optimal accuracy, these steps are followed:
 *      - Prompt the user to take the device outside and press a button when done so
 *      - Turn on the sensor, execute the perform conditioning command and wait 22 seconds
 *        for the conditioning to finish
 *      - Operate the sensor in continuous mode for 30 seconds, then stop the measurement
 *      - Execute the perform forced recalibration command with the target CO2 level set
 *        as the standard outside ambient CO2 concentration of ~430ppm
 *        (note the 430ppm value is rising over time, maybe make this value a settable option?)
 *      - Calibration is finished and the sensor is considered calibrated
 * 
 *  Note that the STCC4 uses an automatic self-calibration feature where the device is expected
 *  to be subjected to ambient CO2 levels at least once a week. We should prompt the user to
 *  calibrate the sensor again after a certain amount of time just to make sure, but this can
 *  be implemented at a later date.
*/

static void zbus_periodic_10s_callback(const struct zbus_channel *chan)
{
    LOG_INF("Read CO2 sensor!");

    // Get 1 or -1
    int32_t dir = 1 + ((sys_rand32_get() % 2) * -2);
    // Add a number between -20 to 20 to current CO2 concentration
    conc += ((sys_rand32_get() % 20) * dir);

    // Add a number between -1C to 1C to current temperature
    dir = 1 + ((sys_rand32_get() % 2) * -2);
    temp += ((((float)(sys_rand32_get() % 100)) / 100.0f) * dir);

    // Add a number between -1% to 1% to current humidity
    dir = 1 + ((sys_rand32_get() % 2) * -2);
    humid += ((((float)(sys_rand32_get() % 100)) / 100.0f) * dir);

    struct co2_event evt = {
        .co2_ppm = conc,
        .temperature_cel = temp,
        .rel_humidity_pct = humid
    };

    //LOG_INF("CO2 concentration: %d ppm, Temperature: %f C, Humidity: %f%", conc, (float)temp, (float)humid);
    zbus_chan_pub(&co2_data_chan, &evt, K_MSEC(250));
}

int tat_co2_sensor_init(void)
{
    tat_periodic_chan_add_obs(&periodic_event_10s_chan, &co2_sensor_periodic_slow_lis);

    return 0;
}