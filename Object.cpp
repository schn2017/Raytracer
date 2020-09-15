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
    std::cout <<"Sphere\n";
    objSphere.getHomoPosition().toString();
    objSphere.setHomoPosition(MathHelper::multiply(objTransform, objSphere.getHomoPosition()));
    objSphere.getHomoPosition().toString();      
    objSphere.getPosition().toString();
    Vector3 newPosition = Vector3(objSphere.getHomoPosition().getX() / objSphere.getHomoPosition().getW(),
                                  objSphere.getHomoPosition().getY() / objSphere.getHomoPosition().getW(),
                                  objSphere.getHomoPosition().getZ() / objSphere.getHomoPosition().getW());

    objSphere.setPosition(newPosition);
    objSphere.getPosition().toString();
  }
  else if (objTriangle.getState() == true)
  {
    std::cout << "Triangle\n";
    float x, y, z;
    x = objTriangle.getV1().getX();
    y = objTriangle.getV1().getY();
    z = objTriangle.getV1().getZ();
    Vector4 homoPosition = Vector4(x, y, z, 1);
    Vector4 transVector = MathHelper::multiply(objTransform, homoPosition);
    transVector.toString();
    Vector3 newVertex = Vector3(transVector.getX() / transVector.getW(),
                            transVector.getY() / transVector.getW(),
                            transVector.getZ() / transVector.getW());

    std::cout << "Vertex 1: ";
    objTriangle.setV1(newVertex);
    newVertex.toString();
    x = objTriangle.getV2().getX();
    y = objTriangle.getV2().getY();
    z = objTriangle.getV2().getZ();
    homoPosition = Vector4(x, y, z, 1);
    transVector = MathHelper::multiply(objTransform, homoPosition);


    newVertex = Vector3(transVector.getX() / transVector.getW(),
                transVector.getY() / transVector.getW(),
                transVector.getZ() / transVector.getW());


    objTriangle.setV2(newVertex);
    std::cout << "Vertex 2: ";
    newVertex.toString();
    x = objTriangle.getV3().getX();
    y = objTriangle.getV3().getY();
    z = objTriangle.getV3().getZ();
    homoPosition = Vector4(x, y, z, 1);
    transVector = MathHelper::multiply(objTransform, homoPosition);

    newVertex = Vector3(transVector.getX() / transVector.getW(),
                transVector.getY() / transVector.getW(),
                transVector.getZ() / transVector.getW());

    std::cout << "Vertex 3: ";
    newVertex.toString();
    objTriangle.setV3(newVertex);
  }
}
