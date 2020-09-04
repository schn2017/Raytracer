#include "Object.h"
#include "Ray.h"
#include "RGB.h"
#include <iostream>
#include <vector>

using namespace std;

class Raytracer
{
public:
  Raytracer();
  Raytracer(vector<Object> objectVector);

  RGB traceRay(Ray hitRay);

private:
  vector<Object> objects;

};
