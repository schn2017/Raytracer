#include "catch.hpp"
#include "Sphere.h"

TEST_CASE("Sphere: Construction")
{
  Sphere testSphere1 = Sphere(1, 2, 3, 10);
  Sphere testSphere2 = Sphere();

  REQUIRE(testSphere1.getPosition().isEqual(Vector3(1, 2, 3)) == true);
  REQUIRE(testSphere1.getRadius() == 10);
  REQUIRE(testSphere1.getState() == true);
  REQUIRE(testSphere2.getState() == false);
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

TEST_CASE("Sphere: Calculate Surface Normal")
{
  Sphere testSphere(0, 0, 0, 1);
  Vector3 point = Vector3(0, 1, 0);

  Vector3 normal =  testSphere.calculateSurfaceNormal(point);

  REQUIRE(normal.isEqual(point) == true );
}
