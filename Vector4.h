#include <iostream>
#include <string>

class Vector4{
  public:
    //Constructors
    Vector4(float x, float y, float z, float w);
    Vector4();
    //Get Member Definitions
    float getX();
    float getY();
    float getZ();
    float getW();
    //Comparison between Vectors, need to change to overridden operator
    bool isEqual(Vector4 other);
    //Convert Vector3 to String Defintion
    std::string toString();
  private:
    float x;
    float y;
    float z;
    float w;
};
