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
  Point getIntersectionPoint();
  //Set Member Definitions
  void setState(bool newState);
  void setDistance(float newDistance);
  void setMaterials(Materials newMaterials);
  void setSurfaceNormal(Vector3 normal);
  void setIntersectionPoint(Point newPoint);

private:
  bool state;
  float t;
  Materials materials;
  Vector3 surfaceNormal;
  Point intersectionPoint;
};
