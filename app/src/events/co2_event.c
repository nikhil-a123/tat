#include <zephyr/zbus/zbus.h>

#include "co2_event.h"

ZBUS_CHAN_DEFINE(co2_data_chan,
                 struct co2_event,
                 NULL,
                 NULL,
                 ZBUS_OBSERVERS_EMPTY,
                 ZBUS_MSG_INIT()
                );