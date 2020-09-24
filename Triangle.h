#pragma once

#include "Shape.h"
#include <iostream>
#include <string>

class Triangle : public Shape
{
public:
  //Constructors
  Triangle(Point vertex1, Point vertex2, Point vertex3);
  Triangle();
  //Get Member Definitions
  Point getP1();
  Point getP2();
  Point getP3();
  bool getState();
  //Set Member Defitions
  void setP1(Point newPoint);
  void setP2(Point newPoint);
  void setP3(Point newPoint);
  void changeState(bool &newState);
  //Method Definitions to determine if ray intersects Triangle
  bool intersect(Ray &cameraRay);
  //Method Definition to calculate the surface normal given a point
  Vector3 calculateSurfaceNormal();
  void applyModelViewMatrix(Matrix4 modelViewMatrix);
  std::string toString();
private:
  Point p1;
  //Point3 v1Normal;
  Point p2;
  //Point3 v2Normal;
  Point p3;
  //Point3 v3Normal;
  bool state;
  float u;
  float v;
  float w;
};
