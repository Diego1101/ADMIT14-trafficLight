#ifndef _MQTTSTATUSTYPE_H_
#define _MQTTSTATUSTYPE_H_

typedef enum {
    MS_UNINITIALIZED    = 0,
    MS_CONNECTED        = 1,
    MS_WIFI_FAILED      = 2,
    MS_MQTT_FAILED      = 3
} mqtt_status;

#endif /* _MQTTSTATUSTYPE_H_ */