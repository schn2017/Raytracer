#include "catch.hpp"
#include "Scene.h"

TEST_CASE("Scene: Open Scene Input Text File")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1.test";
  const char * fileNameFail = "scene10.test";
  REQUIRE(sceneTest.readScene(fileNamePass) == true);
  REQUIRE(sceneTest.readScene(fileNameFail) == false);
}

TEST_CASE("Scene: Read Scene Input - Camera Initialization")
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

TEST_CASE("Scene: Read Scene Input - Size")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1Cam4.test";
  sceneTest.readScene(fileNamePass);

  REQUIRE(sceneTest.getHeight() ==  480);
  REQUIRE(sceneTest.getWidth() == 640);
}

TEST_CASE("Scene: Read Scene Input - Depth")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1Cam4.test";
  sceneTest.readScene(fileNamePass);

  REQUIRE(sceneTest.getDepth() ==  10);
}

TEST_CASE("Scene: Read Vertices")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1Cam4.test";
  sceneTest.readScene(fileNamePass);

  Vector3 v1 = sceneTest.getVertex(0);
  Vector3 v2 = sceneTest.getVertex(1);
  Vector3 v3 = sceneTest.getVertex(2);
  Vector3 v4 = sceneTest.getVertex(3);

  REQUIRE(v1.isEqual(Vector3(-1, -1, 0)) == true);
  REQUIRE(v2.isEqual(Vector3(1, -1, 0)) == true);
  REQUIRE(v3.isEqual(Vector3(1, 1, 0)) == true);
  REQUIRE(v4.isEqual(Vector3(-1, 1, 0)) == true);
}

TEST_CASE("Scene: Read Sphere")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1Cam4.test";
  sceneTest.readScene(fileNamePass);
  vector<Sphere> spheres = sceneTest.getSpheres();
  REQUIRE(spheres[0].getPosition().isEqual(Vector3(1, 2, 3)) == true);
  REQUIRE(spheres[0].getRadius() == 10);
}

TEST_CASE("Scene: Read Spheres")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1Cam4.test";

  sceneTest.readScene(fileNamePass);
  vector<Sphere> spheres = sceneTest.getSpheres();
  REQUIRE(spheres[0].getPosition().isEqual(Vector3(1, 2, 3)) == true);
  REQUIRE(spheres[0].getRadius() == 10);
  REQUIRE(spheres[1].getPosition().isEqual(Vector3(4, 5, 6)) == true);
  REQUIRE(spheres[1].getRadius() == 2);
}

TEST_CASE("Scene: Read Triangle")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1Cam4.test";
  sceneTest.readScene(fileNamePass);
  vector<Triangle> triangles = sceneTest.getTriangles();

  REQUIRE(triangles[0].getV1().isEqual(Vector3(-1, -1, 0)) == true);
  REQUIRE(triangles[0].getV2().isEqual(Vector3(1, -1, 0)) == true);
  REQUIRE(triangles[0].getV3().isEqual(Vector3(1, 1, 0)) == true);
}

TEST_CASE("Scene: Read Triangles")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1Cam4.test";
  sceneTest.readScene(fileNamePass);
  vector<Triangle> triangles = sceneTest.getTriangles();

  REQUIRE(triangles[0].getV1().isEqual(Vector3(-1, -1, 0)) == true);
  REQUIRE(triangles[0].getV2().isEqual(Vector3(1, -1, 0)) == true);
  REQUIRE(triangles[0].getV3().isEqual(Vector3(1, 1, 0)) == true);
  REQUIRE(triangles[1].getV1().isEqual(Vector3(-1, -1, 0)) == true);
  REQUIRE(triangles[1].getV2().isEqual(Vector3(1, 1, 0)) == true);
  REQUIRE(triangles[1].getV3().isEqual(Vector3(-1, 1, 0)) == true);
}

TEST_CASE("Scene: Read Spheres and Triangles")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1Cam4.test";
  sceneTest.readScene(fileNamePass);

  vector<Sphere> spheres = sceneTest.getSpheres();
  vector<Triangle> triangles = sceneTest.getTriangles();

  REQUIRE(spheres[0].getPosition().isEqual(Vector3(1, 2, 3)) == true);
  REQUIRE(spheres[0].getRadius() == 10);
  REQUIRE(spheres[1].getPosition().isEqual(Vector3(4, 5, 6)) == true);
  REQUIRE(spheres[1].getRadius() == 2);

  REQUIRE(triangles[0].getV1().isEqual(Vector3(-1, -1, 0)) == true);
  REQUIRE(triangles[0].getV2().isEqual(Vector3(1, -1, 0)) == true);
  REQUIRE(triangles[0].getV3().isEqual(Vector3(1, 1, 0)) == true);
  REQUIRE(triangles[1].getV1().isEqual(Vector3(-1, -1, 0)) == true);
  REQUIRE(triangles[1].getV2().isEqual(Vector3(1, 1, 0)) == true);
  REQUIRE(triangles[1].getV3().isEqual(Vector3(-1, 1, 0)) == true);
}

TEST_CASE("Scene: Render Test Scene")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1Cam4.test";
  sceneTest.readScene(fileNamePass);

  sceneTest.renderScene();
}
