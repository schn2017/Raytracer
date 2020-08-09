#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Camera.h"

using namespace std;
class Scene
{
public:
  Scene();
  bool readScene(const char *filename);
  bool readSceneValues(stringstream &s, const int numvals, float * values);
  Camera getCamera();
  float getDepth();
  float getHeight();
  float getWidth();
private:
  Camera sceneCamera;
  float depth;
  float height;
  float width;

};
