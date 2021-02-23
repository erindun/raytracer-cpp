#pragma once
#include "Vector.h"

class Camera {
private:
  chromeball::Vector position;
  chromeball::Vector view_direction;
  chromeball::Vector up;
  float fov;
  float aspect;

public:
  Camera(const chromeball::Vector &p, const chromeball::Vector &vd,
         const chromeball::Vector &u, float fov, float a);
  const chromeball::Vector &get_position() const;
  const chromeball::Vector view(float x, float y) const;
};
