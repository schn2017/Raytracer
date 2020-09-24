
#include "Matrix3.h"
#include "Point.h"
#include "Vector3.h"

class Matrix4
{
public:
  //Constructors
  Matrix4(float r0x, float r0y, float r0z, float r0w,
          float r1x, float r1y, float r1z, float r1w,
          float r2x, float r2y, float r2z, float r2w,
          float r3x, float r3y, float r3z, float r3w);
  Matrix4(Matrix3 mat3, float r0w, float r1w, float r2w, float r3x,
          float r3y, float r3z, float r3w);
  Matrix4(Matrix3 mat3);
  Matrix4();
  //Get Member Definitions
  float getElement(int row, int column);
  //Set Member Definitions
  void setElement(int row, int column, float value);
  //
  void print();
  //
  bool isEqual(Matrix4 other);
  //operator overrides
  Point operator*(Point point);
  Vector3 operator*(Vector3 &v1);
  Matrix4 operator*(Matrix4 &otherMatrix);
  Matrix4 operator+(Matrix4 &otherMatrix);
private:
  float elements[4][4];
};
