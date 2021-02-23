#include "Vector.h"
#include <vector>

class PointLight {
private:
  chromeball::Vector position;
  chromeball::Color color;

public:
  const chromeball::Vector &get_position() const;
  const chromeball::Color get_color() const;
};
