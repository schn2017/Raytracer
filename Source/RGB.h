#pragma once
#include <iostream>
#include <string>
class RGB
{
public:
  RGB(float red, float green, float blue);
  RGB();
  float getRed();
  float getGreen();
  float getBlue();

  bool operator==(const RGB &otherRGB);
  RGB operator+(const RGB &otherRGB);
  bool operator!=(const RGB &otherRGB);
  RGB operator*(const float &scalar);
  RGB operator*(const RGB &otherRGB);
  std::string toString();
private:
  float R;
  float G;
  float B;
};
