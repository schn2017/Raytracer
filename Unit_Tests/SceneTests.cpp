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

TEST_CASE("Scene: Read Scene Input - Ambient Light")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1Cam4.test";
  sceneTest.readScene(fileNamePass);

  Lighting testLighting = sceneTest.getLighting();
  RGB testAmbientLight = testLighting.getAmbientLight();

  REQUIRE( (testAmbientLight == RGB(0.1, 0.1, 0.1) == true) );
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
  REQUIRE(testCamera.getFOVY() == 30);
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

TEST_CASE("Scene: Read Scene Input - Vertices")
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

TEST_CASE("Scene: Read Scene Input - Objects")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1Cam4.test";
  sceneTest.readScene(fileNamePass);
  vector<Object> objects = sceneTest.getObjects();

  REQUIRE(objects.size() == 4);

  // Get Objects
  Sphere testSphere1 = objects[0].getSphere();
  Sphere testSphere2 = objects[1].getSphere();
  Triangle testTriangle1 = objects[2].getTriangle();
  Triangle testTriangle2 = objects[3].getTriangle();

  // Vectors for triangle tests
  Vector3 v1 = Vector3(-1, -1, 0);
  Vector3 v2 = Vector3(1, -1, 0);
  Vector3 v3 = Vector3(1, 1, 0);
  Vector3 v4 = Vector3(-1, 1, 0);

  // Test Spheres
  REQUIRE(testSphere1.getRadius() == 10);
  REQUIRE(testSphere2.getRadius() == 2);

  // Test triangles
  REQUIRE(testTriangle1.getV1().isEqual(v1) == true);
  REQUIRE(testTriangle1.getV2().isEqual(v2) == true);
  REQUIRE(testTriangle1.getV3().isEqual(v3) == true);
  REQUIRE(testTriangle2.getV1().isEqual(v1) == true);
  REQUIRE(testTriangle2.getV2().isEqual(v3) == true);
  REQUIRE(testTriangle2.getV3().isEqual(v4) == true);

}

TEST_CASE("Scene: Read Scene Input - PointLight")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1Cam4.test";
  sceneTest.readScene(fileNamePass);

  Lighting testLighting = sceneTest.getLighting();
  PointLight testPointLight = testLighting.getLightSource(0).getPointLight();

  REQUIRE(testPointLight.getPosition().isEqual(Vector3(4, 0, 4)) == true);
  REQUIRE((testPointLight.getLightColor() == RGB(0.5, 0.5, 0.5)) == true);
  REQUIRE(testPointLight.getState() == true);
}


TEST_CASE("Scene: Read Scene Input - Sphere")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1Cam4.test";
  sceneTest.readScene(fileNamePass);
  vector<Sphere> spheres = sceneTest.getSpheres();
  REQUIRE(spheres[0].getPosition().isEqual(Vector3(1, 2, 3)) == true);
  REQUIRE(spheres[0].getRadius() == 10);
}

TEST_CASE("Scene: Read Scene Input - Spheres")
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

TEST_CASE("Scene: Read Scene Input - Triangle")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1Cam4.test";
  sceneTest.readScene(fileNamePass);
  vector<Triangle> triangles = sceneTest.getTriangles();

  REQUIRE(triangles[0].getV1().isEqual(Vector3(-1, -1, 0)) == true);
  REQUIRE(triangles[0].getV2().isEqual(Vector3(1, -1, 0)) == true);
  REQUIRE(triangles[0].getV3().isEqual(Vector3(1, 1, 0)) == true);
}

TEST_CASE("Scene: Read Scene Input - Triangles")
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

TEST_CASE("Scene: Read Scene Input - Spheres and Triangles")
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

TEST_CASE("Scene: Apply Transform Matrix")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "sphereScene.test";
  sceneTest.readScene(fileNamePass);

  //Object testObject = testObjects[0];
  Matrix4 viewMatrix = Matrix4(2, 0, 0, 0,
                               0, 3, 0, 0,
                               0, 0, 4, 0,
                               0, 0, 0, 1);

  sceneTest.applyTransform(viewMatrix);

  vector<Object> testObjects = sceneTest.getObjects();
  Object testObject = testObjects[0];

  REQUIRE(testObject.getTransform().isEqual(viewMatrix) == true);
}

TEST_CASE("Scene: Render Test Scene")
{
  Scene sceneTest = Scene();
  const char * fileNamePass = "scene1Cam4.test";
  sceneTest.readScene(fileNamePass);

  //sceneTest.renderScene();
}
