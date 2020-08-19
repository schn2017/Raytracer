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

Vector3 Scene::getVertex(int element)
{
  return vertices[element];
}

vector<Sphere> Scene::getSpheres()
{
  return spheres;
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
  input.open(filename);

  if (input.is_open())
  {
    getline(input, str);

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
          // To Do
        }
        else if (command == "directional")
        {
          // To Do
        }
        else if (command == "emission")
        {
          // To Do
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
          // To Do
        }
        else if (command == "pushTransform")
        {
          // To Do
        }
        else if (command == "rotate")
        {
          // To Do
        }
        else if (command == "scale")
        {
          // To Do
        }
        else if (command == "shininess")
        {

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
        else if (command == "sphere")
        {
          validCommand = readSceneValues(s, 4, objectParameters);
          if (validCommand)
          {
              spheres.push_back(Sphere(objectParameters[0], objectParameters[1],
                                      objectParameters[2], objectParameters[3]));
          }
        }
        else if (command == "translate")
        {
          // To Do
        }
        else if (command == "tri")
        {
          validCommand = readSceneValues(s, 3, objectParameters);
          if (validCommand)
          {
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
  sampler = SceneSampler(height, width);

  while (sampler.canSample())
  {
    Sample sample = sampler.getSample();

    Ray cameraRay = sceneCamera.createRay(Vector3(sample.getX(), sample.getY(), 0));

    //Check if Ray intersects with shapes

    // Receive color

    // Commit color to film

  }

  // Turn film into image

}
