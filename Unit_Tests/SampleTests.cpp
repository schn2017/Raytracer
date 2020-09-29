#include "catch.hpp"
#include "./Source/Sample.h"


TEST_CASE("Sample: Construction")
{
  Sample testSample = Sample(10, 20);

  REQUIRE(testSample.getRow() == 10);
  REQUIRE(testSample.getColumn() == 20);
}
