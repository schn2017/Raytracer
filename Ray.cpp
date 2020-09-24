#include "Ray.h"

Ray::Ray(Point ori, Vector3 dir)
{
  origin = ori;
  direction = dir;
}

Vector3 Ray::getDirection()
{
  return direction;
}

Point Ray::getOrigin()
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

Point Ray::getIntersectionPoint()
{
  Vector3 dir = direction * t;
  return origin + dir;
}

void Ray::toString()
{
  //std::cout<< "Ray: Origin @ ";
  //origin.toString();
  //std::cout << "Direction @ ";
  //direction.toString();
}
