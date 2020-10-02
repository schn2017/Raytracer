#pragma once

#include "RGB.h"

class Materials
{
public:
  Materials();
  Materials(RGB diff, RGB spec, float shiny, RGB emiss, float reflect);

  float getShininess();
  RGB getDiffuse();
  RGB getSpecular();
  RGB getEmission();
  RGB getAmbient();
  float getReflectivity();

  void setAmbient(RGB value);
  void setDiffuse(RGB value);
  void setEmission(RGB value);
  void setReflectivity(float value);
  void setShininess(float value);
  void setSpecular(RGB value);

private:
  RGB ambient;
  RGB diffuse;
  RGB specular;
  float shininess;
  RGB emission;
  float reflectivity;
};
