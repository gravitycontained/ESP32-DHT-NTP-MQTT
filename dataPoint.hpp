/* 
 * Author: Daniel Rabl
 * Location: Klara-Oppenheimer, Würzburg
 * Class: 11FI4
 * Date: 2023-11-20
 *
 * GitHub: https://github.com/gravitycontained/ESP32-DHT-NTP-MQTT
 */

#pragma once
#include <Arduino.h>

namespace data {
  struct dataPoint {
    float humidity;
    float temperature;
    String time;
    String date;
    String clientID;

    dataPoint(float humidity = 0, float temperature = 0, String time = "", String date = "", String clientID = "") :
      humidity(humidity), temperature(temperature), time(time), date(date), clientID(clientID) {}

    bool empty() const {
      return this->clientID == "";
    }
  };
}