#include "LightSource.h"
#include <vector>

using namespace std;
class Lighting
{
public:
  //Constructors
  Lighting();
  //Get Member Definitions
  RGB getAmbientLight();
  vector<LightSource> getLightSources();
  //Set Member Definitions
  void setAmbientLight(RGB newLight);
  //vector<LightSource> Methods
  void addLightSource(LightSource newLightSource);
  LightSource getLightSource(int lightNumber);

private:
  RGB ambientLight;
  vector<LightSource> lightSources;
};
