#include "Plane.h"
#include "Vector.h"
#include "utils.h"
#include <cmath>
using namespace chromeball;

Plane::Plane(const Vector &p, const Vector &d, const Color &c)
    : SceneObject{c}, position{p}, norm_direction{d} {}

float Plane::intersection(const Ray &r) const {
  // TODO
  return 0.0f;
}
