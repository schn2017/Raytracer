#include "Object.h"
#include "Ray.h"
#include "RGB.h"
#include "Lighting.h"
#include "Intersection.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Raytracer
{
public:
  Raytracer();
  Raytracer(vector<Object> objectVector, Lighting lights);

  Intersection traceRay(Ray &hitRay);
  RGB traceLightRays(Ray hitRay, Intersection intersection);
  RGB getColor(Ray hitRay);

private:
  vector<Object> objects;
  Lighting sceneLights;
};
