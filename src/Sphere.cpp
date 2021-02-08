#include "Sphere.h"
#include "Vector.h"
#include "utils.h"
#include <cmath>
#include <vector>
using namespace chromeball;

Sphere::Sphere(const Vector &p, float r, const Color &c)
    : SceneObject{c}, position{p}, radius{r} {}

float Sphere::intersection(const Ray &r) const {
  Vector a = r.get_position() - this->position;
  float b = dot(a, r.get_direction());
  float c = dot(a, a);
  float f = pow(b, 2) + pow(this->radius, 2) - c;

  if (f < 0.0f) {
    // No intersections were made.
    return 0.0f;
  }

  return 0.0f;
}
