#include "application.hpp"
#include "wifi.hpp"
#include "json.hpp"

// configuration of the application
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
void application::setDHTConfig(const sensor::dhtConfig& config) {
  this->dht.setConfig(config);
}
void application::setNetworkInfo(const network::networkInfo& network) {
  this->network = network;
}
void application::setTimeOffset(std::size_t timeOffset) {
  this->ntp.setTimeOffset(timeOffset);
}
void application::setMQTTLabel(String mqttLabel) {
  this->mqtt.setMQTTLabel(mqttLabel);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
data::dataPoint application::requestDataPoint() {
  auto [humidity, temperature] = this->dht.requestData();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return {};
  }

  this->ntp.update();
  auto [time, date] = this->ntp.requestTimeAndDate();

  return data::dataPoint{
    .humidity = humidity,
    .temperature = temperature,
    .time = time,
    .date = date,
    .clientID = WiFi.localIP().toString()
  };
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
void application::publishData() {
  auto dataPoint = this->requestDataPoint();
  if (dataPoint.empty()) {
    return;
  }

  auto jsonString = data::jsonifyDataPoint<JSON_SIZE>(dataPoint);
  Serial.println(jsonString);

  this->mqtt.publish(this->mqtt.getMQTTLabel(), jsonString);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
void application::setup() {
  Serial.begin(this->SERIAL_BEGIN);

  this->dht.setup();

  network::wifi::connectToNetwork(this->network);

  this->ntp.setup();

  this->mqtt.setup(this->network);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
void application::loop() {
  this->mqtt.update();
  delay(this->DELAY); 

  this->mqtt.checkConnection();

  if (millis() - this->lastMillis > this->DELAY) {
    this->publishData();
    this->lastMillis = millis();
  }
}