#include "Camera.h"
#include "ImagePlane.h"
#include "Plane.h"
#include "Ray.h"
#include "SceneObject.h"
#include "Sphere.h"
#include "Vector.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
using namespace chromeball;

const int NX = 1024;
const int NY = 768;

typedef std::vector<SceneObject *> Scene;

Color Trace(const Ray &r, const Scene &s) {
  std::map<float, SceneObject *> intersections;

  for (auto object : s) {
    float intersect = object->intersection(r);
    if (intersect > 0.0f)
      intersections.insert({intersect, object});
  }

  return Color{0, 0, 0};
  return intersections.begin()->second->get_color();
}

int main() {
  Plane plane{Vector{0.0f, 2.0f, 0.0f}, Vector{0.0f, 1.0f, 0.0f},
              Color{0, 0.5, 1}};
  Sphere sphere{Vector{1.0f, 2.0f, 15.0f}, 3.0f, Color{0.5, 1.0, 0.0}};

  Camera camera{Vector{0.0f, 0.0f, 0.0f}, Vector{0.0f, 0.0f, 1.0f},
                Vector{0.0f, 1.0f, 0.0f}, 90.0f, 1.3333f};

  ImagePlane image{NX, NY};
  Scene scene{&plane, &sphere};

  std::ofstream ppm("raytrace.ppm");
  ppm << "P3" << std::endl << NX << " " << NY << std::endl;
  ppm << 255 << std::endl;

  for (int y = 0; y < NY; y++) {
    for (int x = 0; x < NX; x++) {
      auto direction = camera.view(x, y);
      Ray ray{camera.get_position(), direction};
      Color color = Trace(ray, scene);
      image.set(x, y, color);
      ppm << image.get(x, y).r << " " << image.get(x, y).b << " "
          << image.get(x, y).b << std::endl;
    }
  }
}
