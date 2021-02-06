#pragma once
#include "Vector.h"
#include "ray.h"

class SceneObject {
private:
  chromeball::Color color;

public:
  SceneObject(const chromeball::Color &c);
  virtual float intersect(const Ray &r) const = 0;
};
