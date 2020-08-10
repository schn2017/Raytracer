#include "catch.hpp"
#include "Vector3.h"

TEST_CASE("Vector3: Construction")
{
  Vector3 testVector = Vector3(1,2,3);

  REQUIRE(testVector.getX() == 1);
  REQUIRE(testVector.getY() == 2);
  REQUIRE(testVector.getZ() == 3);
}

TEST_CASE("Vector3: Comparison")
{
  Vector3 v1 = Vector3(1,2,3);
  Vector3 v2 = Vector3(1,2,3);
  Vector3 v3 = Vector3(4,5,6);

  REQUIRE(v1.isEqual(v2) == true);
  REQUIRE(v2.isEqual(v1) == true);
  REQUIRE(v1.isEqual(v3) == false);
}
