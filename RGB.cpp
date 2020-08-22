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

bool RGB::operator==(const RGB &otherRGB)
{
  return R == otherRGB.R && G == otherRGB.G && otherRGB.B;

}

RGB RGB::operator+(const RGB &otherRGB)
{
  float red = R + otherRGB.R;
  float green = G + otherRGB.G;
  float blue = B + otherRGB.B;

  return RGB(red, green, blue);
}

bool RGB::operator!=(const RGB &otherRGB)
{
  return *this == otherRGB;

}
