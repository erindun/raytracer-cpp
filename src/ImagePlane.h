#include "Vector.h"
#include <vector>

class ImagePlane {
private:
  int nx, ny;
  std::vector<chromeball::Color> data;

public:
  ImagePlane(int nx, int ny);
  chromeball::Color get(int i, int j) const;
  void set(int i, int j, const chromeball::Color &c);
};
