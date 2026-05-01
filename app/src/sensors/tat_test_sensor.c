#include <zephyr/logging/log.h>
#include <zephyr/zbus/zbus.h>

#include "tat_periodic_event.h"
#include "tat_test_sensor.h"

LOG_MODULE_REGISTER(tat_test_sensor, CONFIG_TAT_SENSORS_LOG_LEVEL);

static void zbus_periodic_10s_callback(const struct zbus_channel *chan);

ZBUS_CHAN_DECLARE(periodic_event_10s_chan);
ZBUS_LISTENER_DEFINE(test_sensor_periodic_slow_lis, zbus_periodic_10s_callback);

static void zbus_periodic_10s_callback(const struct zbus_channel *chan)
{
    LOG_INF("Hello from periodic slow callback!");
}

int tat_test_sensor_init(void)
{
    tat_periodic_chan_add_obs(&periodic_event_10s_chan, &test_sensor_periodic_slow_lis);

    return 0;
}