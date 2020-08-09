#include "Sample.h"

Sample::Sample(float xPos, float yPos)
{
  x = xPos;
  y = yPos;
}

float Sample::getX()
{
  return x;
}

float Sample::getY()
{
  return y;
}
