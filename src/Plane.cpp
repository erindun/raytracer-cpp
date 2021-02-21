#include "Plane.h"
#include "Vector.h"
#include <cmath>
using namespace chromeball;

Plane::Plane(const Vector &p, const Vector &d, const Color &c)
    : SceneObject{c}, position{p}, norm_direction{d} {}

float Plane::intersection(const Ray &r) const {
  float dn = r.get_direction() * this->norm_direction;
  if (dn == 0) {
    // Ray is parallel to plane (no intersection).
    return -1.0f;
  } else {
    float t =
        (-(r.get_position() - this->position) * this->norm_direction) / dn;

    if (t < 0)
      // Not an intersection.
      return -1.0f;
    else
      return t;
  }
}
