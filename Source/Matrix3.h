#pragma once
#include <math.h>

class Matrix3{
  public:
    Matrix3(float r0x, float r0y, float r0z,
            float r1x, float r1y, float r1z,
            float r2x, float r2y, float r2z);
    Matrix3();

    float getElement(int row, int column);
    void setElement(int row, int column, float value);
    void print();
    bool isEqual(Matrix3 other);

  Matrix3 operator+(Matrix3 otherMatrix);
  Matrix3 operator*(float value);
  bool operator==(Matrix3 otherMatrix);
  private:
    float elements[3][3];
};
