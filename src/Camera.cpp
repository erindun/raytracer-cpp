#include "Camera.h"
#include <cmath>
using namespace chromeball;

Camera::Camera(const chromeball::Vector &p, const chromeball::Vector &vd,
               const chromeball::Vector &ud, float fov, float a)
    : position{p}, view_direction{vd}, up_direction{ud}, fov{fov}, aspect_ratio{
                                                                       a} {}

Vector Camera::get_position() const { return position; }

Vector Camera::view(float x, float y) const {
  Vector right = up_direction ^ view_direction;
  float fov_rad = fov * M_PI / 180;
  float u = ((2 * x) - 1) * tanf(fov_rad / 2);
  float v = ((2 * y) - 1) * (tanf(fov_rad / 2) / aspect_ratio);
  Vector vx = (u * right) + (v * up_direction);

  if (vx.magnitude() != 0.0) {
    // wrap in if-block to prevent any `nan` errors
    vx.normalize();
  }

  return vx;
}
