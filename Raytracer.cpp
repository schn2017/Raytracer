#include "Raytracer.h"

Raytracer::Raytracer()
{

}

Raytracer::Raytracer(vector<Object> objectVector, Lighting lights)
{
  objects = objectVector;
  sceneLights = lights;
}

RGB Raytracer::getColor(Ray hitRay)
{
  RGB color = RGB(0, 0, 0);

  Intersection rayIntersection = traceRay(hitRay);
  if (rayIntersection.getState() == true)
  {
    color = color + sceneLights.getAmbientLight() + traceLightRays(hitRay, rayIntersection);
  }

  return color;
}

Intersection Raytracer::traceRay(Ray &hitRay)
{
  int numberOfObjects = objects.size();
  float minT = 0;
  float distance = 0;
  //Intersection intersection = Intersection();
  vector<Intersection> intersections;
  Vector3 surfaceNormal;
  for (int i = 0; i < numberOfObjects; i++)
  {
    Sphere sphere = objects[i].getSphere();
    Triangle triangle = objects[i].getTriangle();

    if (sphere.getState() == true)
    {
      if (sphere.intersect(hitRay) == true)
      {
        distance = hitRay.getT();

        Intersection intersection = Intersection(distance, objects[i].getMaterials());

        surfaceNormal = sphere.calculateSurfaceNormal(hitRay.getIntersectionPoint());

        intersection.setSurfaceNormal(surfaceNormal);
        intersections.push_back(intersection);
      }
    }
    else if (triangle.getState() == true)
    {
      //To do
      //return true
    }
  }

  if (intersections.size() > 0)
  {
    return findClosestIntersection(intersections);
  }
  else
  {
    Intersection intersection = Intersection();
    return intersection;
  }
}

RGB Raytracer::traceLightRays(Ray hitRay, Intersection intersection)
{
  RGB diffuse = intersection.getMaterials().getDiffuse();
  RGB emission = intersection.getMaterials().getEmission();
  RGB specular = intersection.getMaterials().getSpecular();
  float shininess = intersection.getMaterials().getShininess();
  Vector3 surfaceNormal = intersection.getSurfaceNormal();
  RGB color = RGB(0, 0, 0);
  bool lightFound = false;

  int numberOfLights = sceneLights.getLightSources().size();

  for (int i = 0; i < numberOfLights; i++)
  {
    if (sceneLights.getLightSource(i).getPointLight().getState() == true)
    {
      PointLight pointLight = sceneLights.getLightSource(i).getPointLight();
      Vector3 origin = hitRay.getIntersectionPoint();
      Vector3 cameraDirection = MathHelper::normalize(hitRay.getOrigin() - origin);
      Vector3 direction = MathHelper::normalize(pointLight.getPosition() - origin);
      RGB lightColor = pointLight.getLightColor();
      //cout<< "LightColor - ";
      //lightColor.print();
      Ray lightRay = Ray(origin + direction, direction);
      Intersection rayIntersection = traceRay(lightRay);
      color = color + emission;
      if (rayIntersection.getState() == false)
      {
        float nDotL = MathHelper::dot(surfaceNormal, direction);
        float maxnDotL = MathHelper::max(nDotL, 0);
        RGB lambert = lightColor * (diffuse * maxnDotL);
        Vector3 r = (direction) + (surfaceNormal * MathHelper::dot(direction, surfaceNormal));
        Vector3 halfAngle = MathHelper::normalize(direction + r);
        //float nDotH = MathHelper::dot(surfaceNormal, cameraDirection);
        float nDotH = MathHelper::dot(surfaceNormal, halfAngle);
        float maxnDotH = MathHelper::max(nDotH, 0);
        RGB phong = lightColor * (specular * pow(maxnDotH, shininess));

        //cout << "nDotL " << nDotL << " Max " << maxnDotL << "\n";
        //cout << "nDotH " << nDotH << " Max " << maxnDotH << "\n";
        color = color + lambert + phong;
      }

    }

  }

  return color;
}

  Intersection Raytracer::findClosestIntersection(vector<Intersection> intersections)
  {
    float minT = 0;
    float minIntersection = 0;
    for (int i = 0; i < intersections.size(); i++)
    {
      if (i == 0)
      {
        minT = intersections[0].getDistance();
      }
      else
      {
        if (intersections[i].getDistance() < minT)
        {
          minT = intersections[i].getDistance();
          minIntersection = i;
        }
      }
    }

    return intersections[minIntersection];
  }
