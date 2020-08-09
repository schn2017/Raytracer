#include "Vector3.h"

class Triangle
{
public:
  Triangle(Vector3 v1, Vector3 v2, Vector3 v3);
  Vector3 getV1();
  Vector3 getV2();
  Vector3 getV3();


private:
  Vector3 v1;
  Vector3 v1Normal;
  Vector3 v2;
  Vector3 v2Normal;
  Vector3 v3;
  Vector3 v3Normal;
};
