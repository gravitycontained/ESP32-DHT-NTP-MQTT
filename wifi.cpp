#include "wifi.hpp"
#include <WiFi.h>

namespace network {
  namespace wifi {
    void connectToNetwork(const networkInfo& network) {
      WiFi.begin(network.ssid.c_str(), network.password.c_str());
    }
  }
}