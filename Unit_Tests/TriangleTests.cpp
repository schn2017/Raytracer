#include "catch.hpp"
#include "./Source/Triangle.h"

TEST_CASE("Triangle: Construction")
{
  Point p1 = Point(1, 2, 3);
  Point p2 = Point(4, 5, 6);
  Point p3 = Point(7, 8, 9);

  Triangle testTriangle1 = Triangle(p1, p2, p3);
  Triangle testTriangle2 = Triangle();

  REQUIRE((testTriangle1.getP1() == p1) == true);
  REQUIRE((testTriangle1.getP2() == p2) == true);
  REQUIRE((testTriangle1.getP3() == p3) == true);
  REQUIRE(testTriangle2.getState() == false);
}

TEST_CASE("Triangle: Intersection Test")
{
  Point p1 = Point(-1, -1, 0);
  Point p2 = Point(1, -1, 0);
  Point p3 = Point(0, 1, 0);
  Point origin = Point(0, 0, 5);
  Vector3 direction = MathHelper::normalize(Vector3(0, 0, -1));

  Ray testRay = Ray(origin, direction);

  Triangle testTriangle1 = Triangle(p1, p2, p3);

  REQUIRE(testTriangle1.intersect(testRay) == true);
}

TEST_CASE("Triangle: Apply ModelView Matrix")
{
  Matrix4 testMatrix = Matrix4(2, 0, 2, 0,
                               1, 2, 3, 4,
                               5, 6, 1, 3,
                               2, 5, 5, 7);
  Point p1 = Point(1, 2, 3);
  Point p2 = Point(1, 2, 3);
  Point p3 = Point(1, 2, 3);
  Triangle testTriangle = Triangle(p1, p2, p3);

  testTriangle.setP1(testMatrix * testTriangle.getP1());
  testTriangle.setP2(testMatrix * testTriangle.getP2());
  testTriangle.setP3(testMatrix * testTriangle.getP3());

  REQUIRE((floor(testTriangle.getP1().getX() * 100.0 + 0.5) / 100) == 0.24);
  REQUIRE((floor(testTriangle.getP1().getY() * 100.0 + 0.5) / 100) == 0.53);
  REQUIRE((floor(testTriangle.getP1().getZ() * 100.0 + 0.5) / 100) == 0.68);

  REQUIRE((floor(testTriangle.getP2().getX() * 100.0 + 0.5) / 100) == 0.24);
  REQUIRE((floor(testTriangle.getP2().getY() * 100.0 + 0.5) / 100) == 0.53);
  REQUIRE((floor(testTriangle.getP2().getZ() * 100.0 + 0.5) / 100) == 0.68);

  REQUIRE((floor(testTriangle.getP3().getX() * 100.0 + 0.5) / 100) == 0.24);
  REQUIRE((floor(testTriangle.getP3().getY() * 100.0 + 0.5) / 100) == 0.53);
  REQUIRE((floor(testTriangle.getP3().getZ() * 100.0 + 0.5) / 100) == 0.68);
}
