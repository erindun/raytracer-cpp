#pragma once
#include "Vector.h"

class Camera {
private:
  chromeball::Vector position;
  chromeball::Vector view_direction;
  chromeball::Vector up_direction;
  float fov;
  float aspect_ratio;

public:
  Camera(const chromeball::Vector &p, const chromeball::Vector &vd,
         const chromeball::Vector &ud, float fov, float a);
  chromeball::Vector get_position() const;
  chromeball::Vector view(float x, float y, int nx, int ny) const;
};
