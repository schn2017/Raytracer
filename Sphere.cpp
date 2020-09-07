#include "Sphere.h"

Sphere::Sphere(float x, float y, float z, float r)
{
  position = Vector3(x, y, z);
  homoPosition = Vector4(x, y, z, 1);
  radius = r;
  state = true;
}

Sphere::Sphere()
{
  state = false;
}

bool Sphere::getState()
{
  return state;
}

void Sphere::changeState(bool &newState)
{
  state = newState;
}


Vector3 Sphere::getPosition()
{
  return position;
}

Vector4 Sphere::getHomoPosition()
{
  return homoPosition;
}

float Sphere::getRadius()
{
  return radius;
}

void Sphere::setPosition(Vector3 pos)
{
  position = pos;
}

void Sphere::setHomoPosition(Vector4 homoPos)
{
  homoPosition = homoPos;
}

bool Sphere::intersect(Ray &cameraRay)
{
  float a = MathHelper::dot(cameraRay.getDirection(), cameraRay.getDirection());
  float b = MathHelper::dot(cameraRay.getDirection(), cameraRay.getOrigin() - position) * 2;
  float c = MathHelper::dot(cameraRay.getOrigin() - position, cameraRay.getOrigin() - position) - (radius * radius);
  float t0 = 0;
  float t1 = 0;
  float temp = 0;

  if (!MathHelper::solveQuadratic(a, b, c, t0, t1))
  {
    return false;
  }

  if (t0 > t1)
  {
    temp = t0;
    t0 = t1;
    t1 = temp;
  }

  if (t0 < 0)
  {
    t0 = t1;

    if (t0 < 0)
    {
      return false;
    }
  }

  return true;
}
