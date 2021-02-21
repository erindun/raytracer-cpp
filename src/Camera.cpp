#include "Camera.h"
#include "utils.h"
#include <cmath>
#include <iostream>
using namespace chromeball;

Camera::Camera(const chromeball::Vector &p, const chromeball::Vector &vd,
               const chromeball::Vector &ud, float fov, float a)
    : position{p}, view_direction{vd}, up_direction{ud}, fov{fov}, aspect_ratio{
                                                                       a} {}

Vector Camera::get_position() const { return position; }

Vector Camera::view(float i, float j, int nx, int ny) const {
  Vector right = up_direction ^ view_direction;
  float fov_rad = fov * M_PI / 180;
  float u = ((2 * i / nx) - 1) * tanf(fov_rad / 2);
  float v = ((2 * j / ny) - 1) * (tanf(fov_rad / 2) / aspect_ratio);
  Vector x = (u * right) + (v * up_direction);

  x.normalize();
  return x;
}
