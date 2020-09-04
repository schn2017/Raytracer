#pragma once

#include "Matrix3.h"
#include "Matrix4.h"
#include "Vector3.h"
#include "Vector4.h"
#include "math.h"
#include <iostream>

#define PI 3.14159265

class MathHelper
{
public:
  static bool solveQuadratic(float a, float b, float c, float &t0, float &t1);
  static Matrix3 add(Matrix3 m1, Matrix3 m2);
  static Matrix4 add(Matrix4 m1, Matrix4 m2);
  static float dot(Vector3 v1, Vector3 v2);
  static float dot(Vector4 v1, Vector4 v2);
  static Vector3 cross(Vector3 v1, Vector3 v2);
  static Vector3 normalize(Vector3 v1);
  static Vector4 normalize(Vector4 v1);
  static float magnitude(Vector3 v1);
  static float magnitude(Vector4 v1);
  static Matrix3 multiply(Matrix3 m1, Matrix3 m2);
  static Matrix4 multiply(Matrix4 m1, Matrix4 m2);
  static float radians(float angle);
  static Matrix3 scalarMultiply(float scalar, Matrix3 m1);
  static Matrix4 scalarMultiply(float scalar, Matrix4 m1);
  static Matrix3 sub(Matrix3 m1, Matrix3 m2);
  static Matrix4 sub(Matrix4 m1, Matrix4 m2);



};
