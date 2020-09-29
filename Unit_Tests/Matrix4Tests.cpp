#include "catch.hpp"
#include "./Source/Matrix3.h"
#include "./Source/Matrix4.h"

TEST_CASE("Matrix4: Construction - All Floats")
{
  Matrix4 testMatrix1 = Matrix4(0, 1, 2, 3,
                               4, 5, 6, 7,
                               8, 9, 10, 11,
                               12, 13, 14, 15);

Matrix4 testMatrix2 = Matrix4(0, 1, 2, 3,
                             4, 5, 6, 7,
                             8, 9, 10, 11,
                             12, 13, 14, 15);

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      REQUIRE(testMatrix1.getElement(i, j) == testMatrix2.getElement(i, j));
    }
  }
}

TEST_CASE("Matrix4: Construction - Vec3 and floats")
{
  Matrix3 m1 = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);

  Matrix4 m2 = Matrix4(m1, 1, 2, 3, 4, 5, 6, 7);
  Matrix4 m3 = Matrix4(1, 2, 3, 1,
                       4, 5, 6, 2,
                       7, 8, 9, 3,
                       4, 5, 6, 7);

  REQUIRE(m2.isEqual(m3) == true);
}

TEST_CASE("Matrix4: Construction - Only Vec3")
{
  Matrix3 m1 = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  Matrix4 m2 = Matrix4(m1);
  Matrix4 m3 = Matrix4(1, 2, 3, 0,
                       4, 5, 6, 0,
                       7, 8, 9, 0,
                       0, 0, 0, 1);

  REQUIRE(m2.isEqual(m3) == true);
}

TEST_CASE("Matrix4: Construction - No Inputs")
{
  Matrix4 testMatrix1 = Matrix4();

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      REQUIRE(testMatrix1.getElement(i, j) == 0);
    }
  }

}

TEST_CASE("Matrix4: Comparison")
{
  Matrix4 m1 = Matrix4(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16);

  Matrix4 m2 = Matrix4(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16);

  Matrix4 m3 = Matrix4(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 0);

  REQUIRE(m1.isEqual(m2) == true);
  REQUIRE(m2.isEqual(m1) == true);
  REQUIRE(m1.isEqual(m3) == false);
}

TEST_CASE("Matrix4: Matrix4 + Matrix4")
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

  REQUIRE((m1 + m2).isEqual(sum1) == true);
  REQUIRE((m1 + m3).isEqual(zeros) == true);
}


TEST_CASE("Matrix4: Matrix4 * Matrix4")
{
  Matrix4 m1 = Matrix4(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16);

  Matrix4 m2 = Matrix4(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16);

  Matrix4 m1m2 = m1 * m2;
  Matrix4 m1m2Expected = Matrix4(90, 100, 110, 120,
                                202, 228, 254, 280,
                                314, 356, 398, 440,
                                426, 484, 542, 600);

  REQUIRE(m1m2.isEqual(m1m2Expected) == true);
}

TEST_CASE("Matrix4: Matrix4 * Point")
{
  Matrix4 testMatrix = Matrix4(2, 0, 2, 0,
                               1, 2, 3, 4,
                               5, 6, 1, 3,
                               2, 5, 5, 7);

  Point testPoint1 = Point(1, 2, 3);

  Point testPoint2 = testMatrix * testPoint1;

  REQUIRE((floor(testPoint2.getX() * 100.0 + 0.5) / 100) == 0.24);
  REQUIRE((floor(testPoint2.getY() * 100.0 + 0.5) / 100) == 0.53);
  REQUIRE((floor(testPoint2.getZ() * 100.0 + 0.5) / 100) == 0.68);
}

TEST_CASE("Matrix4: Matrix4 * Vector3")
{
  Matrix4 testMatrix = Matrix4(2, 0, 2, 0,
                               1, 2, 3, 4,
                               5, 6, 1, 3,
                               2, 5, 5, 7);

  Vector3 testVector1 = Vector3(1, 2, 3);

  Vector3 testVector2 = testMatrix * testVector1;

  REQUIRE( testVector2.getX() == 8);
  REQUIRE( testVector2.getY() == 14);
  REQUIRE( testVector2.getZ() == 20);
}
