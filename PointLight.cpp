#include "PointLight.h"
#include "Vector.h"
using namespace chromeball;

const Vector &PointLight::get_position() const { return position; }
const Color PointLight::get_color() const { return color; }
