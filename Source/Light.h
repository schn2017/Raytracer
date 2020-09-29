#pragma once

#include "Ray.h"
#include "RGB.h"

class Light
{
public:
  virtual ~Light() {};
  virtual bool getState() = 0;
  virtual void setState(bool &newState) = 0;
};
