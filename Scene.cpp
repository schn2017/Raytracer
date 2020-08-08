#include "Scene.h"

Scene::Scene()
{
}


Camera Scene::getCamera()
{
  return sceneCamera;
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

        if (command == "camera")
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
