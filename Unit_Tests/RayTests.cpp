#include "catch.hpp"
#include "Ray.h"

TEST_CASE("Ray: Construction")
{
  Point origin = Point(1, 0, 2);
  Vector3 dir = Vector3(2, 3, 4);
  Ray testRay = Ray(origin, dir);

  REQUIRE(testRay.getDirection().isEqual(dir) == true);
  REQUIRE((testRay.getOrigin() == origin) == true);
}

TEST_CASE("Ray: Get Intersection")
{
  Point origin = Point(1, 0, 2);
  Vector3 dir = Vector3(2, 3, 4);
  Ray testRay = Ray(origin, dir);

  testRay.setT(2);

  REQUIRE((testRay.getIntersectionPoint() == Point(5, 6, 10)) == true);
}

TEST_CASE("Ray: Set t")
{
  Point origin = Point(1, 0, 2);
  Vector3 dir = Vector3(2, 3, 4);
  Ray testRay = Ray(origin, dir);

  testRay.setT(10);

  REQUIRE(testRay.getT() == 10);
}
