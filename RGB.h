#pragma once

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
private:
  float R;
  float G;
  float B;
};
