#include "utils.h"
#include "Vector.h"
#include <cmath>
using namespace chromeball;

/** Converts a 0-1 color value to its approximate hex value. */
int to_hex(double color) { return color * 255; }
