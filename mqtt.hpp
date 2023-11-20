#pragma once
#include <WiFi.h>
#include <MQTT.h>
#include "networkInfo.hpp"

namespace network {
  //this function gets triggered by onMessage events
  void messageReceived(String &topic, String &payload);

  class mqttClient {
    WiFiClient wifiClient;
    MQTTClient client;
    String ip;
    
  public:

    void connect();

    void setIP(String ip);
    String getIP() const;
    
    void setup(const network::networkInfo& network);
    void checkConnection();
    void publish(String label, String message);
    void update();
  };
}