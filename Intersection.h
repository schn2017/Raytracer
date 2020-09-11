#include "Object.h"

class Intersection
{
public:
  //Constructors
  Intersection(float newDistance, Materials newMaterials);
  Intersection();
  //Get Member Definitions
  bool getState();
  float getDistance();
  Materials getMaterials();
  Vector3 getSurfaceNormal();
  //Set Member Definitions
  void setState(bool newState);
  void setDistance(float newDistance);
  void setMaterials(Materials newMaterials);
  void setSurfaceNormal(Vector3 normal);

private:
  bool state;
  float t;
  Materials materials;
  Vector3 surfaceNormal;
};
