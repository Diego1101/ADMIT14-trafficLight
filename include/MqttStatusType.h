#pragma once

#ifndef _MQTTSTATUSTYPE_H_
#define _MQTTSTATUSTYPE_H_

typedef enum {
    MS_UNINITIALIZED    = 0,
    MS_CONNECTING       = 1,
    MS_WIFI_CONNECTED   = 2,
    MS_WIFI_FAILED      = 3,
    MS_MQTT_FAILED      = 4,
    MS_MQTT_CONNECTED   = 5
} mqtt_status;

#endif /* _MQTTSTATUSTYPE_H_ */