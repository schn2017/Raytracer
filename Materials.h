#pragma once

#include "RGB.h"

class Materials
{
public:
  Materials();
  Materials(RGB diff, RGB spec, float shiny, RGB emiss);

  float getShininess();
  RGB getDiffuse();
  RGB getSpecular();
  RGB getEmission();

  void setDiffuse(RGB value);
  void setEmission(RGB value);
  void setShininess(float value);
  void setSpecular(RGB value);

private:
  RGB diffuse;
  RGB specular;
  float shininess;
  RGB emission;
};
