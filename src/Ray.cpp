#include "ray.h"
#include "Vector.h"
using namespace chromeball;

Ray::Ray(const Vector &o, const Vector &d) : origin(o), direction(d) {}
Vector Ray::get_origin() const { return origin; }
Vector Ray::get_direction() const { return direction; }
