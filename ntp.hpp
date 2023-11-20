/* 
 * Author: Daniel Rabl
 * Location: Klara-Oppenheimer, Würzburg
 * Class: 11FI4
 * Date: 2023-11-20
 *
 * GitHub: https://github.com/gravitycontained/ESP32-DHT-NTP-MQTT
 */

#pragma once

#include <NTPClient.h>
#include <WiFiUdp.h>
#include <WiFi.h>

namespace dateTime {

  /*
   * This class is responsible for the NTP connection
   * It can request the date and time from the NTP server
   */
  class ntpClient {
    WiFiUDP wifiUDP;
    NTPClient ntp;
    std::size_t timeOffset = 0;

  public:
    ntpClient() : ntp(wifiUDP) {}

    void setTimeOffset(std::size_t timeOffset);
    void setup();
    void update();

    std::pair<String, String> requestTimeAndDate() const;
  };
}