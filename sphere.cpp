#include "sphere.h"
#include "Vector.h"
using namespace chromeball;

Sphere::Sphere(const Vector& ctr, float r, const Color& c)
    : SceneObject(c), center(ctr), radius(r) {}

float Sphere::intersect(const Ray& r) const {
  // TODO
  return 0.0;
}
