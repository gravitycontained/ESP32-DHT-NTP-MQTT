#include "mqtt.hpp"

namespace network {
  void messageReceived(String &topic, String &payload) {
    Serial.println("incoming: " + topic + " - " + payload);

    // Note: Do not use the client in the callback to publish, subscribe or
    // unsubscribe as it may cause deadlocks when other things arrive while
    // sending and receiving acknowledgments. Instead, change a global variable,
    // or push to a queue and handle it in the loop after calling `client.loop()`.
  }

  void mqttClient::connect() {
    Serial.print("checking WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(1000);
    }

    Serial.print("\nconnecting...");
    while (!this->client.connect("arduino", "public", "public")) {
      Serial.print(".");
      delay(1000);
    }

    Serial.println("\nconnected!");
  }

  void mqttClient::setIP(String ip) {
    this->ip = ip;
  }
  String mqttClient::getIP() const {
    return this->ip;
  }

  void mqttClient::setup(const network::networkInfo& network) {
    Serial.println("mqttClient::setup()");

    this->setIP(network.mqttIP);

    this->client.begin(this->ip.c_str(), this->wifiClient);
    this->client.onMessage(messageReceived);

    this->connect();
  }
  void mqttClient::checkConnection() {
    if (!this->client.connected()) {
      this->connect();
    }
  }
  void mqttClient::publish(String label, String message) {
    this->client.publish(label, message);
  }
  void mqttClient::update() {
    this->client.loop();
  }
}