#pragma once
#include "Vector.h"

float dot(const chromeball::Vector &a, const chromeball::Vector &b);
chromeball::Vector cross(const chromeball::Vector &a,
                         const chromeball::Vector &b);
float deg_to_rad(float deg);
float rad_to_deg(float rad);

int to_hex(double color);
