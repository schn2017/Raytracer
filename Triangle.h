#pragma once

#include "Shape.h"
#include <iostream>

class Triangle : public Shape
{
public:
  //Constructors
  Triangle(Vector3 v1, Vector3 v2, Vector3 v3);
  Triangle();
  //Get Member Definitions
  Vector3 getV1();
  Vector3 getV2();
  Vector3 getV3();
  bool getState();
  //Set Member Defitions
  void setV1(Vector3 newVector);
  void setV2(Vector3 newVector);
  void setV3(Vector3 newVector);
  void changeState(bool &newState);
  //Method Definitions to determine if ray intersects Triangle
  bool intersect(Ray &cameraRay);
  //Method Definition to calculate the surface normal given a point
  Vector3 calculateSurfaceNormal();
  void applyModelViewMatrix(Matrix4 modelViewMatrix);
private:
  Vector3 v1;
  Vector3 v1Normal;
  Vector3 v2;
  Vector3 v2Normal;
  Vector3 v3;
  Vector3 v3Normal;
  bool state;
  float u;
  float v;
  float w;
};
