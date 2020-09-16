#include "catch.hpp"
#include "Triangle.h"

TEST_CASE("Triangle: Construction")
{
  Vector3 v1 = Vector3(1, 2, 3);
  Vector3 v2 = Vector3(4, 5, 6);
  Vector3 v3 = Vector3(7, 8, 9);

  Triangle testTriangle1 = Triangle(v1, v2, v3);
  Triangle testTriangle2 = Triangle();

  REQUIRE(testTriangle1.getV1().isEqual(v1) == true);
  REQUIRE(testTriangle1.getV2().isEqual(v2) == true);
  REQUIRE(testTriangle1.getV3().isEqual(v3) == true);
  REQUIRE(testTriangle2.getState() == false);
}

TEST_CASE("Triangle: Intersection Test")
{
  Vector3 v1 = Vector3(-1, -1, 0);
  Vector3 v2 = Vector3(1, -1, 0);
  Vector3 v3 = Vector3(0, 1, 0);
  Vector3 origin = Vector3(0, 0, 5);
  Vector3 direction = MathHelper::normalize(Vector3(0, 0, -1));

  Ray testRay = Ray(origin, direction);

  Triangle testTriangle1 = Triangle(v1, v2, v3);

  REQUIRE(testTriangle1.intersect(testRay) == true);
}

TEST_CASE("Triangle: Apply ModelView Matrix")
{
  Matrix4 testMatrix = Matrix4(2, 0, 2, 0,
                               1, 2, 3, 4,
                               5, 6, 1, 3,
                               2, 5, 5, 7);
  Vector3 v1 = Vector3(1, 2, 3);
  Vector3 v2 = Vector3(1, 2, 3);
  Vector3 v3 = Vector3(1, 2, 3);
  Triangle testTriangle = Triangle(v1, v2, v3);

  testTriangle.setV1(MathHelper::transformVector3(testMatrix, testTriangle.getV1()));
  testTriangle.setV2(MathHelper::transformVector3(testMatrix, testTriangle.getV2()));
  testTriangle.setV3(MathHelper::transformVector3(testMatrix, testTriangle.getV3()));

  REQUIRE((floor(testTriangle.getV1().getX() * 100.0 + 0.5) / 100) == 0.24);
  REQUIRE((floor(testTriangle.getV1().getY() * 100.0 + 0.5) / 100) == 0.53);
  REQUIRE((floor(testTriangle.getV1().getZ() * 100.0 + 0.5) / 100) == 0.68);

  REQUIRE((floor(testTriangle.getV2().getX() * 100.0 + 0.5) / 100) == 0.24);
  REQUIRE((floor(testTriangle.getV2().getY() * 100.0 + 0.5) / 100) == 0.53);
  REQUIRE((floor(testTriangle.getV2().getZ() * 100.0 + 0.5) / 100) == 0.68);

  REQUIRE((floor(testTriangle.getV3().getX() * 100.0 + 0.5) / 100) == 0.24);
  REQUIRE((floor(testTriangle.getV3().getY() * 100.0 + 0.5) / 100) == 0.53);
  REQUIRE((floor(testTriangle.getV3().getZ() * 100.0 + 0.5) / 100) == 0.68);
}
