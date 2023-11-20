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

namespace network {
  struct networkInfo {
    String ssid;
    String password;
    String mqttIP;
  };
}