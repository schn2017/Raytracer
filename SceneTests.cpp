#include "catch.hpp"
#include "Scene.h"

TEST_CASE("Scene - Open Scene Input Text File")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1.test";
  const char * fileNameFail = "scene10.test";
  REQUIRE(sceneTest.readScene(fileNamePass) == true);
  REQUIRE(sceneTest.readScene(fileNameFail) == false);

}

TEST_CASE("Scene - Read Scene Input: Camera Initialization")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1Cam4.test";
  sceneTest.readScene(fileNamePass);
  Camera testCamera = sceneTest.getCamera();

  REQUIRE(testCamera.getLookFrom().isEqual(Vector3(-4, -4, 4)) == true);
  REQUIRE(testCamera.getLookAt().isEqual(Vector3(1, 0, 0)) == true);
  REQUIRE(testCamera.getUp().isEqual(Vector3(0, 1, 0)) == true);
  REQUIRE(testCamera.getFOV() == 30);
}
