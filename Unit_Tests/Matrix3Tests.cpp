#include "catch.hpp"
#include "./Source/Matrix3.h"

TEST_CASE("Matrix3: Construction - All floats")
{
  Matrix3 testMatrix = Matrix3(0, 1, 2, 3, 4, 5, 6, 7, 8);

  int count = 0;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      REQUIRE(testMatrix.getElement(i, j) == count);
      count++;
    }
  }
}

TEST_CASE("Matrix3: Construction - No Inputs")
{
  Matrix3 testMatrix = Matrix3();

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      REQUIRE(testMatrix.getElement(i,j) == 0);
    }
  }

}

TEST_CASE("Matrix3: Set Elements")
{
  Matrix3 testMatrix = Matrix3(0, 1, 2, 3, 4, 5, 6, 7, 8);
  testMatrix.setElement(0, 0, 1);
  REQUIRE(testMatrix.getElement(0,0) == 1);
}

TEST_CASE("Matrix3: == Override")
{
  Matrix3 m1 = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  Matrix3 m2 = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  Matrix3 m3 = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 0);

  REQUIRE( (m1 == m2) == true);
  REQUIRE( (m2 == m1) == true);
  REQUIRE( (m1 == m3) == false);
}

TEST_CASE("Matrix3: Matrix3 + Matrix3 Addition Override")
{
  Matrix3 m1 = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  Matrix3 m2 = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);

  Matrix3 expectedMatrix = Matrix3(2, 4, 6, 8, 10, 12, 14, 16, 18);

  REQUIRE( (((m1 + m2) == expectedMatrix)) == true);

}
