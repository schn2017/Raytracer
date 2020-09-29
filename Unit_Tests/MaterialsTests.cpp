#include "catch.hpp"
#include "./Source/Materials.h"

TEST_CASE("Materials: Constructor")
{
  Materials testMaterials(RGB(1, 1, 1), RGB(2, 2, 2), 4, RGB(3, 3, 3));

  REQUIRE( (testMaterials.getDiffuse() == RGB(1, 1, 1)) == true );
  REQUIRE( (testMaterials.getSpecular() == RGB(2, 2, 2)) == true );
  REQUIRE( testMaterials.getShininess() == 4);
  REQUIRE( (testMaterials.getEmission() == RGB(3, 3, 3)) == true );
}

TEST_CASE("Materials: Set Diffuse")
{
  Materials testMaterials(RGB(1, 1, 1), RGB(2, 2, 2), 4, RGB(3, 3, 3));
  testMaterials.setDiffuse(RGB(3, 4, 5));
  REQUIRE( (testMaterials.getDiffuse() == RGB(3, 4, 5)) == true );
}

TEST_CASE("Materials: Set Emission")
{
  Materials testMaterials(RGB(1, 1, 1), RGB(2, 2, 2), 4, RGB(3, 3, 3));
  testMaterials.setEmission(RGB(3, 4, 5));
  REQUIRE( (testMaterials.getEmission() == RGB(3, 4, 5)) == true );
}

TEST_CASE("Materials: Set Shininess")
{
  Materials testMaterials(RGB(1, 1, 1), RGB(2, 2, 2), 4, RGB(3, 3, 3));
  testMaterials.setShininess(20);
  REQUIRE( testMaterials.getShininess() == 20);
}

TEST_CASE("Materials: Set Specular")
{
  Materials testMaterials(RGB(1, 1, 1), RGB(2, 2, 2), 4, RGB(3, 3, 3));
  testMaterials.setSpecular(RGB(3, 4, 5));
  REQUIRE( (testMaterials.getSpecular() == RGB(3, 4, 5)) == true );
}
