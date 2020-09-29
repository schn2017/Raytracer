#include "PointLight.h"

////////////////////////////////////////////////////////////////////////////////
// Class Constructor Functions
PointLight::PointLight(Point newPosition, RGB newColor)
{
  position = newPosition;
  lightColor = newColor;
  state = true;
}

PointLight::PointLight()
{
  state = false;
}
////////////////////////////////////////////////////////////////////////////////
// Get Member Functions
bool PointLight::getState()
{
  return state;
}

RGB PointLight::getLightColor()
{
  return lightColor;
}

Point PointLight::getPosition()
{
  return position;
}
////////////////////////////////////////////////////////////////////////////////
// Set Member Functions
void PointLight::setPosition(Point newPosition)
{
  position = newPosition;
}

void PointLight::setLightColor(RGB newColor)
{
  lightColor = newColor;
}

void PointLight::setState(bool &newState)
{
  state = newState;
}
////////////////////////////////////////////////////////////////////////////////
