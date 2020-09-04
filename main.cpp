#include <iostream>
#include "Scene.h"
using namespace std;

int main(int argc, char *argv[]){
  Scene testScene = Scene();
  testScene.readScene(argv[1]);
  cout << "Render Scene Beginning\n";
  testScene.renderScene();

  return 0;
}
