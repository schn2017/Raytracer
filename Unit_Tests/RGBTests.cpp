#include "catch.hpp"
#include "RGB.h"

TEST_CASE("RGB: Construction")
{
  RGB color = RGB(1, 2, 3);

  REQUIRE(color.getRed() == 1);
  REQUIRE(color.getGreen() == 2);
  REQUIRE(color.getBlue() == 3);
}

TEST_CASE("RGB: Addition Override")
{
    RGB color1 = RGB(1, 2, 3);
    RGB color2 = RGB(1, 2, 3);

    RGB sum = color1 + color2;

    REQUIRE(sum.getRed() == 2);
    REQUIRE(sum.getGreen() == 4);
    REQUIRE(sum.getBlue() == 6);
}

TEST_CASE("RGB: Comparisons == Override")
{
  RGB color1 = RGB(1, 2, 3);
  RGB color2 = RGB(1, 2, 3);
  RGB color3 = RGB(0, 2, 3);

  REQUIRE( (color1 == color2) == true);
  REQUIRE( (color1 == color3) == false);
}

TEST_CASE("RGB: Comparisons != Override")
{
  RGB color1 = RGB(1, 2, 3);
  RGB color2 = RGB(1, 2, 3);
  RGB color3 = RGB(0, 2, 3);

  REQUIRE( (color1 != color3) == false);
  REQUIRE( (color1 != color2) == true);
}
