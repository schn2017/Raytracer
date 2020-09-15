#include "Camera.h"

Camera::Camera(float lookFromX, float lookFromY, float lookFromZ,
       float lookAtX, float lookAtY, float lookAtZ,
       float upX, float upY, float upZ, float fovYAxis)
{
  lookFrom = Vector3(lookFromX, lookFromY, lookFromZ);
  lookAt = Vector3(lookAtX, lookAtY, lookAtZ);
  up = MathHelper::normalize(Vector3(upX, upY, upZ));
  fovY = fovYAxis;
}

Camera::Camera()
{
}

Ray Camera::createRay(Vector3 direction)
{
  return Ray(lookFrom, direction);
}

Vector3 Camera::convertSampleToCameraView(Sample sample)
{
  Vector3 w = MathHelper::normalize(lookFrom);
  Vector3 u = MathHelper::normalize(MathHelper::cross(up, w));
  Vector3 v = MathHelper::cross(w, u);

  float alpha = tan(fovX / 2) * sample.getColumn();
  float beta =  tan(MathHelper::radians(fovY / 2)) * sample.getRow();

  Vector3 convSample = (u * alpha) + (v * beta) - w;

  return MathHelper::normalize(convSample);
}

void Camera::calculateFOVX()
{
  fovX = 2 * atan(tan(MathHelper::radians(fovY / 2)) * (width / height));
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

float Camera::getHeight()
{
  return height;
}

float Camera::getWidth()
{
  return width;
}


float Camera::getFOVY()
{
  return fovY;
}

void Camera::setFOVY(float newFOV)
{
  fovY = newFOV;
}

float Camera::getFOVX()
{
  return fovX;
}

void Camera::setFOVX(float newFOV)
{
  fovX = newFOV;
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

void Camera::setDimensions(int heightValue, int widthValue)
{
  height = heightValue;
  width = widthValue;
}
