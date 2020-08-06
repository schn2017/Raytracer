#include "Vector3.h"

class Camera
{
public:
  Camera(float lookFromX, float lookFromY, float lookFromZ,
         float lookAtX, float lookAtY, float lookAtZ,
         float upX, float upY, float upZ, float fov);

  Vector3 getLookFrom();
  Vector3 getLookAt();
  Vector3 getUp();
  float getFOV();

  void setLookFrom(Vector3 newVector);
  void setLookAt(Vector3 newVector);
  void setUp(Vector3 newVector);
  void setFOV(float newFOV);

private:
  Vector3 lookFrom = Vector3(0,0,0);
  Vector3 lookAt = Vector3(0,0,0);
  Vector3 up = Vector3(0,0,0);
  float fov;

};
