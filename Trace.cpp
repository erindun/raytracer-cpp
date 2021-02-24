#include "Trace.h"
#include "Ray.h"
#include "SceneObject.h"
#include <map>
using namespace chromeball;

Color Trace(const Ray &r, const Scene &s) {
  float tmin = 1e20;
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
