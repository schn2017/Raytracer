#include "Sample.h"
#include <iostream>

class SceneSampler
{
public:
  SceneSampler(int imageHeight, int imageWidth);
  SceneSampler();
  Sample getSample();
  bool canSample();
  int getHeight();
  int getWidth();
  float getRow();
  float getColumn();
  float getAspectRatio();

private:
  int height;
  int width;
  float row;
  float column;
  float aspectRatio;
};
