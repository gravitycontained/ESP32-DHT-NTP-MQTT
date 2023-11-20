#pragma once
#include "DHT.h"
#include "dhtConfig.hpp"
#include <tuple>

namespace sensor {
  constexpr auto DHTPIN = 4;
  constexpr auto DHTTYPE = DHT11;

  class dhtSensor {
    DHT dht;
    dhtConfig config;
    
  public:

    dhtSensor() : dht(DHTPIN, DHTTYPE) {}

    void setConfig(const sensor::dhtConfig& config);
    void setup();
    float requestHumidity();
    float requestTemperature();
    std::pair<float, float> requestData();
  };
}