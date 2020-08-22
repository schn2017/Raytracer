#pragma once

#include "Ray.h"

class Shape
{
public:
  virtual ~Shape() {};

  virtual bool intersect(Ray &cameraRay) = 0;
private:

};
