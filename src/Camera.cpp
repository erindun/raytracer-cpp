#include "Camera.h"
#include "utils.h"
using namespace chromeball;

Camera::Camera(const chromeball::Vector &p, const chromeball::Vector &vd,
               const chromeball::Vector &ud, float fov, float a)
    : position{p}, view_direction{vd}, up_direction{ud}, fov{fov}, aspect_ratio{
                                                                       a} {}

Vector Camera::get_position() const { return position; }

Vector Camera::view(float x, float y) const {
  Vector right = cross(up_direction, view_direction);
  float fov_rad = deg_to_rad(fov);
  float hfov_rad = 2 * atan(tan(fov_rad) / 2 * aspect_ratio);
  float hfov = rad_to_deg(hfov_rad);
  float vfov = fov / hfov;

  // TODO
  return Vector{0, 0, 0};
}
