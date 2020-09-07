#include "catch.hpp"
#include "MathHelper.h"

TEST_CASE("MathHelper: Addition - Matrix3")
{
  Matrix3 m1 = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  Matrix3 m2 = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  Matrix3 sum1 = Matrix3(2, 4, 6, 8, 10, 12, 14, 16, 18);

  Matrix3 m3 = Matrix3(-1, -2, -3, -4, -5, -6, -7, -8, -9);
  Matrix3 zeros = Matrix3(0, 0, 0, 0, 0, 0, 0, 0, 0);

  REQUIRE(MathHelper::add(m1,m2).isEqual(sum1) == true);
  REQUIRE(MathHelper::add(m1,m3).isEqual(zeros) == true);
}

TEST_CASE("MathHelper: Addition - Matrix4")
{
  Matrix4 m1 = Matrix4(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16);

  Matrix4 m2 = Matrix4(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16);

  Matrix4 sum1 = Matrix4(2, 4, 6, 8,
                         10, 12, 14, 16,
                         18, 20, 22, 24,
                         26, 28, 30, 32);

  Matrix4 m3 = Matrix4(-1, -2, -3, -4,
                       -5, -6, -7, -8,
                       -9, -10, -11, -12,
                       -13, -14, -15, -16);

  Matrix4 zeros = Matrix4(0, 0, 0, 0,
                          0, 0, 0, 0,
                          0, 0, 0, 0,
                          0, 0, 0, 0);

  REQUIRE(MathHelper::add(m1, m2).isEqual(sum1) == true);
  REQUIRE(MathHelper::add(m1, m3).isEqual(zeros) == true);
}

TEST_CASE("MathHelper: Cross Product - Vector3")
{
  Vector3 v1 = Vector3(1, 2, 3);
  Vector3 v2 = Vector3(1, 2, 3);
  Vector3 v1v2 = Vector3(0, 0, 0);

  Vector3 v3 = Vector3(1, 2, 3);
  Vector3 v4 = Vector3(4, 5, 6);
  Vector3 v3v4 = Vector3(-3, 6, -3);
  Vector3 v4v3 = Vector3(3, -6, 3);

  //Vector3 test = Vector3(MathHelper::cross(v4, v3));
  //std::cout << test.getX() << " " << test.getY() << " " << test.getZ();

  REQUIRE(MathHelper::cross(v1, v2).isEqual(v1v2) == true);
  REQUIRE(MathHelper::cross(v3, v4).isEqual(v3v4) == true);
  REQUIRE(MathHelper::cross(v4, v3).isEqual(v4v3) == true);
  REQUIRE(MathHelper::cross(v3, v4).isEqual(MathHelper::cross(v4, v3)) == false);
}

TEST_CASE("MathHelper: Dot Product - Vector3")
{
  Vector3 v1 = Vector3(1, 2, 3);
  Vector3 v2 = Vector3(4, 5, 6);
  Vector3 v3 = Vector3(0, 0, 0);
  Vector3 v4 = Vector3(2.5, 3.3, -1.2);
  REQUIRE(MathHelper::dot(v1, v2) == 32);
  REQUIRE(MathHelper::dot(v1, v2) == MathHelper::dot(v2, v1));
  REQUIRE(MathHelper::dot(v1, v3) == 0);
  REQUIRE(MathHelper::dot(v1, v4) == 5.5);
}

TEST_CASE("MathHelper: Dot Product - Vector4")
{
  Vector4 v1 = Vector4(1, 2, 3, 4);
  Vector4 v2 = Vector4(5, 6, 7, 8);
  Vector4 v3 = Vector4(0, 0, 0, 0);
  Vector4 v4 = Vector4(2.5, 3.3, -1.2, 0);
  REQUIRE(MathHelper::dot(v1, v2) == 70);
  REQUIRE(MathHelper::dot(v1, v2) == MathHelper::dot(v2, v1));
  REQUIRE(MathHelper::dot(v1, v3) == 0);
  REQUIRE(MathHelper::dot(v1, v4) == 5.5);
}

