/* 
 * Author: Daniel Rabl
 * Location: Klara-Oppenheimer, Würzburg
 * Class: 11FI4
 * Date: 2023-11-20
 *
 * GitHub: https://github.com/gravitycontained/ESP32-DHT-NTP-MQTT
 */

#pragma once

#include <WiFi.h>
#include <MQTT.h>
#include "networkInfo.hpp"

namespace network {
  //this function gets triggered by onMessage events
  void messageReceived(String &topic, String &payload);

  /*
   * This class is responsible for the MQTT connection
   * It can publish messages to the MQTT broker
   */
  class mqttClient {
    WiFiClient wifiClient;
    MQTTClient client;
    String ip;
    String label;
    
  public:

    void connect();

    void setMQTTLabel(String mqttLabel);
    String getMQTTLabel() const;
    
    void setIP(String ip);
    String getIP() const;
    
    void setup(const network::networkInfo& network);
    void checkConnection();
    void publish(String label, String message);
    void update();
  };
}