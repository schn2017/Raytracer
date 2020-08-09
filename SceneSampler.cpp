#include "SceneSampler.h"

SceneSampler::SceneSampler(int imageHeight, int imageWidth)
{
  height = imageHeight;
  width = imageWidth;
  row = 0;
  column = 0;
}

Sample SceneSampler::getSample()
{
  //std::cout << "Pixel Sample: " << row << " " << column << "\n";

  float convertedColumn = (column - (width / 2)) / (width / 2);
  float convertedRow = ((height / 2) - row) / (height / 2);
  //std::cout << "Pixel Sample Converted: " << convertedRow << " " << convertedColumn << "\n";
  Sample imageSample = Sample(convertedRow, convertedColumn);
  column++;

  return imageSample;
}

bool SceneSampler::canSample()
{
  if (row > height)
  {
    return false;
  }
  else
  {
    if (column > width)
    {
      column = 0;
      row++;
    }
    return true;
  }
}

int SceneSampler::getHeight()
{
  return height;
}

int SceneSampler::getWidth()
{
  return width;
}

float SceneSampler::getRow()
{
  return row;
}

float SceneSampler::getColumn()
{
  return column;
}
