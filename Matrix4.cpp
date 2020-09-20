#include "Matrix3.h"
#include "Matrix4.h"
#include <iostream>


Matrix4::Matrix4(float r0x, float r0y, float r0z, float r0w,
        float r1x, float r1y, float r1z, float r1w,
        float r2x, float r2y, float r2z, float r2w,
        float r3x, float r3y, float r3z, float r3w)
  {
    elements[0][0] = r0x;
    elements[0][1] = r0y;
    elements[0][2] = r0z;
    elements[0][3] = r0w;
    elements[1][0] = r1x;
    elements[1][1] = r1y;
    elements[1][2] = r1z;
    elements[1][3] = r1w;
    elements[2][0] = r2x;
    elements[2][1] = r2y;
    elements[2][2] = r2z;
    elements[2][3] = r2w;
    elements[3][0] = r3x;
    elements[3][1] = r3y;
    elements[3][2] = r3z;
    elements[3][3] = r3w;
  }

Matrix4::Matrix4(Matrix3 mat3, float r0w, float r1w, float r2w, float r3x,
                float r3y, float r3z, float r3w)
{
  elements[0][0] = mat3.getElement(0, 0);
  elements[0][1] = mat3.getElement(0, 1);
  elements[0][2] = mat3.getElement(0, 2);
  elements[0][3] = r0w;
  elements[1][0] = mat3.getElement(1, 0);
  elements[1][1] = mat3.getElement(1, 1);
  elements[1][2] = mat3.getElement(1, 2);
  elements[1][3] = r1w;
  elements[2][0] = mat3.getElement(2, 0);
  elements[2][1] = mat3.getElement(2, 1);
  elements[2][2] = mat3.getElement(2, 2);
  elements[2][3] = r2w;
  elements[3][0] = r3x;
  elements[3][1] = r3y;
  elements[3][2] = r3z;
  elements[3][3] = r3w;
}

Matrix4::Matrix4(Matrix3 mat3)
{
  elements[0][0] = mat3.getElement(0, 0);
  elements[0][1] = mat3.getElement(0, 1);
  elements[0][2] = mat3.getElement(0, 2);
  elements[0][3] = 0;
  elements[1][0] = mat3.getElement(1, 0);
  elements[1][1] = mat3.getElement(1, 1);
  elements[1][2] = mat3.getElement(1, 2);
  elements[1][3] = 0;
  elements[2][0] = mat3.getElement(2, 0);
  elements[2][1] = mat3.getElement(2, 1);
  elements[2][2] = mat3.getElement(2, 2);
  elements[2][3] = 0;
  elements[3][0] = 0;
  elements[3][1] = 0;
  elements[3][2] = 0;
  elements[3][3] = 1;
}

Matrix4::Matrix4()
  {
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        elements[i][j] = 0;
      }
    }
  }



bool Matrix4::isEqual(Matrix4 other)
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if(elements[i][j] != other.getElement(i, j))
      {
        return false;
      }
    }
  }
  return true;
}

float Matrix4::getElement(int row, int column){
  return elements[row][column];
}

void Matrix4::setElement(int row, int column, float value)
{
  elements[row][column] = value;
}

void Matrix4::print()
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      std::cout << elements[i][j] << " ";
    }
    std::cout<< "\n";
  }
}
