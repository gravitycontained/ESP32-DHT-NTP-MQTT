/* 
 * Author: Daniel Rabl
 * Location: Klara-Oppenheimer, Würzburg
 * Class: 11FI4
 * Date: 2023-11-20
 *
 * GitHub: https://github.com/gravitycontained/ESP32-DHT-NTP-MQTT
 */

#pragma once
#include "DHT.h"
#include "dhtConfig.hpp"
#include <tuple>

namespace sensor {

  /*
   * This class is responsible for the DHT sensor connection
   * It can request the humidity and the temperature from the sensor
   */
  class dhtSensor {
    DHT dht;
    dhtConfig config;

    constexpr static auto DHTPIN = 4;
    constexpr static auto DHTTYPE = DHT11;
    
  public:

    dhtSensor() : dht(DHTPIN, DHTTYPE) {}

    void setConfig(const sensor::dhtConfig& config);
    void setup();
    float requestHumidity();
    float requestTemperature();
    std::pair<float, float> requestData();
  };
}