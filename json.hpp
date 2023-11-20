/* 
 * Author: Daniel Rabl
 * Location: Klara-Oppenheimer, Würzburg
 * Class: 11FI-4
 * Date: 2023-11-20
 *
 * GitHub: https://github.com/gravitycontained/ESP32-DHT-NTP-MQTT
 */

#pragma once
#include <Arduino.h>
#include "dataPoint.hpp"
#include <ArduinoJson.h>

namespace data {
  
  template<std::size_t LENGTH>
  String jsonifyDataPoint(const dataPoint& dataPoint) {

    StaticJsonDocument<LENGTH> doc;

    doc["humidity"] = dataPoint.humidity;
    doc["temperature"] = dataPoint.temperature;
    doc["time"] = dataPoint.time;
    doc["date"] = dataPoint.date;
    doc["clientID"] = dataPoint.clientID;

    String json;
    serializeJson(doc, json);
    return json;
  }
}