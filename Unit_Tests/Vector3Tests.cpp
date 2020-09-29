#include "catch.hpp"
#include "./Source/Vector3.h"

TEST_CASE("Vector3: Construction")
{
  Vector3 testVector = Vector3(1,2,3);

  REQUIRE(testVector.getX() == 1);
  REQUIRE(testVector.getY() == 2);
  REQUIRE(testVector.getZ() == 3);
}

TEST_CASE("Vector3: Addition")
{
  Vector3 v1 = Vector3(1, 2, 3);
  Vector3 v2 = Vector3(4, 5, 6);

  Vector3 v3 = v1 + v2;

  REQUIRE(v3.isEqual(Vector3(5, 7, 9)));
}

TEST_CASE("Vector3: Comparison")
{
  Vector3 v1 = Vector3(1,2,3);
  Vector3 v2 = Vector3(1,2,3);
  Vector3 v3 = Vector3(4,5,6);

  REQUIRE(v1.isEqual(v2) == true);
  REQUIRE(v2.isEqual(v1) == true);
  REQUIRE(v1.isEqual(v3) == false);

  REQUIRE((v1 == v2) == true);
  REQUIRE((v1 == v3) == false);
}

TEST_CASE("Vector3: Scalar Multiplication")
{
  Vector3 v1 = Vector3(1,2,3);
  Vector3 product1 = v1 * 2;
  Vector3 product2 = v1 * -1;

  REQUIRE(product1.isEqual(Vector3(2, 4, 6)) == true);
  REQUIRE(product2.isEqual(Vector3(-1, -2, -3)) == true);
}

TEST_CASE("Vector3: Subtraction")
{
  Vector3 v1 = Vector3(1, 2, 3);
  Vector3 v2 = Vector3(4, 5, 6);

  Vector3 v3 = v1 - v2;

  REQUIRE(v3.isEqual(Vector3(-3, -3, -3)));
}
