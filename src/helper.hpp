#ifndef HELPER_HPP
#define HELPER_HPP

#include <string>
#include <math.h>
#include <raylib.h>

// struct Element {
//   Vector2 position;
//   Vector2 dimensions;
//   float scale;
//   float rotation;

//   Element(float x, float y,
//           float w, float h,
//           float scale,
//           float rotation)
//     : position{ x, y }, dimensions{ w, h }, scale(scale), rotation(rotation) {}

//   Element(Vector2 position,
//           float w, float h,
//           float scale,
//           float rotation)
//     : position(position), dimensions{ w, h }, scale(scale), rotation(rotation) {}

//   Element(Vector2 position,
//           Vector2 dimensions,
//           float scale,
//           float rotation)
//     : position(position), dimensions(dimensions), scale(scale), rotation(rotation) {}
// };

struct Element {
  Rectangle src;
  Rectangle dest;
  Vector2 origin;
  float rotation;

  // Element(Rectangle src, Rectangle dest, Vector2 origin, float rotation)
  //   : src(src), dest(dest), origin(origin), rotation(rotation) {}
};

float normalize(float dim);
float stdForm(float num);
int getGCD(int x, int y);

// debug functions
std::string ntos(float number);

#endif
