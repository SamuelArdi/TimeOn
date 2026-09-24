#include "helper.hpp"

float normalize(float dim) {
  float digits = (float)(floor(log10(dim)) + 1);
  return static_cast<float>(dim/pow(10, digits));
}

float stdForm(float num) {
  float digits = (float)(floor(log10(num)));
  return static_cast<float>(num/pow(10, digits));
}

int getGCD(int x, int y) {
  int remainder = x%y; // 840

  while (remainder != 0) {
    int result = y%remainder; // 1080 % 840 = 240
    y = remainder;
    remainder = result;
  }

  return y;
}

// debug functions
std::string ntos(float number) {
  return std::to_string(number);
}
