#include "Plane.h"
#include "Vector.h"
#include <cmath>
using namespace chromeball;

Plane::Plane(const Vector &p, const Vector &d, const Color &c)
    : SceneObject{c}, position{p}, norm_direction{d} {}

float Plane::intersection(const Ray &r) const {
  float denom = norm_direction * r.get_direction();
  if (fabs(denom) > 1e-6) {
    Vector difference = position - r.get_position();
    float t = (difference * norm_direction) / denom;

    if (t > 1e-6) {
      return t;
    }
  }

  // No intersection.
  return -1.0f;
}