TEST_CASE("MathHelper: Magnitude - Vector3")
{
  Vector3 v1 = Vector3(1, 2, 3);
  Vector3 v2 = Vector3(4, 5, 6);
  Vector3 v3 = Vector3(0, 0, 0);
  Vector3 v4 = Vector3(2.5, 3.3, -1.2);

  REQUIRE(floor(MathHelper::magnitude(v1) * 100.0) / 100.0  == 3.74);
  REQUIRE(floor(MathHelper::magnitude(v2) * 100.0) / 100.0 == 8.77);
  REQUIRE(MathHelper::magnitude(v3) == 0);
  REQUIRE(floor(MathHelper::magnitude(v4) * 100.0) / 100.0 == 4.31);
}

TEST_CASE("MathHelper: Magnitude - Vector4")
{
  Vector4 v1 = Vector4(1, 2, 3, 4);
  Vector4 v2 = Vector4(0, 0, 0, 0);
  Vector4 v3 = Vector4(-1, -1, 2, 2);
  Vector4 v4 = Vector4(2.5, 3.3, -1.2, 2.33);

  REQUIRE(floor(MathHelper::magnitude(v1) * 100.0) / 100.0 == 5.47);
  REQUIRE(MathHelper::magnitude(v2) == 0);
  REQUIRE(floor(MathHelper::magnitude(v3) * 100.0) / 100.0 == 3.16);
  REQUIRE(floor(MathHelper::magnitude(v4) * 100.0) / 100.0 == 4.89);
}

TEST_CASE("MathHelper: Multiplication - Matrix3")
{
  Matrix3 m1 = Matrix3(1,2,3,4,5,6,7,8,9);
  Matrix3 m2 = Matrix3(1,2,3,4,5,6,7,8,9);
  Matrix3 m1m2 = MathHelper::multiply(m1, m2);
  Matrix3 m1m2Expected= Matrix3(30, 36, 42, 66, 81, 96, 102, 126, 150);

  REQUIRE(m1m2.isEqual(m1m2Expected) == true);

}

TEST_CASE("MathHelper: Multiplication - Matrix4")
{
  Matrix4 m1 = Matrix4(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16);
  Matrix4 m2 = Matrix4(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16);

  Matrix4 m1m2 = MathHelper::multiply(m1, m2);
  Matrix4 m1m2Expected= Matrix4(90, 100, 110, 120,
                                202, 228, 254, 280,
                                314, 356, 398, 440,
                                426, 484, 542, 600);

  REQUIRE(m1m2.isEqual(m1m2Expected) == true);
}

TEST_CASE("MathHelper: Mutliplication Matrix4 * Vector4")
{
  Matrix4 m1 = Matrix4(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16);
  Vector4 v1 = Vector4(1, 2, 3, 4);

  v1 = MathHelper::multiply(m1, v1);

  REQUIRE(v1.isEqual(Vector4(30, 70, 110, 150)) == true);

}


TEST_CASE("MathHelper: Normalize Vector - Vector3")
{
  Vector3 v1 = Vector3(1, 2, 3);
  Vector3 v1N = MathHelper::normalize(v1);
  Vector3 v2 = Vector3(4, -1, 2);
  Vector3 v2N = MathHelper::normalize(v2);
  Vector3 v3 = Vector3(4, -1, 0);
  Vector3 v3N = MathHelper::normalize(v3);

  REQUIRE(floor(MathHelper::magnitude(v1N) * 100.0 + 0.5) / 100.0 == 1.0);
  REQUIRE(floor(MathHelper::magnitude(v2N) * 100.0 + 0.5) / 100.0 == 1.0);
  REQUIRE(floor(MathHelper::magnitude(v3N) * 100.0 + 0.5) / 100.0 == 1.0);
}

TEST_CASE("MathHelper: Normalize Vector - Vector4")
{
  Vector4 v1 = Vector4(1, 2, 3, 4);
  Vector4 v1N = MathHelper::normalize(v1);
  Vector4 v2 = Vector4(4, -1, 2, 10);
  Vector4 v2N = MathHelper::normalize(v2);
  Vector4 v3 = Vector4(4, -1, 0, -5);
  Vector4 v3N = MathHelper::normalize(v3);

  REQUIRE(floor(MathHelper::magnitude(v1N) * 100.0 + 0.5) / 100.0 == 1.0);
  REQUIRE(floor(MathHelper::magnitude(v2N) * 100.0 + 0.5) / 100.0 == 1.0);
  REQUIRE(floor(MathHelper::magnitude(v3N) * 100.0 + 0.5) / 100.0 == 1.0);

}

