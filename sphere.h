#pragma once
#include "Vector.h"
#include "scene_object.h"
#include <vector>

class Sphere : public SceneObject {
private:
  chromeball::Vector center;
  float radius;

public:
  Sphere(const chromeball::Vector& ctr, float r, const chromeball::Color& c);
  std::vector<float> intersect(const Ray& r) const;
};
