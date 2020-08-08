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
private:
  Camera sceneCamera;
  float height;
  float width;

};
