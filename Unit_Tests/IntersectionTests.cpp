#include "catch.hpp"
#include "Intersection.h"

TEST_CASE("Intersection - Constructors")
{
  float distance = 1;
  Materials testMaterials = Materials(RGB(0, 0, 1), RGB(0, 1 ,0), 10, RGB(1, 0, 0));


  Intersection testIntersection1 = Intersection(distance, testMaterials);
  Intersection testIntersection2 = Intersection();

  Materials testMaterialsGet = testIntersection1.getMaterials();


  REQUIRE(testIntersection1.getState() == true);
  REQUIRE(testIntersection1.getDistance() == 1);
  REQUIRE( (testMaterialsGet.getDiffuse() == RGB(0, 0, 1)) == true);
  REQUIRE( (testMaterialsGet.getSpecular() == RGB(0, 1, 0)) == true);
  REQUIRE( (testMaterialsGet.getEmission() == RGB(1, 0, 0)) == true);
  REQUIRE(testMaterialsGet.getShininess() == 10);
  REQUIRE(testIntersection2.getState() == false);

}
