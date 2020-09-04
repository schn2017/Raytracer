#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include "Camera.h"
#include "Materials.h"
#include "Raytracer.h"
#include "Pixels.h"
#include "SceneSampler.h"
#include "Sphere.h"
#include "Transform.h"
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
  stack<Matrix4> getTransformStack();
  Vector3 getVertex(int element);
  vector<Object> getObjects();
  vector<Sphere> getSpheres();
  vector<Triangle> getTriangles();
  void renderScene();

private:
  Camera sceneCamera;
  int depth;
  int height;
  int width;
  Pixels film;
  Raytracer tracer;
  SceneSampler sampler;
  stack<Matrix4> transformStack;
  vector<Object> objects;
  vector<Sphere> spheres;
  vector<Triangle> triangles;
  vector<Vector3> vertices;
};
