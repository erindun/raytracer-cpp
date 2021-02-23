#include "Ray.h"
#include "Vector.h"
using namespace chromeball;

Ray::Ray(const Vector &p, const Vector &d) : position{p}, direction{d} {}
const Vector &Ray::get_position() const { return position; }
const Vector &Ray::get_direction() const { return direction; }
