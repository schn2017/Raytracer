
#include "Sample.h"

Sample::Sample(float rowValue, float columnValue)
{
  row = rowValue;
  column = columnValue;
}

float Sample::getRow()
{
  return row;
}

float Sample::getColumn()
{
  return column;
}
