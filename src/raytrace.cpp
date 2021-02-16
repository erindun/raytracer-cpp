#include "Camera.h"
#include "ImagePlane.h"
#include "Plane.h"
#include "SceneObject.h"
#include "Sphere.h"
#include "Vector.h"
#include <iostream>
#include <vector>
using namespace chromeball;

typedef std::vector<SceneObject *> Scene;

Color Trace(const Ray &r, const Scene &s) {
  // TODO
  return Color{0, 0, 0};
}

int main() {
  // TODO
  Plane plane{Vector{0.0f, 2.0f, 0.0f}, Vector{0.0f, 1.0f, 0.0f},
              Color{0, 0.5, 1}};
  Sphere sphere{Vector{1.0f, 2.0f, 15.0f}, 3.0f, Color{0.5, 1.0, 0.0}};

  Camera camera{Vector{0.0f, 0.0f, 0.0f}, Vector{0.0f, 0.0f, 1.0f},
                Vector{0.0f, 1.0f, 0.0f}, 90.f, 1.3333f};

  ImagePlane image{1024, 768};
  Scene scene{&plane, &sphere};
}
