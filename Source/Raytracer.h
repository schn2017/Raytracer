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
  //Constructors
  Raytracer();
  Raytracer(vector<Object> objectVector, Lighting lights, int recursionDepth);
  //Method definition to get color of a camera ray intersection
  RGB getColor(Ray hitRay);

private:
  vector<Object> objects;
  Lighting sceneLights;
  int depth;
  //Method definition to trace a ray to determine if it intersects objects
  Intersection traceRay(Ray &hitRay);
  //Method definition to find find intersecion with the lowest distance value
  Intersection findClosestIntersection(vector<Intersection> intersections);
  //Method definition to trace a ray to determine if it intersects objects
  RGB traceLightRays(Intersection intersection);
  RGB traceReflactionRay(Ray &ray);


};
