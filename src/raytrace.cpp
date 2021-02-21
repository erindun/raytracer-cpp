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

int to_hex(double color) { return color * 255; }

Color Trace(const Ray &r, const Scene &s) {
  std::map<float, SceneObject *> intersections;

  for (auto object : s) {
    float intersect = object->intersection(r);
    if (intersect > 0.0f)
      intersections.insert({intersect, object});
  }

  return intersections.begin()->second->get_color();
}

int main() {
  Plane plane{Vector{0.0f, 2.0f, 0.0f}, Vector{0.0f, 1.0f, 0.0f},
              Color{0, 0.5, 1}};
  Sphere sphere{Vector{1.0f, 2.0f, 15.0f}, 3.0f, Color{0.5, 1.0, 0.0}};

  Camera camera{Vector{0.0f, 0.0f, 0.0f}, Vector{0.0f, 0.0f, 1.0f},
                Vector{0.0f, 1.0f, 0.0f}, 90.0f, 1.3333f};

  ImagePlane image{NX, NY};
  Scene scene{&sphere, &plane};

  std::ofstream ppm("raytrace.ppm");
  ppm << "P3" << std::endl << NX << " " << NY << std::endl;
  ppm << 255 << std::endl;

  for (float j = 0; j < NY; j++) {
    for (float i = 0; i < NX; i++) {
      auto direction = camera.view(i, j, NX, NY);
      Ray ray{camera.get_position(), direction};
      Color color = Trace(ray, scene);
      image.set(i, j, color);
      auto red = to_hex(image.get(i, j).r);
      auto green = to_hex(image.get(i, j).g);
      auto blue = to_hex(image.get(i, j).b);
      ppm << red << " " << green << " " << blue << std::endl;
    }
  }
}
