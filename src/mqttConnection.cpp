#include "mqttConnection.h"

// https://randomnerdtutorials.com/esp32-mqtt-publish-subscribe-arduino-ide/

// Objects
WiFiClient wifiClient;
PubSubClient pubSubClient(wifiClient);

mqtt_status initMqttConnection() {

    //If already connected only loop
    if (pubSubClient.connected()) {
        pubSubClient.loop();
        return MS_MQTT_CONNECTED;
    }

    //Connect to wifi
    mqtt_status currentStatus = connectToWiFi();
    
    if(currentStatus != MS_WIFI_CONNECTED){
        return currentStatus;
    }

    //Broker connection
    currentStatus = checkBrokerConnection();
    
    return currentStatus;
}

mqtt_status connectToWiFi() {
    int start = millis();

    //If connected return
    if (WiFi.status() == WL_CONNECTED) {
        return MS_WIFI_CONNECTED;
    }

    //Initialice WIFI interface
    if (!WiFi.begin(
                WIFI_SSID,
                WIFI_PASSWORD)) {
        Serial.println("Connection failed");
        return MS_WIFI_FAILED;
    }

    // Attempt WIfi connection until timeout 
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

    //SetUp broker configuration
    pubSubClient.setServer(MQTT_HOST.c_str(), MQTT_PORT);
    pubSubClient.setCallback(callback);

    while (!pubSubClient.connected()) {
        Serial.print("Attempting MQTT connection...");
        
        if (pubSubClient.connect(MQTT_CLIENTID.c_str(), MQTT_USER.c_str(), MQTT_PASS.c_str())) {

            // TEST: Publish
            // String topic = "channels/2493191/publish/fields/field2";
            // String data = "10";
            // pubSubClient.publish(topic.c_str(), data.c_str());

            // TEST: Subscribe
            // pubSubClient.subscribe("channels/2493191/subscribe/fields/field2");
            // pubSubClient.subscribe("channels/2493191/subscribe");
            
            Serial.println("Connected");
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
    // ToDo: Handle topic subscription
    Serial.print("Message recieved: ");
    Serial.println(String(topic));
    //Serial.println(message);
    // switch (topic) {
    //     case "Change light":
    //         //handle change light:
    //         break; 
    //     default:
    //         break;
    // }
}