#pragma once
#include <iostream>
#include <string>

class Vector3{
  public:
    //Constructors
    Vector3(float x, float y, float z);
    Vector3();
    //Get Member Definitions
    float getX();
    float getY();
    float getZ();
    //Comparison between Vectors, need to change to overridden operator
    bool isEqual(Vector3 other);
    //Convert Vector3 to String Defintion
    std::string toString();
    //Operator Overides
    Vector3 operator+(const Vector3 &otherVector);
    Vector3 operator-(const Vector3 &otherVector);
    Vector3 operator*(float scalar);
    bool operator==(Vector3 &otherVector);
  private:
    float x;
    float y;
    float z;;
};
