#include "SceneSampler.h"

SceneSampler::SceneSampler(float imageHeight, float imageWidth)
{
  height = imageHeight;
  width = imageWidth;
  pixelX = 0;
  pixelY = 0;
}

void SceneSampler::getSample()
{
  if (pixelX == width)
  {
    pixelX = 0;
    pixelY++;
  }
}
