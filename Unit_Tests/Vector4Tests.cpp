#include "catch.hpp"
#include "./Source/Vector4.h"

TEST_CASE("Vector4: Construction")
{
  Vector4 v1 = Vector4(1, 2, 3, 4);

  REQUIRE(v1.getX() == 1);
  REQUIRE(v1.getY() == 2);
  REQUIRE(v1.getZ() == 3);
  REQUIRE(v1.getW() == 4);
}

TEST_CASE("Vector4: Comparisons")
{
    Vector4 v1 = Vector4(1, 2, 3, 4);
    Vector4 v2 = Vector4(1, 2, 3, 4);
    Vector4 v3 = Vector4(1, 2, 3, 5);

    REQUIRE(v1.isEqual(v2) == true);
    REQUIRE(v2.isEqual(v1) == true);
    REQUIRE(v1.isEqual(v3) == false);
}
