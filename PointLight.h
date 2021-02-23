#pragma once
#include "Vector.h"
#include <vector>

class PointLight {
private:
  chromeball::Vector position;
  chromeball::Color color;

public:
  PointLight(const chromeball::Vector &p, chromeball::Color c);
  const chromeball::Vector &get_position() const;
  const chromeball::Color get_color() const;
};
