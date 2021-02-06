#pragma once
#include "Vector.h"
#include "scene_object.h"

class Sphere: public SceneObject {
    private:
        chromeball::Vector center;
        float radius;
    
    public:
        Sphere(
            const chromeball::Vector& ctr,
            float r,
            const chromeball::Color& c
        );
        float intersect(const Ray& r) const;
};

