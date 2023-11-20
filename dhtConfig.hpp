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

namespace sensor {
  /*
   * This struct is used to configure the DHT sensor pins.
   */
  struct dhtConfig {
    std::size_t input_pin;
    std::size_t output_pin;
  };
}