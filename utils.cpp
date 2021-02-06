#include "utils.h"
#include "Vector.h"
using namespace chromeball;

/* Calculates the dot product of two vectors. */
float dot(const Vector& a, const Vector& b) {
  float x = a.getX() * b.getX();
  float y = a.getY() * b.getY();
  float z = a.getZ() * b.getZ();
  return x + y + z;
}
