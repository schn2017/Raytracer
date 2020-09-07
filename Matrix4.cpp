#include "Matrix3.h"
#include "Matrix4.h"
#include <iostream>


Matrix4::Matrix4(float r0x, float r0y, float r0z, float r0w,
        float r1x, float r1y, float r1z, float r1w,
        float r2x, float r2y, float r2z, float r2w,
        float r3x, float r3y, float r3z, float r3w)
  {
    elements[0] = r0x;
    elements[1] = r0y;
    elements[2] = r0z;
    elements[3] = r0w;
    elements[4] = r1x;
    elements[5] = r1y;
    elements[6] = r1z;
    elements[7] = r1w;
    elements[8] = r2x;
    elements[9] = r2y;
    elements[10] = r2z;
    elements[11] = r2w;
    elements[12] = r3x;
    elements[13] = r3y;
    elements[14] = r3z;
    elements[15] = r3w;
  }

Matrix4::Matrix4(Matrix3 mat3, float r0w, float r1w, float r2w, float r3x,
                float r3y, float r3z, float r3w)
{
  elements[0] = mat3.getElements()[0];
  elements[1] = mat3.getElements()[1];
  elements[2] = mat3.getElements()[2];
  elements[3] = r0w;
  elements[4] = mat3.getElements()[3];
  elements[5] = mat3.getElements()[4];
  elements[6] = mat3.getElements()[5];
  elements[7] = r1w;
  elements[8] = mat3.getElements()[6];
  elements[9] = mat3.getElements()[7];
  elements[10] = mat3.getElements()[8];
  elements[11] = r2w;
  elements[12] = r3x;
  elements[13] = r3y;
  elements[14] = r3z;
  elements[15] = r3w;
}

Matrix4::Matrix4(Matrix3 mat3)
{
  elements[0] = mat3.getElements()[0];
  elements[1] = mat3.getElements()[1];
  elements[2] = mat3.getElements()[2];
  elements[3] = 0;
  elements[4] = mat3.getElements()[3];
  elements[5] = mat3.getElements()[4];
  elements[6] = mat3.getElements()[5];
  elements[7] = 0;
  elements[8] = mat3.getElements()[6];
  elements[9] = mat3.getElements()[7];
  elements[10] = mat3.getElements()[8];
  elements[11] = 0;
  elements[12] = 0;
  elements[13] = 0;
  elements[14] = 0;
  elements[15] = 0;
}

Matrix4::Matrix4()
  {
    elements[0] = 0;
    elements[1] = 0;
    elements[2] = 0;
    elements[3] = 0;
    elements[4] = 0;
    elements[5] = 0;
    elements[6] = 0;
    elements[7] = 0;
    elements[8] = 0;
    elements[9] = 0;
    elements[10] = 0;
    elements[11] = 0;
    elements[12] = 0;
    elements[13] = 0;
    elements[14] = 0;
    elements[15] = 0;
  }



bool Matrix4::isEqual(Matrix4 other)
{
  for (int i = 0; i < 16; i++)
  {
    if(elements[i] != other.getElements()[i])
    {
      return false;
    }
  }

  return true;
}

float * Matrix4::getElements(){
  float *matrix = elements;

  return matrix;
}

void Matrix4::setElement(int elementNumber, float value)
{
  elements[elementNumber] = value;
}

void Matrix4::print()
{
  int count = 0;
  for (int i = 0; i < 16; i++)
  {
    std::cout<< elements[i] << " ";
    count++;

    if(count == 4)
    {
      std::cout << "\n";
      count = 0;
    }

  }
  std::cout<< "\n";
}
