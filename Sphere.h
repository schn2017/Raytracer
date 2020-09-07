#pragma once

#include "Shape.h"
#include <iostream>

class Sphere: public Shape
{
public:
  Sphere(float x, float y, float z, float r);
  Sphere();
  Vector3 getPosition();
  Vector4 getHomoPosition();
  float getRadius();
  bool intersect(Ray &cameraRay);
  bool getState();
  void changeState(bool &newState);
  void setPosition(Vector3 pos);
  void setHomoPosition(Vector4 homoPos);

private:
  Vector3 position;
  Vector4 homoPosition;
  float radius;
  bool state;
};
