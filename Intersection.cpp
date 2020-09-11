#include "Intersection.h"

////////////////////////////////////////////////////////////////////////////////
// Class Constructor Functions
Intersection::Intersection(float newDistance, Materials newMaterials)
{
  t = newDistance;
  materials = newMaterials;
  state = true;
}

Intersection::Intersection()
{
  state = false;
}
////////////////////////////////////////////////////////////////////////////////
// Get Member Functions
bool Intersection::getState()
{
  return state;
}

float Intersection::getDistance()
{
  return t;
}

Materials Intersection::getMaterials()
{
  return materials;
}

Vector3 Intersection::getSurfaceNormal()
{
  return surfaceNormal;
}
////////////////////////////////////////////////////////////////////////////////
// Set Member Functions
void Intersection::setState(bool newState)
{
  state = newState;
}

void Intersection::setDistance(float newDistance)
{
  t = newDistance;
}

void Intersection::setMaterials(Materials newMaterials)
{
  materials = newMaterials;
}

void Intersection::setSurfaceNormal(Vector3 normal)
{
  surfaceNormal = normal;
}
////////////////////////////////////////////////////////////////////////////////
