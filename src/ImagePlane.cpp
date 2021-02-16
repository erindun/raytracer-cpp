#include "ImagePlane.h"
#include "Vector.h"
using namespace chromeball;

ImagePlane::ImagePlane(int nx, int ny) : nx{nx}, ny{ny} {
  data.resize(nx * ny);
}

Color ImagePlane::get(int i, int j) const { return data.at(i * nx + ny); }

void ImagePlane::set(int i, int j, const Color &c) { data.at(i * nx + ny) = c; }
