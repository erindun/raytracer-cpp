#include "Camera.h"
#include "utils.h"
using namespace chromeball;

Camera::Camera(const chromeball::Vector &p, const chromeball::Vector &vd,
               const chromeball::Vector &ud, float fov, float a)
    : position{p}, view_direction{vd}, up_direction{ud}, fov{fov}, aspect_ratio{
                                                                       a} {}

Vector Camera::get_position() const { return position; }

Vector Camera::view(float x, float y, int nx, int ny) const {
  Vector right = cross(up_direction, view_direction);
  float fov_rad = deg_to_rad(fov);
  float hfov_rad = 2 * atanf(tanf(fov_rad) / 2 * aspect_ratio);
  float hfov = rad_to_deg(hfov_rad);
  float vfov = fov / hfov;
  float u = (x / nx - 1) * tanf(hfov / 2);
  float v = (y / ny - 1) * tanf(vfov / 2);
  Vector vx = u * right + v * up_direction;

  Vector dir = (vx + view_direction) / (vx + view_direction).magnitude();
  return dir;
}
