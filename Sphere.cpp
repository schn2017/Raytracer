#include "Sphere.h"

Sphere::Sphere(float x, float y, float z, float r)
{
  position = Vector3(x, y, z);
  radius = r;
}

Vector3 Sphere::getPosition()
{
  return position;
}

float Sphere::getRadius()
{
  return radius;
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
