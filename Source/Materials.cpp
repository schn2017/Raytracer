#include "Materials.h"

Materials::Materials()
{
  ambient = RGB(0, 0, 0);
  diffuse = RGB(0, 0, 0);
  specular = RGB(0, 0, 0);
  shininess = 0;
  emission = RGB(0, 0, 0);
  reflectivity = 0;
}

Materials::Materials(RGB diff, RGB spec, float shiny, RGB emiss, float reflect)
{
  diffuse = diff;
  specular = spec;
  shininess = shiny;
  emission = emiss;
  reflectivity = reflect;
}

RGB Materials::getAmbient()
{
  return ambient;
}

float Materials::getShininess()
{
  return shininess;
}

RGB Materials::getDiffuse()
{
  return diffuse;
}

RGB Materials::getEmission()
{
  return emission;
}

float Materials::getReflectivity()
{
  return reflectivity;
}

RGB Materials::getSpecular()
{
  return specular;
}

void Materials::setAmbient(RGB value)
{
  ambient = value;
}

void Materials::setDiffuse(RGB value)
{
  diffuse = value;
}

void Materials::setEmission(RGB value)
{
  emission = value;
}

void Materials::setReflectivity(float value)
{
  reflectivity = value;
}

void Materials::setShininess(float value)
{
  shininess = value;
}

void Materials::setSpecular(RGB value)
{
  specular = value;
}
