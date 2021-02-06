#pragma once
#include "Vector.h"

class Ray {
private:
  chromeball::Vector origin;
  chromeball::Vector direction;

public:
  Ray(const chromeball::Vector& o, const chromeball::Vector& d);
  chromeball::Vector get_origin();
  chromeball::Vector get_direction();
};
