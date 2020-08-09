#include "catch.hpp"
#include "Triangle.h"

TEST_CASE("Triangle: Construction")
{
  Vector3 v1 = Vector3(1, 2, 3);
  Vector3 v2 = Vector3(4, 5, 6);
  Vector3 v3 = Vector3(7, 8, 9);

  Triangle testTriangle = Triangle(v1, v2, v3);

  REQUIRE(testTriangle.getV1().isEqual(v1) == true);
  REQUIRE(testTriangle.getV2().isEqual(v2) == true);
  REQUIRE(testTriangle.getV3().isEqual(v3) == true);

}
