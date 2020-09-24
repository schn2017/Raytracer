#include "Ray.h"
#include "Sample.h"
#include "Transform.h"

class Camera
{
public:
  Camera(float lookFromX, float lookFromY, float lookFromZ,
         float lookAtX, float lookAtY, float lookAtZ,
         float upX, float upY, float upZ, float fovYAxis);

  Camera();

  Vector3 convertSampleToCameraView(Sample sample);
  Point getLookFrom();
  Point getLookAt();
  Vector3 getUp();
  float getFOVX();
  float getFOVY();
  float getHeight();
  float getWidth();
  void calculateFOVX();

  Ray createRay(Vector3 direction);
  void setLookFrom(Point newPoint);
  void setLookAt(Point newPoint);
  void setUp(Vector3 newVector);
  void setFOVX(float newFOV);
  void setFOVY(float newFOV);
  void setDimensions(int heightValue, int widthValue);

private:
  Point lookFrom;
  Point lookAt;
  Vector3 up;
  float fovY;
  float fovX;
  float height;
  float width;
};
