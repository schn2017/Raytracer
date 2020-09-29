#include "Vector3.h"
#include <string>

class Point
{
public:
  //Constructors
  Point(float xPos, float yPos, float zPos);
  Point();
  //Get Member Definitions
  float getX();
  float getY();
  float getZ();
  //Operator Override
  Point operator+(Vector3 &v1);
  Vector3 operator-(Point otherPoint);
  bool operator==(const Point &otherPoint);
  //
  std::string toString();
private:
  float x;
  float y;
  float z;
};
