#include "catch.hpp"
#include "Matrix3.h"
#include "Matrix4.h"

TEST_CASE("Matrix4: Construction - All Floats")
{
  Matrix4 testMatrix = Matrix4(0, 1, 2, 3,
                               4, 5, 6, 7,
                               8, 9, 10, 11,
                               12, 13, 14, 15);

  for (int i = 0; i < 16; i++)
  {
    REQUIRE(testMatrix.getElements()[i] == i);
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
  Matrix4 testMatrix = Matrix4();

  for (int i = 0; i < 16; i++)
  {
    REQUIRE(testMatrix.getElements()[i] == 0);
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
