#include "Pixels.h"

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
