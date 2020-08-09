#include "Sample.h"

Sample::Sample(float xPos, float yPos)
{
  x = xPos;
  y = yPos;
}

bool Sample::hasNextSample()
{
  if (pixelX > width && pixelY > height)
  {
    return false;
  }
  else
  {
    return true;
  }
}

float Sample::getHeight()
{
  return height;
}

float Sample::getWidth()
{
  return width;
}

float Sample::getPixelX()
{
  return pixelX;
}

float Sample::getPixelY()
{
  return pixelY;
}

Sample Sample::getSample()
{
  if (pixelX > width)
  {
    pixelX = 0;
    pixelY++;
  }

  Sample imageSample = Sample(pixelX, pixelY);
  pixelX++;

  return imageSample;
}
