#include "Trace.h"
#include "Ray.h"
#include "SceneObject.h"
#include <map>
using namespace chromeball;

Color Trace(const Ray &r, const Scene &s) {
  std::map<float, SceneObject *> intersections;

  for (auto object : s) {
    float intersect = object->intersection(r);
    if (intersect > 0.0f)
      intersections.insert({intersect, object});
  }

  if (intersections.empty()) {
    return Color{0, 0, 0};
  } else {
    return intersections.begin()->second->get_color();
  }
}
