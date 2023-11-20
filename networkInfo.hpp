#pragma once
#include <Arduino.h>

namespace network {
  struct networkInfo {
    String ssid;
    String password;
    String mqttIP;
  };
}