#include "catch.hpp"
#include "RGB.h"

TEST_CASE("RGB: Construction")
{
  RGB color = RGB(1, 0, 1);

  REQUIRE(color.getRed() == 255);
  REQUIRE(color.getGreen() == 0);
  REQUIRE(color.getBlue() == 255);
}

TEST_CASE("RGB: Addition Override")
{
    RGB color1 = RGB(1, 0, 1);
    RGB color2 = RGB(1, 0, 1);

    RGB sum = color1 + color2;

    REQUIRE(sum.getRed() == 255);
    REQUIRE(sum.getGreen() == 0);
    REQUIRE(sum.getBlue() == 255);
}

TEST_CASE("RGB: Comparisons == Override")
{
  RGB color1 = RGB(1, 0, 0);
  RGB color2 = RGB(1, 0, 0);
  RGB color3 = RGB(0, 0, 1);

  REQUIRE( (color1 == color2) == true);
  REQUIRE( (color1 == color3) == false);
}

TEST_CASE("RGB: Comparisons != Override")
{
  RGB color1 = RGB(1, 0, 0);
  RGB color2 = RGB(1, 0, 0);
  RGB color3 = RGB(0, 0, 1);

  REQUIRE( (color1 != color3) == false);
  REQUIRE( (color1 != color2) == true);
}
