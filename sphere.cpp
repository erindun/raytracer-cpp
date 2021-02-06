#include "sphere.h"
#include "Vector.h"
#include "utils.h"
#include <cmath>
#include <vector>
using namespace chromeball;

Sphere::Sphere(const Vector& ctr, float r, const Color& c)
    : SceneObject(c), center(ctr), radius(r) {}

std::vector<float> Sphere::intersect(const Ray& r) const {
  Vector a = r.get_origin() - this->center;
  float b = dot(a, r.get_direction());
  float c = dot(a, a);
  float f = pow(b, 2) + pow(this->radius, 2) - c;

  std::vector<float> intersections;

  if (f < 0.0f) {
    // No intersections were made.
    return intersections;
  }

  return std::vector<float>();
}
