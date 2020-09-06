#include "catch.hpp"
#include "Camera.h"

TEST_CASE("Camera: Construction")
{
  Camera cam = Camera(1, 2, 3, 4, 5, 6, 7, 8, 9, 30);

  REQUIRE(cam.getLookFrom().isEqual(Vector3(1,2,3)) == true);
  REQUIRE(cam.getLookAt().isEqual(Vector3(4,5,6)) == true);
  REQUIRE(cam.getUp().isEqual(Vector3(7,8,9)) == true);
  REQUIRE(cam.getFOVY() == 30);
}

TEST_CASE("Camera: Calculate Field Of View X Axis")
{
  Camera cam = Camera(1, 2, 3, 4, 5, 6, 7, 8, 9, 30);
  cam.setDimensions(100, 100);

  float fovXAngle = cam.calculateFOVX();
  REQUIRE(fovXAngle == MathHelper::radians(cam.getFOVY()));
}

TEST_CASE("Camera: Convert Pixel Sample to Camera View Dimensions")
{
  Sample testSample = Sample(0, 5);
  Camera cam = Camera(1, 2, 3, 4, 5, 6, 7, 8, 9, 30);
  cam.setDimensions(20, 20);
  cam.calculateFOVX();

  Vector3 testVector = cam.convertSampleToCameraView(testSample);
  testVector.toString();

  //REQUIRES need to be completed


}

TEST_CASE("Camera: Create A Primary Ray")
{
  Camera cam = Camera(1, 2, 3, 4, 5, 6, 7, 8, 9, 30);
  Vector3 direction = Vector3(0,0,1);
  Ray cameraRay = cam.createRay(direction);

  REQUIRE(cameraRay.getOrigin().isEqual(cam.getLookFrom()) == true);
  REQUIRE(cameraRay.getDirection().isEqual(direction) == true);
}


TEST_CASE("Camera: Set Look From Vector")
{
  Camera cam = Camera(1, 2, 3, 4, 5, 6, 7, 8, 9, 30);

  cam.setLookFrom(Vector3 (9, 9, 9));

  REQUIRE(cam.getLookFrom().isEqual(Vector3 (9,9,9)));

}

TEST_CASE("Camera: Set Look At Vector")
{
  Camera cam = Camera(1, 2, 3, 4, 5, 6, 7, 8, 9, 30);

  cam.setLookAt(Vector3 (9, 9, 9));

  REQUIRE(cam.getLookAt().isEqual(Vector3 (9, 9, 9)));

}

TEST_CASE("Camera: Set Up Vector")
{
  Camera cam = Camera(1, 2, 3, 4, 5, 6, 7, 8, 9, 30);

  cam.setUp(Vector3 (9, 9, 9));

  REQUIRE(cam.getUp().isEqual(Vector3 (9 , 9, 9)));

}

TEST_CASE("Camera: Set Field of View Y Axis")
{
  Camera cam = Camera(1, 2, 3, 4, 5, 6, 7, 8, 9, 30);

  cam.setFOVY(90);

  REQUIRE(cam.getFOVY() == 90);
}

TEST_CASE("Camera: Set Image Dimensions")
{
  Camera cam = Camera(1, 2, 3, 4, 5, 6, 7, 8, 9, 30);
  cam.setDimensions(200, 100);

  REQUIRE(cam.getHeight() == 200);
  REQUIRE(cam.getWidth() == 100);
}
