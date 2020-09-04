#pragma once
#include <iostream>

class Vector3{
  public:
    Vector3(float x, float y, float z);
    Vector3();
    float getX();
    float getY();
    float getZ();
    bool isEqual(Vector3 other);
    void toString();

    Vector3 operator+(const Vector3 &otherVector)
    {
      float xx = x + otherVector.x;
      float yy = y + otherVector.y;
      float zz = z + otherVector.z;

      return Vector3(xx, yy , zz);
    }

    Vector3 operator-(const Vector3 &otherVector)
    {
      float xx = x - otherVector.x;
      float yy = y - otherVector.y;
      float zz = z - otherVector.z;

      return Vector3(xx, yy, zz);
    }

    Vector3 operator*(const float &scalar)
    {
      float xx = x * scalar;
      float yy = y * scalar;
      float zz = z * scalar;

      return Vector3(xx, yy, zz);
    }

  private:
    float x;
    float y;
    float z;;
};
