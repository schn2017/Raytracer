#include "RGB.h"
#include <vector>

class Pixels
{
public:
  Pixels();

  void addColor(RGB color);
  RGB getElement(int value);

private:
  std::vector<RGB> samples;
};
