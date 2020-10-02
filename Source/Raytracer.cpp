#include "Raytracer.h"

////////////////////////////////////////////////////////////////////////////////
// Class Constructor Functions
Raytracer::Raytracer()
{

}

Raytracer::Raytracer(vector<Object> objectVector, Lighting lights)
{
  objects = objectVector;

 for(int i = 0; i < objects.size(); i++)
 {
   std::cout << "The reflectivity is " << objects[i].getMaterials().getReflectivity() << "\n";
   std::cout << "The ambient is " << objects[i].getMaterials().getAmbient().toString() << "\n";
 }

  sceneLights = lights;
}
////////////////////////////////////////////////////////////////////////////////
// Method to get color of a camera ray intersection
RGB Raytracer::getColor(Ray hitRay, int recursionDepth)
{
  RGB color = RGB(0, 0, 0);

  Intersection rayIntersection = traceRay(hitRay);
  if (rayIntersection.getState() == true)
  {
    float reflectivity = rayIntersection.getMaterials().getReflectivity();
    //std::cout << "The reflectivity is " << reflectivity << "\n";
    //color = color + sceneLights.getAmbientLight() + traceLightRays(hitRay, rayIntersection);
    color = color + rayIntersection.getMaterials().getAmbient()
                  + traceLightRays(rayIntersection)
                  + traceReflectionRay(hitRay, rayIntersection, recursionDepth);
  }

  return color;
}
////////////////////////////////////////////////////////////////////////////////
// Method to trace a ray to determine if it intersects objects
Intersection Raytracer::traceRay(Ray &hitRay)
{
  int numberOfObjects = objects.size();
  float distance = 0;
  vector<Intersection> intersections;
  Vector3 surfaceNormal;
  for (int i = 0; i < numberOfObjects; i++)
  {
    Sphere sphere = objects[i].getSphere();
    Triangle triangle = objects[i].getTriangle();

    if (sphere.getState() == true)
    {

      Matrix4 inverseTransform = MathHelper::inverseMatrix4(objects[i].getTransform());
      Point transformedOrigin = inverseTransform * hitRay.getOrigin();
      Vector3 transformedDirection = MathHelper::normalize(inverseTransform  * hitRay.getDirection());

      Ray transformedRay = Ray(transformedOrigin, transformedDirection);

      if (sphere.intersect(transformedRay) == true)
      {
        Point normalPoint = MathHelper::transpose(objects[i].getTransform()) * transformedRay.getIntersectionPoint();
        Point intersectionPoint = objects[i].getTransform() * transformedRay.getIntersectionPoint();
        distance = MathHelper::distance(hitRay.getOrigin(), intersectionPoint);

        //std::cout << "The intersection point is " + intersectionPoint.toString();
        //std::cout << "The calculated distance is " << distance << " The original distance was " << transformedRay.getT() << "\n";

        surfaceNormal = sphere.calculateSurfaceNormal(normalPoint);

        Intersection intersection = Intersection(distance, objects[i].getMaterials());
        intersection.setSurfaceNormal(surfaceNormal);
        intersection.setIntersectionPoint(intersectionPoint);

        intersections.push_back(intersection);
      }
    }
    else if (triangle.getState() == true)
    {
      if (triangle.intersect(hitRay) == true)
      {
        distance = hitRay.getT();

        Intersection intersection = Intersection(distance, objects[i].getMaterials());

        surfaceNormal = triangle.calculateSurfaceNormal();

        intersection.setSurfaceNormal(surfaceNormal);
        intersections.push_back(intersection);
      }
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
////////////////////////////////////////////////////////////////////////////////
// Method to trace a ray to determine if it intersects objects
RGB Raytracer::traceLightRays(Intersection intersection)
{
  RGB diffuse = intersection.getMaterials().getDiffuse();
  RGB emission = intersection.getMaterials().getEmission();
  RGB specular = intersection.getMaterials().getSpecular();
  float shininess = intersection.getMaterials().getShininess();
  Vector3 surfaceNormal = intersection.getSurfaceNormal();
  RGB color = RGB(0, 0, 0);

  int numberOfLights = sceneLights.getLightSources().size();

  for (int i = 0; i < numberOfLights; i++)
  {
    if (sceneLights.getLightSource(i).getPointLight().getState() == true)
    {
      PointLight pointLight = sceneLights.getLightSource(i).getPointLight();
      Point origin = intersection.getIntersectionPoint();
      float distanceFromIntersectionToLight = MathHelper::distance(origin, pointLight.getPosition());
      Vector3 direction = MathHelper::normalize(pointLight.getPosition() - origin);

      RGB lightColor = pointLight.getLightColor();
      Vector3 offset = direction * 0.0025;
      Ray lightRay = Ray(origin + offset, direction);
      Intersection rayIntersection = traceRay(lightRay);
      float rayToIntersectionDistance = MathHelper::distance(origin, rayIntersection.getIntersectionPoint());
      color = color + emission;
      if (rayIntersection.getState() == false || distanceFromIntersectionToLight < rayToIntersectionDistance)
      {
        float nDotL = MathHelper::dot(surfaceNormal, direction);
        float maxnDotL = MathHelper::max(nDotL, 0);
        RGB lambert = lightColor * (diffuse * maxnDotL);
        Vector3 r = (direction) + (surfaceNormal * MathHelper::dot(direction, surfaceNormal));
        Vector3 halfAngle = MathHelper::normalize(direction + r);
        float nDotH = MathHelper::dot(surfaceNormal, halfAngle);
        float maxnDotH = MathHelper::max(nDotH, 0);
        RGB phong = lightColor * (specular * pow(maxnDotH, shininess));

        color = color + lambert + phong;
      }
    }
  }
  return color;
}
////////////////////////////////////////////////////////////////////////////////
// Method to find find intersecion with the lowest distance value
Intersection Raytracer::findClosestIntersection(vector<Intersection> intersections)
  {
    float minT = 0;
    float minIntersection = 0;
    for (int i = 0; i < intersections.size(); i++)
    {
      if (i == 0)
      {
        minT = intersections[0].getDistance();
        minIntersection = 0;
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
////////////////////////////////////////////////////////////////////////////////
//
RGB Raytracer::traceReflectionRay(Ray ray, Intersection rayIntersection, int recursionDepth)
{
  if (recursionDepth == -1)
  {
    //std::cout << "Reflection Recursion done!\n";
    return RGB(0, 0, 0);
  }
  else
  {
    // create new ray from interesection point
    Point reflectionRayOrigin = rayIntersection.getIntersectionPoint();
    Vector3 originalRayDirection = ray.getDirection();
    Vector3 surfaceNormal = rayIntersection.getSurfaceNormal();
    Vector3 reflectionRayDirection = MathHelper::normalize(originalRayDirection
                                                           + (surfaceNormal * MathHelper::dot(originalRayDirection, surfaceNormal)));

    Ray nextReflectionRay = Ray(reflectionRayOrigin + reflectionRayDirection, reflectionRayDirection);
    float reflectivity = rayIntersection.getMaterials().getReflectivity();
    if (reflectivity == 0)
    {
      return RGB(0,0,0);
    }
    else
    {
      //std::cout << "The reflectivity is " << reflectivity << "\n";
    }

    RGB color = getColor(nextReflectionRay, recursionDepth - 1);
    color = color * rayIntersection.getMaterials().getReflectivity();
  //  std::cout << "The reflected color is " + color.toString();

    return color;
  }

}
