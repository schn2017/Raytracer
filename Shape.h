#pragma once

#include "MathHelper.h"
#include "Ray.h"
#include "Vector3.h"

class Shape
{
public:
  virtual ~Shape() {};

  virtual bool intersect(Ray &cameraRay) = 0;
private:

};
