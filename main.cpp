#include <iostream>
#include "Vector.h"
#include "ray.h"
using namespace chromeball;

int main() {
    Vector v;
    Vector w;
    Ray r(v, w);
    std::cout << r.get_origin().getX() << std::endl;
}

