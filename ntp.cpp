#include "ntp.hpp"

namespace dateTime {
  void ntpClient::setup() {
    Serial.println("ntpClient::setup()");
    
    while ( WiFi.status() != WL_CONNECTED ) {
      delay ( 500 );
      Serial.print ( "." );
    }

    this->ntp.begin();
    this->ntp.setTimeOffset(3600); // Set your timezone offset in seconds
  }

  void ntpClient::update() {
    this->ntp.update();
  }
  std::pair<String, String> ntpClient::getDateAndTime() const {
    unsigned long epochTime =  this->ntp.getEpochTime();
    
    time_t rawtime = (time_t)epochTime;
    struct tm *timeinfo = gmtime(&rawtime);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    String formattedDateTime = String(buffer);
    
    String date = formattedDateTime.substring(0, 10);
    String time = formattedDateTime.substring(11);
    return std::make_pair(date, time);
  }
}