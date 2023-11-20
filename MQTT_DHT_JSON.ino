// MQTT_DHT_JSON.ino by Daniel Rabl, 11Fi-4, 2023-11-17
#include "application.hpp"
#include "configuration.hpp"

application application;

void setup() {
  config::configureApplication(application);
  application.setup();
}

void loop() {
  application.loop();
}
