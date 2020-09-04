#include "Materials.h"
#include "Sphere.h"
#include "Triangle.h"

class Object
{
  public:
    //Constructors
    Object();
    //Get Member Definitions
    Materials getMaterials();
    Sphere getSphere();
    Triangle getTriangle();
    //Set Member Definitions
    void setMaterials(Materials newMaterials);
    void setSphere(Sphere newSphere);
    void setTriangle(Triangle newTriangle);

  private:
    Materials objMaterials;
    Triangle objTriangle;
    Sphere objSphere;
};
