#include "Vector.h"
#include "ray.h"
using namespace chromeball;

Ray::Ray(Vector o, Vector d): origin(o), direction(d) {}
Vector Ray::get_origin() { return origin; }
Vector Ray::get_direction() { return direction; }

