#include "catch.hpp"
#include "Sample.h"


TEST_CASE("Sample: Construction")
{
  Sample testSample = Sample(10, 20);

  REQUIRE(testSample.getX() == 10);
  REQUIRE(testSample.getY() == 20);
}
