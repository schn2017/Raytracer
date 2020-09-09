#include "Light.h"

class PointLight: public Light
{
public:
  //Constructors
  PointLight(Vector3 newPosition, RGB newColor);
  PointLight();
  //Get member defitions
  bool getState();
  RGB getLightColor();
  Vector3 getPosition();
  //Set Member defitions
  void setPosition(Vector3 newPosition);
  void setLightColor(RGB newColor);
  void setState(bool &newState);

private:
  bool state;
  Vector3 position;
  RGB lightColor;
};
