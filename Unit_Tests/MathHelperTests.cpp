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

TEST_CASE("MathHelper: Create Adjugate matrix")
{
  Matrix4 testMatrix = Matrix4(1, 1, 1, -1,
                               1, 1, -1, 1,
                               1, -1, 1, 1,
                              -1, 1, 1, 1);

  Matrix4 expectedMatrix = Matrix4(-4, -4, -4, 4,
                                   -4, -4, 4, -4,
                                   -4, 4, -4, -4,
                                    4, -4, -4, -4);

  Matrix4 adjugateMatrix = MathHelper::adjugateMatrix4X4(testMatrix);
  REQUIRE(adjugateMatrix.isEqual(expectedMatrix));
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

TEST_CASE("MathHelper: Determinant - Matrix 3")
{
  Matrix3 testMatrix1 = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  Matrix3 testMatrix2 = Matrix3(1, 2, 3, 4, 5, 7, 7, 8, 9);

  REQUIRE(MathHelper::determinant(testMatrix1) == 0);
  REQUIRE(MathHelper::determinant(testMatrix2) == 6);
}

TEST_CASE("MathHelper: Determinant Sub Array 2X2")
{
  Matrix3 testMatrix = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);

  float testArray[4];

  // 1 2 3
  // 4 5 6
  // 7 8 9

  MathHelper::determinantSubArray2X2(testMatrix, 0, 0, testArray);

  REQUIRE(testArray[0] == 5);
  REQUIRE(testArray[1] == 6);
  REQUIRE(testArray[2] == 8);
  REQUIRE(testArray[3] == 9);

  MathHelper::determinantSubArray2X2(testMatrix, 0, 1, testArray);

  REQUIRE(testArray[0] == 4);
  REQUIRE(testArray[1] == 6);
  REQUIRE(testArray[2] == 7);
  REQUIRE(testArray[3] == 9);

  MathHelper::determinantSubArray2X2(testMatrix, 0, 2, testArray);

  REQUIRE(testArray[0] == 4);
  REQUIRE(testArray[1] == 5);
  REQUIRE(testArray[2] == 7);
  REQUIRE(testArray[3] == 8);

}

TEST_CASE("MathHelper: Determinant Sub Array 3X3")
{
  Matrix4 m1 = Matrix4(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16);

  Matrix3 testMatrix3X3 = MathHelper::determinantSubArray3X3(m1, 0, 0);
  Matrix3 expectedValue1 = Matrix3(6, 7, 8, 10, 11, 12, 14, 15, 16);

  REQUIRE(testMatrix3X3.isEqual(expectedValue1) == true);

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

TEST_CASE("MathHelper: Inverse Matrix 4X4")
{
  Matrix4 testMatrix = Matrix4(1, 1, 1, -1,
                               1, 1, -1, 1,
                               1, -1, 1, 1,
                              -1, 1, 1, 1);

  Matrix4 inverse = MathHelper::inverseMatrix4(testMatrix);
  Matrix4 expectedMatrix = Matrix4(0.25, 0.25, 0.25, -0.25,
                                   0.25, 0.25, -0.25, 0.25,
                                   0.25, -0.25, 0.25, 0.25,
                                  -0.25, 0.25, 0.25, 0.25);

  REQUIRE(inverse.isEqual(expectedMatrix) == true);
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

TEST_CASE("MathHelper: Find Max Value")
{
  REQUIRE(MathHelper::max(5, 10) == 10);
  REQUIRE(MathHelper::max(10, 5) == 10);
}

TEST_CASE("MathHelper: Multiplication - Matrix3")
{
  Matrix3 m1 = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  Matrix3 m2 = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  Matrix3 m1m2 = MathHelper::multiply(m1, m2);
  Matrix3 m1m2Expected = Matrix3(30, 36, 42, 66, 81, 96, 102, 126, 150);

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

TEST_CASE("MathHelper: Mutliplication Matrix3 * Vector3")
{
  Matrix3 m1 = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  Vector3 v1 = Vector3(1, 2, 3);

  v1 = MathHelper::multiply(m1, v1);

  REQUIRE(v1.isEqual(Vector3(14, 32, 50)) == true);
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
  for(int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      REQUIRE(m1Scaled.getElement(i, j) == expectedValue.getElement(i, j));
    }
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

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      REQUIRE(m1Scaled.getElement(i, j) == expectedValue.getElement(i, j));
    }
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

TEST_CASE("MathHelper: Transform Vector3")
{
  Matrix4 testMatrix = Matrix4(2, 0, 2, 0,
                               1, 2, 3, 4,
                               5, 6, 1, 3,
                               2, 5, 5, 7);

  Vector3 testVector1 = Vector3(1, 2, 3);

  Vector3 testVector2 = MathHelper::transformVector3(testMatrix, testVector1);

  REQUIRE((floor(testVector2.getX() * 100.0 + 0.5) / 100) == 0.24);
  REQUIRE((floor(testVector2.getY() * 100.0 + 0.5) / 100) == 0.53);
  REQUIRE((floor(testVector2.getZ() * 100.0 + 0.5) / 100) == 0.68);
}
