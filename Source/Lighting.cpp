#include "Lighting.h"

////////////////////////////////////////////////////////////////////////////////
// Class Constructor Functions
Lighting::Lighting()
{
  ambientLight = RGB(0.2, 0.2, 0.2);
};
////////////////////////////////////////////////////////////////////////////////
// Get Member Functions
RGB Lighting::getAmbientLight()
{
  return ambientLight;
}

vector<LightSource> Lighting::getLightSources()
{
  return lightSources;
}
////////////////////////////////////////////////////////////////////////////////
// Set Member Functions
void Lighting::setAmbientLight(RGB newLight)
{
  ambientLight = newLight;
}
////////////////////////////////////////////////////////////////////////////////
//vector<LightSource> Methods
void Lighting::addLightSource(LightSource newLightSource)
{
  lightSources.push_back(newLightSource);
}

LightSource Lighting::getLightSource(int lightNumber)
{
  return lightSources[lightNumber];
}
////////////////////////////////////////////////////////////////////////////////
//Apply View Matrix
void Lighting::applyViewMatrix(Matrix4 viewMatrix)
{
  for (int i = 0; i < lightSources.size(); i++)
  {
    lightSources[i].applyViewMatrix(viewMatrix);
  }
}
////////////////////////////////////////////////////////////////////////////////
