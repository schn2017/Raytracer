#include "Triangle.h"

////////////////////////////////////////////////////////////////////////////////
//Class Constructor Functions
Triangle::Triangle(Point vertex1, Point vertex2, Point vertex3)
{
  p1 = vertex1;
  p2 = vertex2;
  p3 = vertex3;
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

Point Triangle::getP1()
{
  return p1;
}

Point Triangle::getP2()
{
  return p2;
}

Point Triangle::getP3()
{
  return p3;
}
////////////////////////////////////////////////////////////////////////////////
//Set Member Functions
void Triangle::setP1(Point newPoint)
{
  p1 = newPoint;
}

void Triangle::setP2(Point newPoint)
{
  p2 = newPoint;
}

void Triangle::setP3(Point newPoint)
{
  p3 = newPoint;
}
////////////////////////////////////////////////////////////////////////////////
//Method to determine if ray intersects Triangle
bool Triangle::intersect(Ray &cameraRay)
{
  //std::cout << "Triangle Intersect" << "\n";
  Vector3 A = p2 - p1;
  //std::cout << "A ";
//  A.toString();
  Vector3 B = p3 - p1;
  //std::cout << "B ";
  //B.toString();

  Vector3 C = MathHelper::cross(A, B);
  //std::cout << "C ";
  Vector3 surfaceNormal = C;
//  C.toString();
  Vector3 triangleNormal = MathHelper::normalize(C);
  //std::cout << "Normal ";
  //triangleNormal.toString();

  float numerator = MathHelper::dot(A, triangleNormal) - MathHelper::dot(cameraRay.getOrigin() - Point(0,0,0), triangleNormal);
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
  Point intersectionPoint = cameraRay.getIntersectionPoint();
  //std::cout << "The intersection point is ";
  //intersectionPoint.toString();

  float paralleogramArea = MathHelper::magnitude(MathHelper::cross(A, B));
  float triangleArea = paralleogramArea / 2;

  //std::cout << "\nThe area of the paralleogram is " << paralleogramArea << "\n";
  //std::cout << "The area of the triangle is " << triangleArea << "\n";

  //Edge 1
  //std::cout << "\nEDGE 1\n";
  Vector3 edge = p2 - p1;
  Vector3 edgeToPoint = intersectionPoint - p1;
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
  edge = p3 - p2;
  edgeToPoint = intersectionPoint - p2;
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
  edge = p1 - p3;
  edgeToPoint = intersectionPoint - p3;
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
}
////////////////////////////////////////////////////////////////////////////////
Vector3 Triangle::calculateSurfaceNormal()
{
  Vector3 A = p2 - p1;
  Vector3 B = p3 - p1;

  return MathHelper::normalize(MathHelper::cross(A, B));
}
////////////////////////////////////////////////////////////////////////////////
void Triangle::applyModelViewMatrix(Matrix4 modelViewMatrix)
{/*
    v1 = MathHelper::transformPoint3(modelViewMatrix, v1);
    v2 = MathHelper::transformPoint3(modelViewMatrix, v2);
    v3 = MathHelper::transformPoint3(modelViewMatrix, v3);*/
}
//
std::string Triangle::toString()
{
  return "Triangle \nVertex 1: " + p1.toString() + "Vertex 2: " + p2.toString() + "Vertex 3: " + p3.toString();



}
