#include "Vector.h"

class ImagePlane {
private:
  chromeball::Vector nx, ny;
  chromeball::Color *data;

public:
  chromeball::Color get(int i, int j) const;
  void set(int i, int j, const chromeball::Color &c);
};
