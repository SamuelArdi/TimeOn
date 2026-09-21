#include "helper.h"

float divideSize(int dim) {
  std::string result = "0."+std::to_string(dim);
  float converted = std::stof(result);
  converted = round(converted*10.0f)/10.0f;
  return converted;
}