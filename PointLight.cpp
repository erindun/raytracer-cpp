#include "PointLight.h"
#include "Vector.h"
using namespace chromeball;

PointLight::PointLight(const Vector &p, Color c) : position{p}, color{c} {}
const Vector &PointLight::get_position() const { return position; }
const Color PointLight::get_color() const { return color; }
