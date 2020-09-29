#include "catch.hpp"
#include "Object.h"

TEST_CASE("Object: Set and Get Object Properties")
{
  Object testObject = Object();

  Materials testMaterials = Materials(RGB(0, 0, 0), RGB(1, 1, 1), 10, RGB(2, 2, 2));
  Sphere testSphere = Sphere(1, 2, 3, 4);
  Triangle testTriangle = Triangle(Point(0, 0, 0), Point(1, 1, 1), Point(-1, -1, -1));
  Matrix4 testMatrix = Matrix4(1, 0, 0, 0,
                               0, 1, 0, 0,
                               0, 0, 1, 0,
                               0, 0, 0, 1);

  testObject.setMaterials(testMaterials);
  testObject.setSphere(testSphere);
  testObject.setTransform(testMatrix);
  testObject.setTriangle(testTriangle);

  // Testing Materials
  REQUIRE( (testObject.getMaterials().getDiffuse() == RGB(0, 0, 0)) == true);
  REQUIRE( (testObject.getMaterials().getEmission() == RGB(2, 2, 2)) == true);
  REQUIRE( testObject.getMaterials().getShininess() == 10);
  REQUIRE( (testObject.getMaterials().getSpecular() == RGB(1, 1, 1)) == true);

  // Testing Sphere
  REQUIRE((testObject.getSphere().getPosition() == Point(1, 2, 3)) == true);
  REQUIRE(testObject.getSphere().getRadius() == 4);

  // Testing Transform
  REQUIRE(testObject.getTransform().isEqual(testMatrix) == true);

  // Testing Triangle
  REQUIRE((testObject.getTriangle().getP1() == Point(0, 0, 0)) == true);
  REQUIRE((testObject.getTriangle().getP2() == Point(1, 1, 1)) == true);
  REQUIRE((testObject.getTriangle().getP3() == Point(-1, -1, -1)) == true);
}
