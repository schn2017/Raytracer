#include "Shape.h"
#include <iostream>

class Sphere: public Shape
{
public:
  Sphere(float x, float y, float z, float r);
  Vector3 getPosition();
  float getRadius();
  bool intersect(Ray &cameraRay);
private:
  Vector3 position;
  float radius;
};
