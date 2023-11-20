#include "application.hpp"
#include "wifi.hpp"

void application::setDHTConfig(const sensor::dhtConfig& config) {
  this->dht.setConfig(config);
}
void application::setNetworkInfo(const network::networkInfo& network) {
  this->network = network;
}

void application::setup() {
  Serial.begin(9600);

  this->dht.setup();

  network::wifi::connectToNetwork(this->network);

  this->ntp.setup();

  this->mqtt.setup(this->network);
}
void application::loop() {
  this->mqtt.update();
  delay(1000);  // <- fixes some issues with WiFi stability

  this->mqtt.checkConnection();

  if (millis() - this->lastMillis > 1000) {
    String str = this->getDataJson();
    Serial.println(str);

    String label = "/DHT/" + WiFi.localIP().toString();
    this->mqtt.publish(label, str);
  }
}

String application::getDataJson() {

  auto [humidity, temperature] = this->dht.requestData();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return "";
  }

  this->ntp.update();
  auto [date, time] = this->ntp.getDateAndTime();

  DynamicJsonDocument doc(256);
  doc["temp"] = temperature;
  doc["humidity"] = humidity;
  doc["time"] = time;
  doc["date"] = date;
  doc["clientid"] = WiFi.localIP();

  String jsonString;
  serializeJson(doc, jsonString);
  return jsonString;
}