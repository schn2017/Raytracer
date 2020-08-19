#include "FreeImage.h"
#include "RGB.h"
#include <vector>
#include <iostream>

class Pixels
{
public:
  Pixels(int sizeHeight, int sizeWidth);
  Pixels();

  void addColor(RGB color);
  RGB getElement(int value);
  void printCopyRight(int height, int width);
  bool createFinalImage();

private:
  std::vector<RGB> samples;
  int height;
  int width;
};
