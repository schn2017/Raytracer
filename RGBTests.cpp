#include "catch.hpp"
#include "RGB.h"

TEST_CASE("RGB: Construction")
{
  RGB color = RGB(1, 2, 3);

  REQUIRE(color.getRed() == 1);
  REQUIRE(color.getGreen() == 2);
  REQUIRE(color.getBlue() == 3);
}
