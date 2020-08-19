#include "catch.hpp"
#include "Sphere.h"

TEST_CASE("Sphere: Construction")
{
  Sphere testSphere = Sphere(1, 2, 3, 10);

  REQUIRE(testSphere.getPosition().isEqual(Vector3(1, 2, 3)) == true);
  REQUIRE(testSphere.getRadius() == 10);
}

TEST_CASE("Sphere: Intersection Test")
{
  Vector3 origin = Vector3(0, 0, 0);
  Vector3 direction = Vector3(0, 1, 0);
  Ray testRay = Ray(origin, direction);
  Sphere testSphere1 = Sphere(1, 2, 3, 10);
  Sphere testSphere2 = Sphere(0, 0, 50, 10);

  REQUIRE(testSphere1.intersect(testRay) == true);
  REQUIRE(testSphere2.intersect(testRay) == false);
}
