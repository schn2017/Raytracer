#include "catch.hpp"
#include "./Source/Point.h"

TEST_CASE("Point: Construction")
{
  Point testPoint1 = Point(0, 1, 2);
  Point testPoint2 = Point(1, 2, 3);
  Point testPoint3 = Point(0, 1, 2);

  REQUIRE((testPoint1 == testPoint2) == false);
  REQUIRE((testPoint1 == testPoint3) == true);
}

TEST_CASE("Point: Add Vector to Point")
{
  Point testPoint1 = Point(0, 1, 2);
  Vector3 v1 = Vector3(1, 2, 3);
  Point expectedPoint = Point(1, 3, 5);

  REQUIRE((testPoint1 + v1 == expectedPoint) == true);
}

TEST_CASE("Point: Point - Point")
{
  Point testPoint1 = Point(0, 1, 2);
  Point testPoint2 = Point(0, 5, 7);

  Vector3 sum = testPoint1 - testPoint2;
  Vector3 expectedSum = Vector3(0, -4, -5);
  REQUIRE((sum == expectedSum) == true);
}
