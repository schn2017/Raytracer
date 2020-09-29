#include "Vector3.h"

////////////////////////////////////////////////////////////////////////////////
// Class Constructor Functions
Vector3::Vector3(float xx, float yy, float zz){
  x = xx;
  y = yy;
  z = zz;
}

Vector3::Vector3()
{

}
////////////////////////////////////////////////////////////////////////////////
//Convert Vector3 to String
std::string Vector3::toString()
{
  return "Vector3 - X: " + std::to_string(x) + " Y: " + std::to_string(y) + " Z: " + std::to_string(z) + "\n";
}
////////////////////////////////////////////////////////////////////////////////
// Get Member Methods
float Vector3::getX(){
  return x;
}

float Vector3::getY(){
  return y;
}

float Vector3::getZ(){
  return z;
}
////////////////////////////////////////////////////////////////////////////////
// Comparison Method
bool Vector3::isEqual(Vector3 other){

  if (getX() != other.getX()
      || getY() != other.getY()
      || getZ() != other.getZ())
      {
        return false;
      }

  return true;
}
////////////////////////////////////////////////////////////////////////////////
//Operator Overrides
Vector3 Vector3::operator+(const Vector3 &otherVector)
{
  float xx = x + otherVector.x;
  float yy = y + otherVector.y;
  float zz = z + otherVector.z;

  return Vector3(xx, yy , zz);
}

Vector3 Vector3::operator-(const Vector3 &otherVector)
{
  float xx = x - otherVector.x;
  float yy = y - otherVector.y;
  float zz = z - otherVector.z;

  return Vector3(xx, yy, zz);
}

Vector3 Vector3::operator*(const float &scalar)
{
  float xx = x * scalar;
  float yy = y * scalar;
  float zz = z * scalar;

  return Vector3(xx, yy, zz);
}

bool Vector3::operator==(Vector3 &otherVector)
{
  return x == otherVector.x && y == otherVector.y && z == otherVector.z;
}
////////////////////////////////////////////////////////////////////////////////
