#pragma once

#include "MathHelper.h"

class Ray
{
public:
  Ray(Vector3 ori, Vector3 dir);
  Vector3 getIntersectionPoint();
  Vector3 getOrigin();
  Vector3 getDirection();
  void setT(float value);
  float getT();
  void toString();

private:
  Vector3 origin;
  Vector3 direction;
  float t;

};
