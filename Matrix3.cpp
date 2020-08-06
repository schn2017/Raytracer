#include "Matrix3.h"
#include <iostream>

Matrix3::Matrix3(float r0x, float r0y, float r0z,
                 float r1x, float r1y, float r1z,
                 float r2x, float r2y, float r2z)
{
  elements[0] = r0x;
  elements[1] = r0y;
  elements[2] = r0z;
  elements[3] = r1x;
  elements[4] = r1y;
  elements[5] = r1z;
  elements[6] = r2x;
  elements[7] = r2y;
  elements[8] = r2z;
}

Matrix3::Matrix3()
{
  for (int i = 0; i < 9; i++)
  {
    elements[i] = 0;
  }
}


bool Matrix3::isEqual(Matrix3 other)
{
  for (int i = 0; i < 9; i++)
  {
    if(elements[i] != other.getElements()[i])
    {
      return false;
    }
  }

  return true;
}

float * Matrix3::getElements()
{
  float *matrix = elements;

  return matrix;

}

void Matrix3::setElement(int elementNumber, float value)
{
  elements[elementNumber] = value;
}

void Matrix3::print()
{
  for (int i = 0; i < 9; i++)
  {
    std::cout<< elements[i] << " ";

  }
  std::cout<< "\n ";
}
