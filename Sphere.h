#include "Vector3.h"

class Sphere
{
public:
  Sphere(float x, float y, float z, float r);
  Vector3 getPosition();
  float getRadius();

private:
  Vector3 position;
  float radius;
};
