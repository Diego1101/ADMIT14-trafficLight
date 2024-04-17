#include <Arduino.h>
#include "main.h"

mqtt_status connectionStatus = MS_UNINITIALIZED;

void setup() {
  Serial.begin(9600);
  pinMode(27, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);

  if (connectionStatus != MS_MQTT_CONNECTED) {
    Serial.print("Connection failed: ");
    Serial.println(connectionStatus);
  }
}

void loop() {
  connectionStatus = initMqttConnection();

  switch (connectionStatus) {
  case MS_MQTT_CONNECTED:
    digitalWrite(27, HIGH);
    digitalWrite(14, LOW);
    digitalWrite(12, LOW);
    break;

  case MS_WIFI_FAILED:
    digitalWrite(27, LOW);
    digitalWrite(14, HIGH);
    digitalWrite(12, LOW);
    break;

  case MS_MQTT_FAILED:
    digitalWrite(27, LOW);
    digitalWrite(14, LOW);
    digitalWrite(12, HIGH);
    break;
  
  default:
    break;
  }
}
