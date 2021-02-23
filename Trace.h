#pragma once
#include "Ray.h"
#include "SceneObject.h"
#include "Vector.h"

chromeball::Color Trace(const Ray &r, const Scene &s);
