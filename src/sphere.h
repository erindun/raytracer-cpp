#pragma once
#include "Vector.h"
#include "scene_object.h"
#include <vector>

class Sphere : public SceneObject {
private:
  chromeball::Vector origin;
  float radius;

public:
  Sphere(const chromeball::Vector &o, float r, const chromeball::Color &c);
  float intersect(const Ray &r) const;
};
