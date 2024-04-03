#include "mqttConnection.h"

mqtt_status MqttClient::init() {
    int start = millis();

    if (!WiFi.begin(
                MqttClient::WIFI_SSID,
                MqttClient::WIFI_PASSWORD)) {
        // Serial.println("Connection failed");
    return MS_WIFI_FAILED;
    }

    while(WiFi.status() != WL_CONNECTED) {
        // Serial.print("Current Status: ");
        // Serial.println(WiFi.status());
        if (millis() > start + MqttClient::MAX_TIMEOUT) {
            return MS_WIFI_FAILED;
        } else {
            delay(200);
        }
    }

    //ToDo: Check MQTT connection
    //  client.setServer(mqtt_server, 1883);
//   client.setCallback(callback);
// https://randomnerdtutorials.com/esp32-mqtt-publish-subscribe-arduino-ide/
    return MS_CONNECTED;
}