#include "RGB.h"

RGB::RGB(float red, float green, float blue)
{
  R = red;
  G = green;
  B = blue;
}

RGB::RGB()
{
  
}

float RGB::getRed()
{
  return R;
}

float RGB::getGreen()
{
  return G;
}

float RGB::getBlue()
{
  return B;
}
