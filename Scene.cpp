#include "Scene.h"

////////////////////////////////////////////////////////////////////////////////
// Class Constructor Functions
Scene::Scene()
{
}
////////////////////////////////////////////////////////////////////////////////
// Get Member Functions
Camera Scene::getCamera()
{
  return sceneCamera;
}

int Scene::getDepth()
{
  return depth;
}

float Scene::getHeight()
{
  return height;
}

float Scene::getWidth()
{
  return width;
}

vector<Object> Scene::getObjects()
{
  return objects;
}

Lighting Scene::getLighting()
{
  return sceneLights;
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
////////////////////////////////////////////////////////////////////////////////
//Set Member Functions

void Scene::setViewMatrix(Matrix4 m1)
{
  viewMatrix = m1;
}

////////////////////////////////////////////////////////////////////////////////
//Render Scene Methods
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
          validCommand = readSceneValues(s, 3, objectParameters);

          if (validCommand)
          {
            RGB ambientLight = RGB( objectParameters[0], objectParameters[1], objectParameters[2]);
            sceneLights.setAmbientLight(ambientLight);
          }
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

            viewMatrix = Transform::lookAt(sceneCamera.getLookFrom(), sceneCamera.getLookAt(), sceneCamera.getUp());

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
          validCommand = readSceneValues(s, 6, objectParameters);

          if (validCommand)
          {
            Vector3 position = Vector3(objectParameters[0], objectParameters[1], objectParameters[2]);
            RGB pointLightColor = RGB(objectParameters[3], objectParameters[4], objectParameters[5]);
            //pointLightColor.print();
            PointLight newPointLight = PointLight(position, pointLightColor);
            LightSource newLightSource = LightSource();
            newLightSource.setPointLight(newPointLight);
            sceneLights.addLightSource(newLightSource);
          }
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
            float rotationAngle = objectParameters[3];
            Matrix3 rotationMatrix3 = Transform::rotate(rotationAngle, inputVector);
            Matrix4 rotationMatrix4 = Matrix4(rotationMatrix3);

            cout << "Pre Rotation \n";
            transformStack.top().print();
            transformStack.top() = MathHelper::multiply(rotationMatrix4, transformStack.top());
            cout << "Rotated! \n";
            transformStack.top().print();
          }
        }
        else if (command == "scale")
        {
          validCommand = readSceneValues(s, 3, objectParameters);

          if (validCommand)
          {
            Matrix4 scaleMatrix = Transform::scale(objectParameters[0], objectParameters[1], objectParameters[2]);
            cout << "Pre Scaling \n";
            transformStack.top().print();
            transformStack.top() = MathHelper::multiply(scaleMatrix, transformStack.top());
            cout << "Scaled! \n";
            transformStack.top().print();
          }

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
            newObject.setMaterials(material);
            newObject.setTransform(transformStack.top());
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
            transformStack.top().print();
            Matrix4 translationMatrix = Transform::translate(objectParameters[0], objectParameters[1], objectParameters[2]);
            transformStack.top() = MathHelper::multiply(translationMatrix, transformStack.top());
            cout << "Translated! \n";
            transformStack.top().print();
          }

        }
        else if (command == "tri")
        {
          //std::cout << "Triangle found!\n";
          validCommand = readSceneValues(s, 3, objectParameters);
          if (validCommand)
          {
            //std::cout << "Creating triangle!\n";
            Triangle newTriangle = Triangle(vertices[objectParameters[0]], vertices[objectParameters[1]], vertices[objectParameters[2]]);
            Object newObject = Object();
            newObject.setTriangle(newTriangle);
            newObject.setMaterials(material);
            newObject.setTransform(transformStack.top());
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
////////////////////////////////////////////////////////////////////////////////
//Scene Setup Helper Functions
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
////////////////////////////////////////////////////////////////////////////////
//Render Scene Method
void Scene::renderScene()
{
  sceneCamera.setDimensions(height, width);
  sceneCamera.calculateFOVX();
  cout << "Camera Information:\nLookFrom: ";
  sceneCamera.getLookFrom().toString();
  cout << "LookAt: ";
  sceneCamera.getLookAt().toString();
  cout << "Up: ";
  sceneCamera.getUp().toString();
  cout << "FOVY: " << sceneCamera.getFOVY() << " FOVX: " << sceneCamera.getFOVX() << "\n\n";

  cout << "Scene Information\n";

  cout << "Number of Objects: " << objects.size() << "\n";
  //Matrix4 projectionMatrix = Transform::perspective(sceneCamera.getFOVY(), height / width, 0, 100);
  cout << "\nView Matrix\n";
  viewMatrix.print();
  //cout << "Projection Matrix\n";
  //projectionMatrix.print();

  cout << "Number of vertices: " << vertices.size() << "\n";
  for (int i = 0; i < vertices.size(); i++)
  {
    cout<< "Vertex: ";
    vertices[i].toString();
  }
  cout << "\n";

  applyViewMatrix();

  film = Pixels(height, width);
  sampler = SceneSampler(height, width);
  tracer = Raytracer(objects, sceneLights);
  float sampleTotalCount = height * width;
  int sampleCount = 0;

  cout << "\nStarting sampling \n";

  while (sampler.canSample())
  {
    Sample sample = sampler.getSample();

    Vector3 rayDirection = sceneCamera.convertSampleToCameraView(sample);

    Ray cameraRay = sceneCamera.createRay(rayDirection);

    if(sampleCount > sampleTotalCount * .1)
    {
      cout << "[]";
      sampleCount = 0;
    }

    RGB pixelColor = tracer.getColor(cameraRay);
    film.addColor(pixelColor);
    sampleCount++;
  }
  cout << "[]";
  cout << "\nSampling Complete\n";
  film.createFinalImage();
  cout << "Render Scene Beginning\n";
  cout << "Image created.\n";
}
////////////////////////////////////////////////////////////////////////////////
//Render Scene Helper Functions
void Scene::applyViewMatrix()
{
  sceneLights.applyViewMatrix(viewMatrix);

  for(int i = 0; i < objects.size(); i++)
  {
    objects[i].setTransform(MathHelper::multiply(viewMatrix, objects[i].getTransform()));
    objects[i].applyTransform();
  }
}
////////////////////////////////////////////////////////////////////////////////
