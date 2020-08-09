#include "Sample.h"

class SceneSampler
{
public:
  SceneSampler(float imageHeight, float imageWidth);
  Sample getSample();
  bool hasNextSample();
  float getHeight();
  float getWidth();
  float getPixelX();
  float getPixelY();

private:
  float height;
  float width;
  float pixelX;
  float pixelY;
};
