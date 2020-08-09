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
          // To Do
        }
        else if (command == "translate")
        {
          // To Do
        }
        else if (command == "tri")
        {
          // To Do
        }
        else if (command == "trinormal")
        {
          // To Do
        }
        else if (command == "vertex")
        {
          // To Do
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
      cout<< "Failed reading value " << i << " will skip \n";
      return false;
    }
  }
  return true;
}
