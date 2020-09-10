#include "catch.hpp"
#include "LightSource.h"

TEST_CASE("Light Source: Add Point Light")
{
  LightSource testLightSource = LightSource();
  PointLight testPointLight = PointLight(Vector3(0, 0, 0), RGB(1, 0, 0));

  testLightSource.setPointLight(testPointLight);
  PointLight testPointLightGet = testLightSource.getPointLight();

  REQUIRE(testPointLightGet.getPosition().isEqual(Vector3(0, 0, 0)) == true);
  REQUIRE((testPointLightGet.getLightColor() == RGB(1, 0, 0)) == true);
  REQUIRE(testPointLightGet.getState() == true);
}
