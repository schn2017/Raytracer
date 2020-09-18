#include "Triangle.h"

////////////////////////////////////////////////////////////////////////////////
//Class Constructor Functions
Triangle::Triangle(Vector3 vertex1, Vector3 vertex2, Vector3 vertex3)
{
  v1 = vertex1;
  v2 = vertex2;
  v3 = vertex3;
  state = true;
}

Triangle::Triangle()
{
  state = false;
}
////////////////////////////////////////////////////////////////////////////////
//Get Member Functions
bool Triangle::getState()
{
  return state;
}

void Triangle::changeState(bool &newState)
{
  state = newState;
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
////////////////////////////////////////////////////////////////////////////////
//Set Member Functions
void Triangle::setV1(Vector3 newVector)
{
  v1 = newVector;
}

void Triangle::setV2(Vector3 newVector)
{
  v2 = newVector;
}

void Triangle::setV3(Vector3 newVector)
{
  v3 = newVector;
}
////////////////////////////////////////////////////////////////////////////////
//Method to determine if ray intersects Triangle
bool Triangle::intersect(Ray &cameraRay)
{
  //std::cout << "Triangle Intersect" << "\n";

  Vector3 A = v2 - v1;
  //std::cout << "A ";
//  A.toString();
  Vector3 B = v3 - v1;
  //std::cout << "B ";
  //B.toString();

  Vector3 C = MathHelper::cross(A, B);
  //std::cout << "C ";
  Vector3 surfaceNormal = C;
//  C.toString();
  Vector3 triangleNormal = MathHelper::normalize(C);
  //std::cout << "Normal ";
  //triangleNormal.toString();

  float numerator = MathHelper::dot(A, triangleNormal) - MathHelper::dot(cameraRay.getOrigin(), triangleNormal);
  float denominator = MathHelper::dot(cameraRay.getDirection(), triangleNormal);

  if (denominator == 0)
  {
    return false;
  }

  float distance = numerator / denominator;
  //std::cout << "The numerator is " << numerator << "\n";
  //std::cout << "The denominator is " << denominator << "\n";
  //std::cout << "The distance is " << distance << "\n";

  if (distance < 0)
  {
    return false;
  }

  cameraRay.setT(distance);
  Vector3 intersectionPoint = cameraRay.getIntersectionPoint();
  //std::cout << "The intersection point is ";
  //intersectionPoint.toString();

  float paralleogramArea = MathHelper::magnitude(MathHelper::cross(A, B));
  float triangleArea = paralleogramArea / 2;

  //std::cout << "\nThe area of the paralleogram is " << paralleogramArea << "\n";
  //std::cout << "The area of the triangle is " << triangleArea << "\n";

  //Edge 1
  //std::cout << "\nEDGE 1\n";
  Vector3 edge = v2 - v1;
  Vector3 edgeToPoint = intersectionPoint - v1;
  //edge.toString();
  //edgeToPoint.toString();
  C = MathHelper::cross(edge, edgeToPoint);
  if (MathHelper::dot(surfaceNormal, C) < 0)  return false;

  //C.toString();
  //std::cout << "The area of the triangle is " << MathHelper::magnitude(C) << "\n";
  w = (MathHelper::magnitude(C) / 2) / triangleArea;
  //std::cout << "W: " << w << "\n";

  //Edge2
  //std::cout << "\nEDGE 2\n";
  edge = v3 - v2;
  edgeToPoint = intersectionPoint - v2;
  //edge.toString();
  //edgeToPoint.toString();
  C = MathHelper::cross(edge, edgeToPoint);
  if (MathHelper::dot(surfaceNormal, C) < 0)  return false;
  //C.toString();
  //std::cout << "The area of the triangle is " << MathHelper::magnitude(C) << "\n";
  u = (MathHelper::magnitude(C) / 2) / triangleArea;
  //std::cout << "U: " << u << "\n";

  //Edge3
  //std::cout << "\nEDGE 3\n";
  edge = v1 - v3;
  edgeToPoint = intersectionPoint - v3;
  //edge.toString();
  //edgeToPoint.toString();
  C = MathHelper::cross(edge, edgeToPoint);
  if (MathHelper::dot(surfaceNormal, C) < 0)  return false;
  //C.toString();
  //std::cout << "The area of the triangle is " << MathHelper::magnitude(C) << "\n";
  v = (MathHelper::magnitude(C) / 2) / triangleArea;
//  std::cout << "V: " << v << "\n";

  w = 1 - u - v;

  if (((u < 0) || (u > 1)) || ((v < 0) || (v > 1)) || ((w < 0) || (w > 1)))
  {
    //std::cout << "\nNO INTERSECTION\n";
    return false;
  }

  //std::cout << "W: " << w << "\n";

  //std::cout << "\nINTERSECTION\n";
  return true;
};
////////////////////////////////////////////////////////////////////////////////
Vector3 Triangle::calculateSurfaceNormal()
{
  Vector3 A = v2 - v1;
  Vector3 B = v3 - v1;

  return MathHelper::normalize(MathHelper::cross(A, B));
}
////////////////////////////////////////////////////////////////////////////////
void Triangle::applyModelViewMatrix(Matrix4 modelViewMatrix)
{
  /*  std::cout << "Pre Model View Matrix\n"<< toString();
    v1 = MathHelper::transformVector3(modelViewMatrix, v1);
    v2 = MathHelper::transformVector3(modelViewMatrix, v2);
    v3 = MathHelper::transformVector3(modelViewMatrix, v3);
    std::cout << "Post Model View Matrix\n"<< toString();
    std::cout << toString();*/
}
//
std::string Triangle::toString()
{
  return "Triangle \nVertex 1: " + v1.toString() + "Vertex 2: " + v2.toString() + "Vertex 3: " + v3.toString();

}
