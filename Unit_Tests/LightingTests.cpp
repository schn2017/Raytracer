#include "catch.hpp"
#include "Lighting.h"

TEST_CASE("Lighting - Add Light Source/Get Light Source")
{
  Lighting testLighting = Lighting();
  LightSource testLightSource = LightSource();
  PointLight testPointLight = PointLight(Vector3(0, 0, 1), RGB(1, 0, 0));

  testLightSource.setPointLight(testPointLight);
  testLighting.addLightSource(testLightSource);

  PointLight testPointLightGet = testLighting.getLightSource(0).getPointLight();

  REQUIRE(testPointLightGet.getPosition().isEqual(Vector3(0, 0, 1)) == true);
  REQUIRE((testPointLightGet.getLightColor() == RGB(1, 0, 0)) == true);
  REQUIRE(testPointLightGet.getState() == true);
}

TEST_CASE("Lighting - Add Ambient Light/Get Ambient Light")
{
  Lighting testLighting = Lighting();
  RGB testAmbient = RGB(0, 1, 0);

  testLighting.setAmbientLight(testAmbient);
  REQUIRE((testLighting.getAmbientLight() == RGB(0, 1, 0)) == true);
}
