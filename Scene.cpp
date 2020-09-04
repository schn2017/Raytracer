#include "Scene.h"

Scene::Scene()
{
}

Camera Scene::getCamera()
{
  return sceneCamera;
}

int Scene::getDepth()
{
  return depth;
}

int Scene::getHeight()
{
  return height;
}

int Scene::getWidth()
{
  return width;
}

vector<Object> Scene::getObjects()
{
  return objects;
}

Vector3 Scene::getVertex(int element)
{
  return vertices[element];
}

vector<Sphere> Scene::getSpheres()
{
  return spheres;
}

stack<Matrix4> Scene::getTransformStack()
{
  return transformStack;
}

vector<Triangle> Scene::getTriangles()
{
  return triangles;
}

bool Scene::readScene(const char *filename)
{
  bool validCommand;
  float objectParameters[10];
  ifstream input;
  string str, command;

  Materials material;

  input.open(filename);

  if (input.is_open())
  {
    getline(input, str);
    Matrix4 identityMatrix = Matrix4(1, 0, 0, 0,
                                     0, 1, 0, 0,
                                     0, 0, 1, 0,
                                     0, 0, 0, 1);

    transformStack.push(identityMatrix);

    while (input)
    {
      if ((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#'))
      {
        stringstream s(str);
        s >> command;


        if (command == "ambient")
        {
          // To Do
        }
        else if (command == "attenuation")
        {
          // To Do
        }
        else if (command == "camera")
        {
          validCommand = readSceneValues(s, 10, objectParameters);

          if (validCommand)
          {
            sceneCamera = Camera(objectParameters[0], objectParameters[1],
                                 objectParameters[2], objectParameters[3],
                                 objectParameters[4], objectParameters[5],
                                 objectParameters[6], objectParameters[7],
                                 objectParameters[8], objectParameters[9]);
          }

        }
        else if (command == "diffuse")
        {
          validCommand = readSceneValues(s, 3, objectParameters);

          if (validCommand)
          {
            material.setDiffuse(RGB(objectParameters[0], objectParameters[1], objectParameters[2]));
          }
        }
        else if (command == "directional")
        {
          // To Do
        }
        else if (command == "emission")
        {
          validCommand = readSceneValues(s, 3, objectParameters);

          if (validCommand)
          {
            material.setEmission(RGB(objectParameters[0], objectParameters[1], objectParameters[2]));
          }
        }
        else if (command == "maxdepth")
        {
          validCommand = readSceneValues(s, 1, objectParameters);
          if (validCommand)
          {
            depth = objectParameters[0];
          }
        }
        else if (command == "maxverts")
        {
          // To Do
        }
        else if (command == "maxvertnorms")
        {
          // To Do
        }
        else if (command == "output")
        {
          // To Do
        }
        else if (command == "point")
        {
          // To Do
        }
        else if (command == "popTransform")
        {
          if (transformStack.size() <= 1)
          {
            cout << "ERROR: Stack has no elements! \n";
          }
          else
          {
            transformStack.pop();
          }
        }
        else if (command == "pushTransform")
        {
          transformStack.push(transformStack.top());
        }
        else if (command == "rotate")
        {
          validCommand = readSceneValues(s, 4, objectParameters);

          if (validCommand)
          {
            Vector3 inputVector = Vector3(objectParameters[0], objectParameters[1], objectParameters[2]);
            Matrix3 rotationMatrix3 = Matrix3();
            Matrix4 rotationMatrix4 = Matrix4();

          }

          // To Do
        }
        else if (command == "scale")
        {
          // To Do
        }
        else if (command == "shininess")
        {
          validCommand = readSceneValues(s, 1, objectParameters);

          if (validCommand)
          {
            material.setShininess(objectParameters[0]);
          }
        }
        else if (command == "size")
        {
          validCommand = readSceneValues(s, 2, objectParameters);
          if (validCommand)
          {
            width = objectParameters[0];
            height = objectParameters[1];
          }
        }
        else if (command == "specular")
        {
          validCommand = readSceneValues(s, 3, objectParameters);

          if (validCommand)
          {
            material.setSpecular(RGB(objectParameters[0], objectParameters[1], objectParameters[2]));
          }
        }
        else if (command == "sphere")
        {
          validCommand = readSceneValues(s, 4, objectParameters);
          if (validCommand)
          {
            Sphere newSphere = Sphere(objectParameters[0], objectParameters[1],
                                    objectParameters[2], objectParameters[3]);
            Object newObject = Object();
            newObject.setSphere(newSphere);
            objects.push_back(newObject);

            //Testing to be removed
            spheres.push_back(Sphere(objectParameters[0], objectParameters[1],
                                      objectParameters[2], objectParameters[3]));
          }
        }
        else if (command == "translate")
        {
          validCommand = readSceneValues(s, 3, objectParameters);

          if (validCommand)
          {
            Matrix4 translationMatrix = Transform::translate(objectParameters[0], objectParameters[1], objectParameters[2]);
          }

        }
        else if (command == "tri")
        {
          validCommand = readSceneValues(s, 3, objectParameters);
          if (validCommand)
          {
            Triangle newTriangle = Triangle(vertices[objectParameters[0]], vertices[objectParameters[1]], vertices[objectParameters[2]]);
            Object newObject = Object();
            newObject.setTriangle(newTriangle);
            objects.push_back(newObject);

            //Testing to be removed
            triangles.push_back(Triangle(vertices[objectParameters[0]], vertices[objectParameters[1]], vertices[objectParameters[2]]));
          }
        }
        else if (command == "trinormal")
        {
          // To Do
        }
        else if (command == "vertex")
        {
          validCommand = readSceneValues(s, 3, objectParameters);
          if (validCommand)
          {
            vertices.push_back(Vector3(objectParameters[0], objectParameters[1], objectParameters[2]));
          }
        }
        else if (command == "vertexnormal")
        {
          // To Do
        }
      }

      getline (input, str);
    }

    return true;
  }
  else
  {
    return false;
  }
}

bool Scene::readSceneValues(stringstream &s, const int numvals, float * values)
{
  for (int i = 0; i < numvals; i++)
  {
    s >> values[i];

    if (s.fail())
    {
      cout << "Failed reading value " << i << " will skip \n";
      return false;
    }
  }
  return true;
}

void Scene::renderScene()
{
  film = Pixels(height, width);
  sampler = SceneSampler(height, width);
  tracer = Raytracer(objects);

  while (sampler.canSample())
  {
    Sample sample = sampler.getSample();

    Vector3 rayDirection = sceneCamera.convertSampleToCameraView(sample);

    Ray cameraRay = sceneCamera.createRay(rayDirection);

    RGB pixelColor = tracer.traceRay(cameraRay);
    film.addColor(pixelColor);
  }

  cout << "Sampling Complete \n";
  film.createFinalImage();
}
