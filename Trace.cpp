#include "Trace.h"
#include "Ray.h"
#include "SceneObject.h"
#include <limits>
#include <map>
using namespace chromeball;

Color Trace(const Ray &r, const Scene &s) {
  float tmin = std::numeric_limits<float>::infinity();
  Color c{0, 0, 0};
  for (auto obj : s) {
    float t = obj->intersection(r);
    if (t > 0 && t < tmin) {
      tmin = t;
      c = obj->get_color();
    }
  }
  return c;
}
