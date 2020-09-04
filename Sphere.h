#pragma once

#include "Shape.h"
#include <iostream>

class Sphere: public Shape
{
public:
  Sphere(float x, float y, float z, float r);
  Sphere();
  Vector3 getPosition();
  float getRadius();
  bool intersect(Ray &cameraRay);
  bool getState();
  void changeState(bool &newState);
private:
  Vector3 position;
  float radius;
  bool state;
};
