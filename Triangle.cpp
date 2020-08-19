#include "Triangle.h"

Triangle::Triangle(Vector3 vertex1, Vector3 vertex2, Vector3 vertex3)
{
  v1 = vertex1;
  v2 = vertex2;
  v3 = vertex3;
}

Vector3 Triangle::getV1()
{
  return v1;
}

Vector3 Triangle::getV2()
{
  return v2;
}

Vector3 Triangle::getV3()
{
  return v3;
}

bool Triangle::intersect(Ray &cameraRay)
{
  std::cout << "Triangle Intersect" << "\n";
  return true;
}
