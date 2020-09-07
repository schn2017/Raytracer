#include "Vector4.h"

Vector4::Vector4(float xx, float yy, float zz, float ww){
  x = xx;
  y = yy;
  z = zz;
  w = ww;
}

Vector4::Vector4()
{
  
}

float Vector4::getX(){
  return x;
}

float Vector4::getY(){
  return y;
}

float Vector4::getZ(){
  return z;
}

float Vector4::getW(){
  return w;
}

bool Vector4::isEqual(Vector4 other){

  if (getX() != other.getX()
      || getY() != other.getY()
      || getZ() != other.getZ()
      || getW() != other.getW())
      {
        return false;
      }

  return true;
}
