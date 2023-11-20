#include "configuration.hpp"
#include <WiFi.h>

namespace config {
  void configureApplication(application& app) {

    // Configure the application here:

    app.setNetworkInfo({
      .ssid = "FBIT.IoT.Router1",
      .password = "WueLoveIoT",
      .mqttIP = "192.168.101.210",
    });
    app.setDHTConfig({
      .input_pin = 4,
      .output_pin = 15
    });
    app.setMQTTLabel(
      "/ESP32-DHT-NTP-MQTT/" + WiFi.localIP().toString()
    );
    app.setTimeOffset(3600);
  }
}