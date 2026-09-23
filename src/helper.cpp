#include "helper.h"

float normalize(float dim) {
  float digits = floor(log10(dim)) + 1;
  return static_cast<float>(dim/pow(10, digits));
}

float stdForm(float num) {
  float digits = floor(log10(num));
  return static_cast<float>(num/pow(10, digits));
}
