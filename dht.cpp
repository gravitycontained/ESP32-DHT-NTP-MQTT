#include "dht.hpp"

namespace sensor {

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  void dhtSensor::setConfig(const sensor::dhtConfig& config) {
    this->config = config;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  void dhtSensor::setup() {
    Serial.println("dhtSensor::setup()");

    this->dht.begin();

    pinMode(this->config.output_pin, OUTPUT);
    digitalWrite(this->config.output_pin, HIGH);
    pinMode(this->config.input_pin, INPUT);
  }

  // request methods
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  float dhtSensor::requestHumidity() {
    return this->dht.readHumidity();
  }
  float dhtSensor::requestTemperature() {
    return this->dht.readTemperature();
  }
  std::pair<float, float> dhtSensor::requestData() {
    return std::make_pair(
      this->requestHumidity(),
      this->requestTemperature()
    );
  }
}
