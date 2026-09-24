#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <math.h>
#include <iostream>

struct Sway {
  double current;
  double target;
  double decay;

  double operator()() {
    return target+(current - target)*exp(-decay);
  };
};

#endif
