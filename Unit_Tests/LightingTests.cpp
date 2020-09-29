#include "catch.hpp"
#include "Lighting.h"

TEST_CASE("Lighting - Add Light Source/Get Light Source")
{
  Lighting testLighting = Lighting();
  LightSource testLightSource = LightSource();
  PointLight testPointLight = PointLight(Point(0, 0, 1), RGB(1, 0, 0));

  testLightSource.setPointLight(testPointLight);
  testLighting.addLightSource(testLightSource);

  PointLight testPointLightGet = testLighting.getLightSource(0).getPointLight();

  REQUIRE((testPointLightGet.getPosition() == Point(0, 0, 1)) == true);
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

TEST_CASE("Lighting - Apply View Matrix to Lights")
{
  Lighting testLighting = Lighting();
  LightSource testLightSource = LightSource();
  PointLight testPointLight = PointLight(Point(1, 2, 3), RGB(0, 0, 0));

  Matrix4 testMatrix = Matrix4(2, 0, 2, 0,
                               1, 2, 3, 4,
                               5, 6, 1, 3,
                               2, 5, 5, 7);

  testLightSource.setPointLight(testPointLight);
  testLighting.addLightSource(testLightSource);

  testLighting.applyViewMatrix(testMatrix);

  testPointLight = testLighting.getLightSource(0).getPointLight();

  REQUIRE((floor(testPointLight.getPosition().getX() * 100.0 + 0.5) / 100) == 0.24);
  REQUIRE((floor(testPointLight.getPosition().getY() * 100.0 + 0.5) / 100) == 0.53);
  REQUIRE((floor(testPointLight.getPosition().getZ() * 100.0 + 0.5) / 100) == 0.68);
}
