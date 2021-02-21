#include "Sphere.h"
#include "Vector.h"
#include "utils.h"
#include <cmath>
using namespace chromeball;

Sphere::Sphere(const Vector &p, float r, const Color &c)
    : SceneObject{c}, position{p}, radius{r} {}

float Sphere::intersection(const Ray &r) const {
  Vector oc = r.get_position() - this->position;
  float b = 2 * (r.get_direction() * oc);
  float c = (oc * oc) - (radius * radius);

  // a = 1, so it is left out of the formula.
  float discriminant = (b * b) - (4 * c);

  if (discriminant < 0) {
    // No intersections were made.
    return -1.0f;
  } else {
    // An intersection is made! Return the smallest t value where t > 0.
    float tplus = (-b + sqrt(discriminant)) / 2.0f;
    float tminus = (-b - sqrt(discriminant)) / 2.0f;

    if (tminus > 0)
      return tminus;
    else
      return tplus;
  }
}
