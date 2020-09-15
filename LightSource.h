#include "PointLight.h"
#include <vector>

using namespace std;
class LightSource
{
public:
  //Constructors
  LightSource();
  //Get Member Definitions
  PointLight getPointLight();
  //Set Member Definitions
  void setPointLight(PointLight newPointLight);
  void applyViewMatrix(Matrix4 viewMatrix);
private:
  PointLight pointLight;
};
