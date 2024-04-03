#include <WiFi.h>
#include <PubSubClient.h>
#include "MqttStatusType.h"

#ifndef _MQTTCLIENT_H_
#define _MQTTCLIENT_H_

class MqttClient {
    protected:
        WiFiClient wifiClient;
        PubSubClient pubSubClient(WiFiClient);

        String WIFI_SSID = "Plg";
        String WIFI_PASSWORD = "dnuW0JvW";
        int MAX_TIMEOUT = 10000;

        String MQTT_HOST = "mqtt.host.com";
        String MQTT_PORT = "1883"; 

    public:
        mqtt_status init();
};

#endif /* _MQTTCLIENT_H_ */