#pragma once
#include "Vector.h"

class Ray {
private:
  chromeball::Vector position;
  chromeball::Vector direction;

public:
  Ray(const chromeball::Vector &p, const chromeball::Vector &d);
  const chromeball::Vector get_position() const;
  const chromeball::Vector get_direction() const;
};
