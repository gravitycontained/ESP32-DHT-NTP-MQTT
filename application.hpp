/* 
 * Author: Daniel Rabl
 * Location: Klara-Oppenheimer, Würzburg
 * Class: 11FI4
 * Date: 2023-11-20
 *
 * GitHub: https://github.com/gravitycontained/ESP32-DHT-NTP-MQTT
 */

#pragma once

#include "dht.hpp"
#include "ntp.hpp"
#include "mqtt.hpp"
#include "networkInfo.hpp"
#include "dhtConfig.hpp"
#include "dataPoint.hpp"

/*
 * This class is responsible for the application logic.
 * It combines the dht sensor, the NTP client and the MQTT client
 * and publishes the data to the MQTT broker in the form of a JSON file.
 */
class application {
  sensor::dhtSensor dht;
  dateTime::ntpClient ntp;
  network::mqttClient mqtt;
  network::networkInfo network;

  std::size_t lastMillis = 0;
  
  constexpr static auto SERIAL_BEGIN = 9600;
  constexpr static auto DELAY = 1000;
  constexpr static auto JSON_SIZE = 256;

public:

  void setDHTConfig(const sensor::dhtConfig& config);
  void setNetworkInfo(const network::networkInfo& network);
  void setTimeOffset(std::size_t timeOffset);
  void setMQTTLabel(String mqttLabel);

  data::dataPoint requestDataPoint();
  void publishData();

  void setup();
  void loop();
};