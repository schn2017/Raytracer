#include "catch.hpp"
#include "LightSource.h"

TEST_CASE("Light Source: Add Point Light")
{
  LightSource testLightSource = LightSource();
  PointLight testPointLight = PointLight(Point(0, 0, 0), RGB(1, 0, 0));

  testLightSource.setPointLight(testPointLight);
  PointLight testPointLightGet = testLightSource.getPointLight();

  REQUIRE((testPointLightGet.getPosition() == Point(0, 0, 0)) == true);
  REQUIRE((testPointLightGet.getLightColor() == RGB(1, 0, 0)) == true);
  REQUIRE(testPointLightGet.getState() == true);
}

TEST_CASE("Light Source: Apply View Matrix")
{
  Matrix4 testMatrix = Matrix4(2, 0, 2, 0,
                               1, 2, 3, 4,
                               5, 6, 1, 3,
                               2, 5, 5, 7);

  PointLight testPointLight = PointLight(Point(1, 2, 3), RGB(0, 0, 0));

  Point newPoint = testMatrix * testPointLight.getPosition();
  testPointLight.setPosition(newPoint);

  REQUIRE((floor(testPointLight.getPosition().getX() * 100.0 + 0.5) / 100) == 0.24);
  REQUIRE((floor(testPointLight.getPosition().getY() * 100.0 + 0.5) / 100) == 0.53);
  REQUIRE((floor(testPointLight.getPosition().getZ() * 100.0 + 0.5) / 100) == 0.68);
}
