#pragma once
#include "Ray.h"
#include "SceneObject.h"
#include "Vector.h"
#include <vector>

class Sphere : public SceneObject {
private:
  chromeball::Vector position;
  float radius;

public:
  Sphere(const chromeball::Vector &p, float r, const chromeball::Color &c);
  float intersection(const Ray &r) const;
};
