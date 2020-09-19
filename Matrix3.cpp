#include "Matrix3.h"
#include <iostream>

Matrix3::Matrix3(float r0x, float r0y, float r0z,
                 float r1x, float r1y, float r1z,
                 float r2x, float r2y, float r2z)
{
  elements[0][0] = r0x;
  elements[0][1] = r0y;
  elements[0][2] = r0z;
  elements[1][0] = r1x;
  elements[1][1] = r1y;
  elements[1][2] = r1z;
  elements[2][0] = r2x;
  elements[2][1] = r2y;
  elements[2][2] = r2z;
}

Matrix3::Matrix3()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      elements[i][j] = 0;
    }
  }
}

bool Matrix3::isEqual(Matrix3 other)
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if(elements[i][j] != other.getElement(i,j))
      {
        return false;
      }
    }
  }
  return true;
}

float Matrix3::getElement(int row, int column)
{
  return elements[row][column];
}

void Matrix3::setElement(int row, int column, float value)
{
  elements[row][column] = value;
}

void Matrix3::print()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
    std::cout << elements[i][j] << " ";
    }
  }
  std::cout<< "\n ";
}
