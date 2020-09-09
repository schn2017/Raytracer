#include "Object.h"

////////////////////////////////////////////////////////////////////////////////
// Class Constructor Functions
Object::Object()
{
}
////////////////////////////////////////////////////////////////////////////////
// Get Member Functions
Materials Object::getMaterials()
{
  return objMaterials;
}

Sphere Object::getSphere()
{
  return objSphere;
}

Matrix4 Object::getTransform()
{
  return objTransform;
}

Triangle Object::getTriangle()
{
  return objTriangle;
}
////////////////////////////////////////////////////////////////////////////////
// Set Member Functions
void Object::setMaterials(Materials newMaterials)
{
  objMaterials = newMaterials;
}

void Object::setSphere(Sphere newSphere)
{
  objSphere = newSphere;
}

void Object::setTransform(Matrix4 newTransform)
{
  objTransform = newTransform;
}

void Object::setTriangle(Triangle newTriangle)
{
  objTriangle = newTriangle;
}
////////////////////////////////////////////////////////////////////////////////
//
void Object::applyTransform()
{
  if (objSphere.getState() == true)
  {
    //objSphere.getHomoPosition().toString();
    objSphere.setHomoPosition(MathHelper::multiply(objTransform, objSphere.getHomoPosition()));

    Vector3 newPosition = Vector3(objSphere.getHomoPosition().getX() / objSphere.getHomoPosition().getW(),
                                  objSphere.getHomoPosition().getY() / objSphere.getHomoPosition().getW(),
                                  objSphere.getHomoPosition().getZ() / objSphere.getHomoPosition().getW());

    objSphere.setPosition(newPosition);


    //objSphere.getHomoPosition().toString();
    //objSphere.getPosition().toString();
  }
}
