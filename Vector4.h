#include <iostream>

class Vector4{
  public:
    Vector4(float x, float y, float z, float w);
    Vector4();
    float getX();
    float getY();
    float getZ();
    float getW();

    bool isEqual(Vector4 other);
    void toString();
  private:
    float x;
    float y;
    float z;
    float w;
};
