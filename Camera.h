#include "Ray.h"
#include "Sample.h"

class Camera
{
public:
  Camera(float lookFromX, float lookFromY, float lookFromZ,
         float lookAtX, float lookAtY, float lookAtZ,
         float upX, float upY, float upZ, float fovYAxis);

  Camera();

  Vector3 convertSampleToCameraView(Sample sample);
  Vector3 getLookFrom();
  Vector3 getLookAt();
  Vector3 getUp();
  float getFOVX();
  float getFOVY();
  float calculateFOVX();

  Ray createRay(Vector3 direction);
  void setLookFrom(Vector3 newVector);
  void setLookAt(Vector3 newVector);
  void setUp(Vector3 newVector);
  void setFOVX(float newFOV);
  void setFOVY(float newFOV);
  void setDimensions(float heightt, float widthh);

private:
  Vector3 lookFrom = Vector3();
  Vector3 lookAt = Vector3();
  Vector3 up = Vector3();
  float fovY;
  float fovX;
  float height;
  float width;
};
