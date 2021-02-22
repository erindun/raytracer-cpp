#include "SceneObject.h"
#include "Vector.h"
using namespace chromeball;

SceneObject::SceneObject(const Color &c) : color{c} {}
const Color SceneObject::get_color() const { return color; }
