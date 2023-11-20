#include "configuration.hpp"

namespace config {
  void configureApplication(application& app) {
    app.setNetworkInfo({
      .ssid = "FBIT.IoT.Router1",
      .password = "WueLoveIoT",
      .mqttIP = "192.168.101.210"
    });
    app.setDHTConfig({
      .input_pin = 4,
      .output_pin = 15
    });
  }
}