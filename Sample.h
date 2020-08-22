#pragma once

class Sample
{
public:
  Sample(float roww, float col);
  float getRow();
  float getColumn();

private:
  float row;
  float column;
};
