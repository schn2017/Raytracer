#include "Vector4.h"
////////////////////////////////////////////////////////////////////////////////
// Class Constructor Functions
Vector4::Vector4(float xx, float yy, float zz, float ww){
  x = xx;
  y = yy;
  z = zz;
  w = ww;
}

Vector4::Vector4()
{

}
////////////////////////////////////////////////////////////////////////////////
// Get Member Functions
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
////////////////////////////////////////////////////////////////////////////////
//Convert Vector4 to String
std::string Vector4::toString()
{
  return "Vector4 - X: " + std::to_string(x) + " Y: " + std::to_string(y) + " Z: " + std::to_string(z) + " W: " + std::to_string(w) + "\n";
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
