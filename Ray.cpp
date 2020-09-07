#include "Ray.h"

Ray::Ray(Vector3 ori, Vector3 dir)
{
  origin = ori;
  direction = dir;
}

Vector3 Ray::getDirection()
{
  return direction;
}

Vector3 Ray::getOrigin()
{
  return origin;
}

float Ray::getT()
{
  return t;
}

void Ray::setT(float value)
{
  t = value;
}

Vector3 Ray::getIntersection()
{
  return origin + (direction * t);
}

void Ray::toString()
{
  //std::cout<< "Ray: Origin @ ";
  //origin.toString();
  //std::cout << "Direction @ ";
  //direction.toString();
}
