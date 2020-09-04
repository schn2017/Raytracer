#pragma once

class Sample
{
public:
  Sample(float rowValue, float columnValue);
  float getRow();
  float getColumn();

private:
  float row;
  float column;
};
