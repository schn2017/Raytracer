class RGB
{
public:
  RGB(float red, float green, float blue);
  RGB();
  float getRed();
  float getGreen();
  float getBlue();

  RGB operator+(const RGB &otherRGB)
  {
    float red = R + otherRGB.R;
    float green = G + otherRGB.G;
    float blue = B + otherRGB.B;

    return RGB(red, green, blue);
  }

private:
  float R;
  float G;
  float B;
};
