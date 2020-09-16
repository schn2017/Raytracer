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

TEST_CASE("Sphere: Apply ModelView Matrix")
{
  Matrix4 testMatrix = Matrix4(2, 0, 2, 0,
                               1, 2, 3, 4,
                               5, 6, 1, 3,
                               2, 5, 5, 7);

  Sphere testSphere = Sphere(1, 2, 3, 1);
  
  testSphere.setPosition(MathHelper::transformVector3(testMatrix, testSphere.getPosition()));

  REQUIRE((floor(testSphere.getPosition().getX() * 100.0 + 0.5) / 100) == 0.24);
  REQUIRE((floor(testSphere.getPosition().getY() * 100.0 + 0.5) / 100) == 0.53);
  REQUIRE((floor(testSphere.getPosition().getZ() * 100.0 + 0.5) / 100) == 0.68);
}
