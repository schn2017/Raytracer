#include "Raytracer.h"

Raytracer::Raytracer()
{

}

Raytracer::Raytracer(vector<Object> objectVector)
{
  objects = objectVector;
}

RGB Raytracer::traceRay(Ray hitRay)
{
  for (int i = 0; i < objects.size(); i++)
  {
    Sphere sphere = objects[i].getSphere();
    Triangle triangle = objects[i].getTriangle();

    if (sphere.getState() == true)
    {
      cout << "Sphere found \n";
      if (sphere.intersect(hitRay) == true)
      {
        return RGB(0, 0, 255);
      }
    }
    else if (triangle.getState() == true)
    {
      //cout << "Triangle found \n";
    }
  }
return RGB(0, 0, 0);
}
