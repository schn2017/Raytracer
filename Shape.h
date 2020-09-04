#pragma once

#include "Ray.h"

class Shape
{
public:
  virtual ~Shape() {};

  virtual bool intersect(Ray &cameraRay) = 0;
  virtual bool getState() = 0;
  virtual void changeState(bool &newState) = 0;

private:

};
