#pragma once

#include "math.h"
#include "MathHelper.h"

class Transform
{
public:
  static Matrix4 lookAt(Point eye, Point center, Vector3 up);
  static Matrix4 perspective(float fovy, float aspect, float zNear, float zFar);
  static Matrix3 rotate(float degrees, Vector3 axis);
  static Matrix4 scale(float sx, float sy, float sz);
  static Matrix4 translate(float tx, float ty, float tz);
  static Vector3 up(Vector3 up, Vector3 eye);
};
