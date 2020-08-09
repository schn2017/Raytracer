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
