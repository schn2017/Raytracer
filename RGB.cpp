#include "RGB.h"

RGB::RGB(float red, float green, float blue)
{
  if (red <= 1 && red >= 0)
  {
    R = red * 255;
  }
  else if (red > 1)
  {
    R = 255;
  }
  else{
    R = 0;
  }

  if (green <= 1 && green >= 0)
  {
    G = green * 255;
  }
  else if(green > 1)
  {
    G = 255;
  }
  else
  {
    G = 0;
  }

  if (blue <= 1 && blue >= 0)
  {
    B = blue * 255;
  }
  else if (blue > 1)
  {
    B = 255;
  }
  else
  {
    B = 0;
  }
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
  return R == otherRGB.R && G == otherRGB.G && B == otherRGB.B;

}

RGB RGB::operator+(const RGB &otherRGB)
{
  float red = R + otherRGB.R;
  float green = G + otherRGB.G;
  float blue = B + otherRGB.B;

  if (red > 255)
  {
    red = 1;
  }
  else if (red < 0)
  {
    red = 0;
  }
  else
  {
    red = red / 255;
  }

  if (green > 255)
  {
    green = 1;
  }
  else if (green < 0)
  {
    green = 0;
  }
  else
  {
    green = green / 255;
  }

  if (blue > 255)
  {
    blue = 1;
  }
  else if (blue < 0)
  {
    blue = 0;
  }
  else
  {
    blue = blue / 255;
  }

  return RGB(red, green, blue);
}

bool RGB::operator!=(const RGB &otherRGB)
{
  return *this == otherRGB;

}

RGB RGB::operator*(const float &scalar)
{
  float red = (R / 255) * scalar;
  float green = (G / 255) * scalar;
  float blue = (B / 255) * scalar;

  if (red > 1)
  {
    red = 1;
  }
  else if (red < 0)
  {
    red = 0;
  }

  if (green > 1)
  {
    green = 1;
  }
  else if (green < 0)
  {
    green = 0;
  }

  if (blue > 1)
  {
    blue = 1;
  }
  else if (blue < 0)
  {
    blue = 0;
  }

  return RGB(red, green, blue);
}

RGB RGB::operator*(const RGB &otherRGB)
{
  float red = (R / 255) * (otherRGB.R / 255);
  float green = (G / 255) * (otherRGB.G / 255);
  float blue = (B / 255) * (otherRGB.B / 255);

  if (red > 1)
  {
    red = 1;
  }
  else if (red < 0)
  {
    red = 0;
  }

  if (green > 1)
  {
    green = 1;
  }
  else if (green < 0)
  {
    green = 0;
  }

  if (blue > 1)
  {
    blue = 1;
  }
  else if (blue < 0)
  {
    blue = 0;
  }

  return RGB(red, green, blue);
}

void RGB::print()
{
  std::cout << "R: " << R << " G: " << G << " B: " << B << "\n";
}
