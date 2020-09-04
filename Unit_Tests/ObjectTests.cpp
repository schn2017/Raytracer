#include "catch.hpp"
#include "Object.h"

TEST_CASE("Object: Set and Get Object Properties")
{
  Object testObject = Object();

  Materials testMaterials = Materials(RGB(0, 0, 0), RGB(1, 1, 1), 10, RGB(2, 2, 2));
  Sphere testSphere = Sphere(1, 2, 3, 4);
  Triangle testTriangle = Triangle(Vector3(0, 0, 0), Vector3(1, 1, 1), Vector3(-1, -1, -1));

  testObject.setMaterials(testMaterials);
  testObject.setSphere(testSphere);
  testObject.setTriangle(testTriangle);

  // Testing Materials
  REQUIRE( (testObject.getMaterials().getDiffuse() == RGB(0, 0, 0)) == true);
  REQUIRE( (testObject.getMaterials().getEmission() == RGB(2, 2, 2)) == true);
  REQUIRE(testObject.getMaterials().getShininess() == 10);
  REQUIRE( (testObject.getMaterials().getSpecular() == RGB(1, 1, 1)) == true);

  // Testing Sphere
  REQUIRE(testObject.getSphere().getPosition().isEqual(Vector3(1, 2,3)) == true);
  REQUIRE(testObject.getSphere().getRadius() == 4);

  // Testing Triangle
  REQUIRE(testObject.getTriangle().getV1().isEqual(Vector3(0, 0, 0)) == true);
  REQUIRE(testObject.getTriangle().getV2().isEqual(Vector3(1, 1, 1)) == true);
  REQUIRE(testObject.getTriangle().getV3().isEqual(Vector3(-1, -1, -1)) == true);
}
