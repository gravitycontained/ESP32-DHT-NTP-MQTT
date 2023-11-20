#pragma once
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <WiFi.h>

namespace dateTime {
  class ntpClient {
    WiFiUDP wifiUDP;
    NTPClient ntp;

  public:
    ntpClient() : ntp(wifiUDP) {}

    void setup();
    void update();

    std::pair<String, String> getDateAndTime() const;
  };
}