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
  RGB getColor(Ray hitRay);

private:
  vector<Object> objects;
  Lighting sceneLights;

  Intersection traceRay(Ray &hitRay);
  Intersection findClosestIntersection(vector<Intersection> intersections);
  RGB traceLightRays(Ray hitRay, Intersection intersection);  
};
