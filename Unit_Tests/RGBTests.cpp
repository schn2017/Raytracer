#include "catch.hpp"
#include "RGB.h"

TEST_CASE("RGB: Construction")
{
  RGB color = RGB(1, 2, 3);

  REQUIRE(color.getRed() == 1);
  REQUIRE(color.getGreen() == 2);
  REQUIRE(color.getBlue() == 3);
}

TEST_CASE("RGB: Adding Colors")
{
    RGB color1 = RGB(1, 2, 3);
    RGB color2 = RGB(1, 2, 3);

    RGB sum = color1 + color2;

    REQUIRE(sum.getRed() == 2);
    REQUIRE(sum.getGreen() == 4);
    REQUIRE(sum.getBlue() == 6);
}
