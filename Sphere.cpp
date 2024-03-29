#include "Sphere.h"
#include "Vector.h"
#include <algorithm>
#include <cmath>
using namespace chromeball;

Sphere::Sphere(const Vector &p, float r, const Color &c)
    : SceneObject{c}, position{p}, radius{r} {}

float Sphere::intersection(const Ray &r) const {
  // position - center
  Vector pc = r.get_position() - this->position;

  float a = r.get_direction() * r.get_direction();
  float b = 2 * (r.get_direction() * pc);
  float c = (pc * pc) - (radius * radius);
  float discriminant = (b * b) - (4 * a * c);

  if (discriminant < 0) {
    // No intersections were made.
    return -1.0f;
  } else {
    // An intersection is made! Return the smallest t value where t > 0.
    float t1 = (-b + sqrt(discriminant)) / (2 * a);
    float t2 = (-b - sqrt(discriminant)) / (2 * a);

    if (t1 > 0 && t2 > 0)
      return std::min(t1, t2);
    else if (t1 > 0)
      return t1;
    else
      return t2;
  }
}
