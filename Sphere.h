#pragma once

#include "Shape.h"
#include <iostream>

class Sphere: public Shape
{
public:
  //Constructors
  Sphere(float x, float y, float z, float r);
  Sphere();
  //Get Member Definitions
  Vector3 getPosition();
  Vector4 getHomoPosition();
  float getRadius();
  bool getState();
  //Set Member Definitions
  void changeState(bool &newState);
  void setPosition(Vector3 pos);
  void setHomoPosition(Vector4 homoPos);
  //Method Definition to determine if ray intersects sphere
  bool intersect(Ray &cameraRay);
  //Method Definition to calculate the surface normal given a point
  Vector3 calculateSurfaceNormal(Vector3 point);

  Vector3 applyModelViewMatrix(Matrix4 modelViewMatrix);
private:
  Vector3 position;
  Vector4 homoPosition;
  float radius;
  bool state;
};
