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
// Method to apply transform to Sphere/Triangle vector(s)
void Object::applyTransform()
{
  if (objSphere.getState() == true)
  {
    objSphere.applyModelViewMatrix(objTransform);
  }
  else if (objTriangle.getState() == true)
  {
    objTriangle.applyModelViewMatrix(objTransform);
  }
}
