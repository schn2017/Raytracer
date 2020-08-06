#include <iostream>
#include "FreeImage.h"
#include "Vector3.h"
using namespace std;

int main(int argc, char *argv[]){
  FreeImage_Initialise();
  cout << "FreeImage"  << FreeImage_GetVersion () << "\n" ;
  cout << FreeImage_GetCopyrightMessage () << "\n\n" ;
  FreeImage_DeInitialise();

  Vector3 testVector = Vector3(1, 2, 3);

  cout << testVector.getX() << "\n";
  cout << testVector.getY() << "\n";
  cout << testVector.getZ() << "\n";

  return 0;
}
