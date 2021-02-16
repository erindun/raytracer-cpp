#include "Camera.h"
using namespace chromeball;

Camera::Camera(const chromeball::Vector &p, const chromeball::Vector &vd,
               const chromeball::Vector &ud, float fov, float a)
    : position{p}, view_direction{vd}, up_direction{ud}, fov{fov}, aspect_ratio{
                                                                       a} {}

Vector Camera::view(float x, float y) const {
  // TODO
  return Vector{0.0f, 0.0f, 0.0f};
}
