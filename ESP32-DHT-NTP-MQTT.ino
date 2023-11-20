/* ESP32-DHT-NTP-MQTT.ino
 * Project: ESP32-DHT-NTP-MQTT
 * Description: Program that reads data from a DHT sensor and the
 *              current time from an NTP server and sends that data
 *              to a MQTT broker in the form of a JSON file.
 *              the configuration.hpp defines the necessary parameters.
 * Author: Daniel Rabl
 * Location: Klara-Oppenheimer, Würzburg
 * Class: 11FI-4
 * Date: 2023-11-20
 *
 * GitHub: https://github.com/gravitycontained/ESP32-DHT-NTP-MQTT
 */

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
