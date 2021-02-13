#pragma once
#include "Ray.h"
#include "SceneObject.h"
#include "Vector.h"

class Plane : public SceneObject {
private:
  chromeball::Vector position;
  chromeball::Vector norm_direction;

public:
  Plane(const chromeball::Vector &p, const chromeball::Vector &d,
        const chromeball::Color &c);
  float intersection(const Ray &r) const;
};
