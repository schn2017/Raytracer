#include "Materials.h"

Materials::Materials()
{

}

Materials::Materials(RGB diff, RGB spec, float shiny, RGB emiss)
{
  diffuse = diff;
  specular = spec;
  shininess = shiny;
  emission = emiss;

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

RGB Materials::getSpecular()
{
  return specular;
}

void Materials::setDiffuse(RGB value)
{
  diffuse = value;
}

void Materials::setEmission(RGB value)
{
  emission = value;
}

void Materials::setShininess(float value)
{
  shininess = value;
}

void Materials::setSpecular(RGB value)
{
  specular = value;
}
