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
  float getHeight();
  float getWidth();
  Lighting getLighting();
  stack<Matrix4> getTransformStack();
  Point getVertex(int element);
  vector<Object> getObjects();
  vector<Sphere> getSpheres();
  vector<Triangle> getTriangles();

  // Set Member Definitions
  void setViewMatrix(Matrix4 m1);

  // Scene Setup Method
  bool readScene(const char *filename);

  // Scene Setup Helper Functions
  bool readSceneValues(stringstream &s, const int numvals, float * values);

  // Render Scene Method
  void renderScene();

  // Render Scene Helper Functions
  void applyViewMatrix();

private:
  Camera sceneCamera;
  int depth;
  float height;
  float width;
  Lighting sceneLights;
  Pixels film;
  Raytracer tracer;
  SceneSampler sampler;
  Matrix4 viewMatrix;
  stack<Matrix4> transformStack;
  vector<Object> objects;
  vector<Sphere> spheres;
  vector<Triangle> triangles;
  vector<Point> vertices;
};