TEST_CASE("MathHelper: Radians (Angle to Radians Conversion)")
{
  float angle1 = 30;
  float angle2 = -30;
  float angle3 = 0;
  float angle4 = 360;

  REQUIRE(floor(MathHelper::radians(angle1) * 100.0 + 0.5) / 100.0 == 0.52);
  REQUIRE(floor(MathHelper::radians(angle2) * 100.0 + 0.5) / 100.0 == -0.52);
  REQUIRE(floor(MathHelper::radians(angle3) * 100.0 + 0.5) / 100.0 == 0);
  REQUIRE(floor(MathHelper::radians(angle4) * 100.0 + 0.5) / 100.0 == 6.28);
}

TEST_CASE("MathHelper: Scalar Multiplication Matrix3")
{
  Matrix3 m1 = Matrix3(1, 2, 3,
                       4, 5, 6,
                       7, 8, 9);

  float scalar = 2;

  Matrix3 m1Scaled = MathHelper::scalarMultiply(scalar, m1);
  Matrix3 expectedValue = Matrix3(2, 4, 6,
                                  8, 10, 12,
                                  14, 16, 18);
  for(int i = 0; i < 9; i++)
  {
    REQUIRE(m1Scaled.getElements()[i] == expectedValue.getElements()[i]);
  }
}

TEST_CASE("MathHelper: Scalar Multiplication Matrix4")
{
  Matrix4 m1 = Matrix4(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16);

  float scalar = 2;

  Matrix4 m1Scaled = MathHelper::scalarMultiply(scalar, m1);
  Matrix4 expectedValue = Matrix4(2, 4, 6, 8,
                                  10, 12, 14, 16,
                                  18, 20, 22, 24,
                                  26, 28, 30, 32);

  for(int i = 0; i < 16; i++)
  {
    REQUIRE(m1Scaled.getElements()[i] == expectedValue.getElements()[i]);
  }
}

TEST_CASE("MathHelper: Subtaction - Matrix3")
{
  Matrix3 m1 = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  Matrix3 m2 = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  Matrix3 sum1 = Matrix3(2, 4, 6, 8, 10, 12, 14, 16, 18);

  Matrix3 m3 = Matrix3(-1, -2, -3, -4, -5, -6, -7, -8, -9);
  Matrix3 zeros = Matrix3(0, 0, 0, 0, 0, 0, 0, 0, 0);

  REQUIRE(MathHelper::sub(m1,m2).isEqual(zeros) == true);
  REQUIRE(MathHelper::sub(m1,m3).isEqual(sum1) == true);
}

TEST_CASE("MathHelper: Subtraction - Matrix4")
{
  Matrix4 m1 = Matrix4(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16);

  Matrix4 m2 = Matrix4(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16);

  Matrix4 sum1 = Matrix4(2, 4, 6, 8,
                         10, 12, 14, 16,
                         18, 20, 22, 24,
                         26, 28, 30, 32);

  Matrix4 m3 = Matrix4(-1, -2, -3, -4,
                       -5, -6, -7, -8,
                       -9, -10, -11, -12,
                       -13, -14, -15, -16);

  Matrix4 zeros = Matrix4(0, 0, 0, 0,
                          0, 0, 0, 0,
                          0, 0, 0, 0,
                          0, 0, 0, 0);

  REQUIRE(MathHelper::sub(m1, m2).isEqual(zeros) == true);
  REQUIRE(MathHelper::sub(m1, m3).isEqual(sum1) == true);
}

TEST_CASE("MathHelper: Quadratic Equation Solver")
{
  // Two Solutions, -2 and 3
  float a1 = 1;
  float b1 = -1;
  float c1 = -6;
  // One Solution x = -1
  float a2 = 1;
  float b2 = 2;
  float c2 = 1;
  // Complex Solution
  float a3 = 1;
  float b3 = 2;
  float c3 = 4;

  float t0 = 0;
  float t1 = 0;

  REQUIRE(MathHelper::solveQuadratic(a1, b1, c1, t0, t1) == true);
  REQUIRE(t0 == -2);
  REQUIRE(t1 == 3);

  REQUIRE(MathHelper::solveQuadratic(a2, b2, c2, t0, t1) == true);
  REQUIRE(t0 == -1);
  REQUIRE(t1 == -1);

  REQUIRE(MathHelper::solveQuadratic(a3, b3, c3, t0, t1) == false);
}
