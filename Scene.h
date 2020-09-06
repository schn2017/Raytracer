#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include "Camera.h"
#include "Raytracer.h"
#include "Pixels.h"
#include "SceneSampler.h"
#include "Transform.h"

using namespace std;
class Scene
{
public:
  // Constructors
  Scene();

  // Get Member Definitions
  Camera getCamera();
  int getDepth();
  int getHeight();
  int getWidth();
  stack<Matrix4> getTransformStack();
  Vector3 getVertex(int element);
  vector<Object> getObjects();
  vector<Sphere> getSpheres();
  vector<Triangle> getTriangles();

  // Scene Setup Methods
  bool readScene(const char *filename);
  bool readSceneValues(stringstream &s, const int numvals, float * values);

  // Render Scene Methods
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
