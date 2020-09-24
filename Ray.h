#pragma once

#include "MathHelper.h"

class Ray
{
public:
  Ray(Point ori, Vector3 dir);
  Point getIntersectionPoint();
  Point getOrigin();
  Vector3 getDirection();
  void setT(float value);
  float getT();
  void toString();

private:
  Point origin;
  Vector3 direction;
  float t;
};
