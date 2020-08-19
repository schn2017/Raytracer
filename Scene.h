#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Camera.h"
#include "Pixels.h"
#include "SceneSampler.h"
#include "Shape.h"
#include "Sphere.h"
#include "Triangle.h"

using namespace std;
class Scene
{
public:
  Scene();
  bool readScene(const char *filename);
  bool readSceneValues(stringstream &s, const int numvals, float * values);
  Camera getCamera();
  int getDepth();
  int getHeight();
  int getWidth();
  Vector3 getVertex(int element);
  vector<Sphere> getSpheres();
  vector<Triangle> getTriangles();
  void renderScene();

private:
  Camera sceneCamera;
  int depth;
  int height;
  int width;
  Pixels film;
  SceneSampler sampler;
  vector<Sphere> spheres;
  vector<Triangle> triangles;
  vector<Vector3> vertices;
};
