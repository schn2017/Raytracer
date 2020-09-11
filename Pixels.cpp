#include "Pixels.h"

Pixels::Pixels(int sizeHeight, int sizeWidth)
{
  height = sizeHeight;
  width = sizeWidth;
}

Pixels::Pixels()
{
}

void Pixels::addColor(RGB color)
{
  samples.push_back(color);
}

RGB Pixels::getElement(int value)
{
  return samples[value];
}

void Pixels::printCopyRight(int height, int width)
{
  FreeImage_Initialise();
  std::cout << "FreeImage"  << FreeImage_GetVersion () << "\n" ;
  std::cout << FreeImage_GetCopyrightMessage () << "\n\n" ;
  //FIBITMAP *output = FreeImage_ConvertFromRawBits(samples, width, height, width * 3, 24, 0xFF0000, 0x00FF00, 0x0000FF, true);
  //FreeImage_Save(FIF_PNG, output, "test", 0);
  FreeImage_DeInitialise();
}

bool Pixels::createFinalImage()
{
  int byteCount = 0;
  int pixelCount = 0;
  int totalBytes = samples.size() * 3;
  bool createdFile = false;
  unsigned char  film[totalBytes];
  unsigned char * filmptr;

  filmptr = film;

  while(byteCount <= totalBytes)
  {
    RGB color = samples[pixelCount];
    film[byteCount] = color.getBlue();
    byteCount++;
    film[byteCount]= color.getGreen();
    byteCount++;
    film[byteCount]= color.getRed();
    byteCount++;
    pixelCount++;
  }

  FreeImage_Initialise();
  FIBITMAP *output = FreeImage_ConvertFromRawBits(filmptr, width, height, width * 3, 24, 0xFF0000, 0x00FF00, 0x0000FF, true);
  createdFile = FreeImage_Save(FIF_PNG, output, "test.png", 0);
  FreeImage_DeInitialise();

  return createdFile;
}
