#include "Light.h"

class PointLight: public Light
{
public:
  //Constructors
  PointLight(Point newPosition, RGB newColor);
  PointLight();
  //Get member defitions
  bool getState();
  RGB getLightColor();
  Point getPosition();
  //Set Member defitions
  void setPosition(Point newPosition);
  void setLightColor(RGB newColor);
  void setState(bool &newState);

private:
  bool state;
  Point position;
  RGB lightColor;
};
