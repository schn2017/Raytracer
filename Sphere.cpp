#include "Sphere.h"

////////////////////////////////////////////////////////////////////////////////
//Class Constructor Functions
Sphere::Sphere(float x, float y, float z, float r)
{
  position = Vector3(x, y, z);
  homoPosition = Vector4(x, y, z, 1);
  radius = r;
  state = true;
}

Sphere::Sphere()
{
  state = false;
}
////////////////////////////////////////////////////////////////////////////////
//Get Member Functions
bool Sphere::getState()
{
  return state;
}

Vector3 Sphere::getPosition()
{
  return position;
}

Vector4 Sphere::getHomoPosition()
{
  return homoPosition;
}

float Sphere::getRadius()
{
  return radius;
}
////////////////////////////////////////////////////////////////////////////////
//Set Member Functions
void Sphere::setPosition(Vector3 pos)
{
  position = pos;
}

void Sphere::setHomoPosition(Vector4 homoPos)
{
  homoPosition = homoPos;
}

void Sphere::changeState(bool &newState)
{
  state = newState;
}
////////////////////////////////////////////////////////////////////////////////
//Method to determine if ray intersects Triangle
bool Sphere::intersect(Ray &cameraRay)
{
  float a = MathHelper::dot(cameraRay.getDirection(), cameraRay.getDirection());
  float b = MathHelper::dot(cameraRay.getDirection(), cameraRay.getOrigin() - position) * 2;
  float c = MathHelper::dot(cameraRay.getOrigin() - position, cameraRay.getOrigin() - position) - (radius * radius);
  float t0 = 0;
  float t1 = 0;
  float temp = 0;

  if (!MathHelper::solveQuadratic(a, b, c, t0, t1))
  {
    return false;
  }

  if (t0 > t1)
  {
    temp = t0;
    t0 = t1;
    t1 = temp;
  }

  if (t0 < 0)
  {
    t0 = t1;

    if (t0 < 0)
    {
      return false;
    }
  }
  cameraRay.setT(t0);
  return true;
}
////////////////////////////////////////////////////////////////////////////////
//Method to calculate the surface normal given a point
Vector3 Sphere::calculateSurfaceNormal(Vector3 point)
{
  return MathHelper::normalize(point - position);
}
////////////////////////////////////////////////////////////////////////////////
