#include "catch.hpp"
#include "PointLight.h"

TEST_CASE("Point Light: Constructor")
{
  PointLight testLight1 = PointLight(Point(0, 0, 1), RGB(0, 0, 1));
  PointLight testLight2 = PointLight();
  REQUIRE((testLight1.getPosition() == Point(0, 0, 1)) == true);
  REQUIRE((testLight1.getLightColor() == RGB(0, 0, 1)) == true);
  REQUIRE(testLight1.getState() == true);
  REQUIRE(testLight2.getState() == false);
}
