#include "catch.hpp"
#include "Sphere.h"


TEST_CASE("Sphere: Construction")
{
  Sphere testSphere = Sphere(1, 2, 3, 10);

  REQUIRE(testSphere.getPosition().isEqual(Vector3(1, 2, 3)) == true);
  REQUIRE(testSphere.getRadius() == 10);
}
