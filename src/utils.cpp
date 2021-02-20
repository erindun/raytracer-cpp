#include "utils.h"
#include "Vector.h"
#include <cmath>
using namespace chromeball;

/** Calculates the dot product of two vectors. */
float dot(const Vector &a, const Vector &b) {
  float x = a.getX() * b.getX();
  float y = a.getY() * b.getY();
  float z = a.getZ() * b.getZ();
  return x + y + z;
}

/** Calculates the cross product of two vectors. */
Vector cross(const Vector &a, const Vector &b) {
  return Vector{a.getY() * b.getZ() - a.getZ() * b.getY(),
                a.getZ() * b.getX() - a.getX() * b.getZ(),
                a.getX() * b.getY() - a.getY() * b.getX()};
}

/** Converts degree values into radians. */
float deg_to_rad(float deg) { return deg * M_PI / 180.0f; }

/** Converts radian values into degrees. */
float rad_to_deg(float rad) { return rad * 180.0f / M_PI; }

/** Converts a 0-1 color value to its approximate hex value. */
int to_hex(double color) { return color * 255; }
