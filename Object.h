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
    Matrix4 getTransform();    
    Triangle getTriangle();
    //Set Member Definitions
    void setMaterials(Materials newMaterials);
    void setSphere(Sphere newSphere);
    void setTransform(Matrix4 newTransform);
    void setTriangle(Triangle newTriangle);

  private:
    Materials objMaterials;
    Triangle objTriangle;
    Sphere objSphere;
    Matrix4 objTransform;
};
