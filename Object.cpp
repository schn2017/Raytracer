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

void Object::setTriangle(Triangle newTriangle)
{
  objTriangle = newTriangle;
}
////////////////////////////////////////////////////////////////////////////////
