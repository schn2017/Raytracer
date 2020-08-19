#include "Camera.h"

Camera::Camera(float lookFromX, float lookFromY, float lookFromZ,
       float lookAtX, float lookAtY, float lookAtZ,
       float upX, float upY, float upZ, float fovy)
{
  lookFrom = Vector3(lookFromX, lookFromY, lookFromZ);
  lookAt = Vector3(lookAtX, lookAtY, lookAtZ);
  up = Vector3(upX, upY, upZ);
  fov = fovy;
}

Camera::Camera()
{
}

Ray Camera::createRay(Vector3 direction)
{
  return Ray(lookFrom, direction);
}


Vector3 Camera::getLookFrom()
{
  return lookFrom;
}

Vector3 Camera::getLookAt()
{
  return lookAt;
}

Vector3 Camera::getUp()
{
  return up;
}

float Camera::getFOV()
{
  return fov;
}

void Camera::setFOV(float newFOV)
{
  fov = newFOV;
}

void Camera::setLookFrom(Vector3 newVector)
{
  lookFrom = newVector;
}

void Camera::setLookAt(Vector3 newVector)
{
  lookAt = newVector;
}

void Camera::setUp(Vector3 newVector)
{
  up = newVector;
}
