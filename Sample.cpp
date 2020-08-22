
#include "Sample.h"

Sample::Sample(float roww, float col)
{
  row = roww;
  column = col;
}

float Sample::getRow()
{
  return row;
}

float Sample::getColumn()
{
  return column;
}
