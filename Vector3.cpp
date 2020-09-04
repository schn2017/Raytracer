#include "Vector3.h"

Vector3::Vector3(float xx, float yy, float zz){
  x = xx;
  y = yy;
  z = zz;
}

Vector3::Vector3()
{

}

void Vector3::toString()
{
  std::cout << "Vector3 - X: " << x << " Y: " << y << " Z: " << z << "\n";
}


float Vector3::getX(){
  return x;
}

float Vector3::getY(){
  return y;
}

float Vector3::getZ(){
  return z;
}

bool Vector3::isEqual(Vector3 other){

  if (getX() != other.getX()
      || getY() != other.getY()
      || getZ() != other.getZ())
      {
        return false;
      }

  return true;
}
