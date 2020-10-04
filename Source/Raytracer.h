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
  Raytracer(vector<Object> objectVector, Lighting lights);
  //Method definition to get color of a camera ray intersection
  RGB getColor(Ray hitRay, int recursionDepth);

private:
  vector<Object> objects;
  Lighting sceneLights;
  //Method definition to trace a ray to determine if it intersects objects
  Intersection traceRay(Ray &hitRay);
  //Method definition to find find intersecion with the lowest distance value
  Intersection findClosestIntersection(vector<Intersection> intersections);
  //Method definition to trace a ray to determine if it intersects objects
  RGB traceLightRays(Intersection intersection);
  float calculateLambertCoefficient(Vector3 surfaceNormal, Vector3 direction);
  float calculatePhongCoefficient(Vector3 surfaceNormal, Vector3 direction);

  RGB traceReflectionRay(Ray ray, Intersection rayIntersection, int recursionDepth);
  Ray createReflectionRay(Vector3 direction, Intersection rayIntersection);
  RGB traceRefractionRay(Ray ray, Intersection rayIntersection, int recursionDepth);
  Ray createRefractionRay(Vector3 direction, Intersection rayIntersection);
};
