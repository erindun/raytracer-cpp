#include "Camera.h"
#include "ImagePlane.h"
#include "Plane.h"
#include "PointLight.h"
#include "Ray.h"
#include "SceneObject.h"
#include "Sphere.h"
#include "Trace.h"
#include "Vector.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
using namespace chromeball;

const int NX = 1024;
const int NY = 768;

int to_hex(double color) { return color * 255; }

int main() {
  Plane plane0{Vector{0.0f, 2.0f, 0.0f}, Vector{0.0f, -1.0f, 0.0f},
               Color{1, 1, 1}};
  Plane plane1{Vector{0.0f, -2.0f, 0.0f}, Vector{0.0f, 1.0f, 0.0f},
               Color{1, 1, 1}};
  Plane plane2{Vector{-2.0f, 0.0f, 0.0f}, Vector{1.0f, 0.0f, 0.0f},
               Color{1, 0, 0}};
  Plane plane3{Vector{2.0f, 0.0f, 0.0f}, Vector{-1.0f, 0.0f, 0.0f},
               Color{0, 1, 0}};
  Plane plane4{Vector{0.0f, 0.0f, 10.0f}, Vector{0.0f, 0.0f, -1.0f},
               Color{1, 1, 1}};
  Sphere sphere{Vector{1.1f, 1.25f, 7.0f}, 1.0f, Color{0.5, 0.5, 0.5}};

  Camera camera{Vector{0.0f, 0.0f, 0.0f}, Vector{0.0f, 0.0f, 1.0f},
                Vector{0.0f, 1.0f, 0.0f}, 90.0f, 1.3333f};

  PointLight light{Vector{-1.0f, -1.0f, 7.0f}, Color{2, 2, 2}};

  ImagePlane image{NX, NY};
  Scene scene{&plane0, &plane1, &plane2, &plane3, &plane4, &sphere};

  std::ofstream ppm("output.ppm");
  ppm << "P3" << std::endl << NX << " " << NY << std::endl;
  ppm << 255 << std::endl;

  for (float j = 0; j < NY; j++) {
    for (float i = 0; i < NX; i++) {
      float x = i / NX;
      float y = j / NY;
      Vector direction = camera.view(x, y);
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
