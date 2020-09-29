#include "Point.h"
////////////////////////////////////////////////////////////////////////////////
// Class Constructor Functions
Point::Point(float xPos, float yPos, float zPos)
{
  x = xPos;
  y = yPos;
  z = zPos;
}

Point::Point()
{

}
////////////////////////////////////////////////////////////////////////////////
// Get Member Functions
float Point::getX()
{
  return x;
}

float Point::getY()
{
  return y;
}

float Point::getZ()
{
  return z;
}
////////////////////////////////////////////////////////////////////////////////
// Operator Overrides
Point Point::operator+(Vector3 &v1)
{
  float xx = x + v1.getX();
  float yy = y + v1.getY();
  float zz = z + v1.getZ();

  return Point(xx, yy, zz);
}

Vector3 Point::operator-(Point otherPoint)
{
  float xx = x - otherPoint.getX();
  float yy = y - otherPoint.getY();
  float zz = z - otherPoint.getZ();

  return Vector3(xx, yy, zz);
}

bool Point::operator==(const Point &otherPoint)
{
  return x == otherPoint.x && y == otherPoint.y && z == otherPoint.z;
}
////////////////////////////////////////////////////////////////////////////////
//
std::string Point::toString()
{
  return "Point - X: " + std::to_string(x) + " Y: " + std::to_string(y) + " Z: " + std::to_string(z) + "\n";
}
////////////////////////////////////////////////////////////////////////////////
