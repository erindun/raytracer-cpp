#pragma once
#include "Ray.h"
#include "Vector.h"

class SceneObject {
private:
  chromeball::Color color;

public:
  SceneObject(const chromeball::Color &c);
  const chromeball::Color get_color() const;
  virtual float intersection(const Ray &r) const = 0;
};
