#include "Camera.h"
#include <cmath>
using namespace chromeball;

Camera::Camera(const chromeball::Vector &p, const chromeball::Vector &v,
               const chromeball::Vector &u, float fov, float a)
    : position{p}, view_direction{v}, up{u}, fov{fov}, aspect{a} {}

Vector Camera::get_position() const { return position; }

Vector Camera::view(float x, float y) const {
  Vector right = up ^ view_direction;
  float fov_rad = fov * M_PI / 180;

  float u = ((2 * x) - 1) * tanf(fov_rad / 2);
  float v = ((2 * y) - 1) * (tanf(fov_rad / 2) / aspect);
  Vector vx = (u * right) + (v * up);
  Vector np = vx + view_direction;
  np.normalize();

  return np;
}
