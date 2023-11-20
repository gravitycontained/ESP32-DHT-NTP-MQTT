#pragma once
#include <Arduino.h>

namespace sensor {
  struct dhtConfig {
    std::size_t input_pin;
    std::size_t output_pin;
  };
}