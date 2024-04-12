#include "mqttConnection.h"

// https://randomnerdtutorials.com/esp32-mqtt-publish-subscribe-arduino-ide/

// Objects
WiFiClient wifiClient;
PubSubClient pubSubClient(wifiClient);

mqtt_status initMqttConnection() {

    //Connect to wifi
    mqtt_status currentStatus = connectToWiFi();
    
    if(currentStatus != MS_WIFI_CONNECTED){
        return currentStatus;
    }

    //SetUp broker configuration
    pubSubClient.setServer(MQTT_HOST.c_str(), MQTT_PORT);
    pubSubClient.setCallback(callback);

    //Broker connection
    currentStatus = checkBrokerConnection();
    if(currentStatus == MS_MQTT_CONNECTED){
        // Subscribe
        // pubSubClient.subscribe("esp32/output");
    } 

    return currentStatus;
}

mqtt_status connectToWiFi() {
    int start = millis();

    if (!WiFi.begin(
                WIFI_SSID,
                WIFI_PASSWORD)) {
        Serial.println("Connection failed");
    return MS_WIFI_FAILED;
    }

    while(WiFi.status() != WL_CONNECTED) {
        Serial.println("Attempting WIFI connection...");
        if (millis() > start + MAX_TIMEOUT) {
            return MS_WIFI_FAILED;
        } else {
            Serial.print("Current Status: ");
            Serial.println(WiFi.status());
            delay(RETRY_DELAY);
        }
    }
    Serial.println("WIFI connected");
    return MS_WIFI_CONNECTED;
}

mqtt_status checkBrokerConnection() {
    int start = millis();

    while (!pubSubClient.connected()) {
        Serial.print("Attempting MQTT connection...");
        
        if (pubSubClient.connect("wifiClient")) {
          Serial.println("connected");
          return MS_MQTT_CONNECTED;
          
        }
        
        Serial.print("MQTT failed, rc=");
        Serial.println(pubSubClient.state());
        
        if (millis() > start + MAX_TIMEOUT) {
            return MS_MQTT_FAILED;
        } else {
            delay(RETRY_DELAY);
        }
    }
    return MS_WIFI_CONNECTED;
}

void callback(char* topic, byte* message, unsigned int length) {
    // Todo: Handle topic subscription
    Serial.println(topic);
    // switch (topic) {
    //     case "Change light":
    //         //handle change lighr:
    //         break; 
    //     default:
    //         break;
    // }
}