#include "catch.hpp"
#include "Ray.h"

TEST_CASE("Ray: Construction")
{
  Vector3 origin = Vector3(1, 0, 2);
  Vector3 dir = Vector3(2, 3, 4);
  Ray testRay = Ray(origin, dir);

  REQUIRE(testRay.getDirection().isEqual(dir) == true);
  REQUIRE(testRay.getOrigin().isEqual(origin) == true);
}

TEST_CASE("Ray: Get Intersection")
{
  Vector3 origin = Vector3(1, 0, 2);
  Vector3 dir = Vector3(2, 3, 4);
  Ray testRay = Ray(origin, dir);

  testRay.setT(2);

  REQUIRE(testRay.getIntersection().isEqual(Vector3(5, 6, 10)));
}

TEST_CASE("Ray: Set t")
{
  Vector3 origin = Vector3(1, 0, 2);
  Vector3 dir = Vector3(2, 3, 4);
  Ray testRay = Ray(origin, dir);

  testRay.setT(10);

  REQUIRE(testRay.getT() == 10);
}
