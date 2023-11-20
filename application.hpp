#include "dht.hpp"
#include "ntp.hpp"
#include "mqtt.hpp"
#include "networkInfo.hpp"
#include "dhtConfig.hpp"
#include <ArduinoJson.h>

class application {
  sensor::dhtSensor dht;
  dateTime::ntpClient ntp;
  network::mqttClient mqtt;
  network::networkInfo network;

  std::size_t lastMillis = 0;
public:

  void setDHTConfig(const sensor::dhtConfig& config);
  void setNetworkInfo(const network::networkInfo& network);
  void setDHTInfo();

  void setup();
  void loop();
  
  String getDataJson();
};