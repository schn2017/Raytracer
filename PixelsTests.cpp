#include "catch.hpp"
#include "Pixels.h"

TEST_CASE("Pixels: Adding Color Samples")
{
  Pixels testPixels = Pixels();
  RGB color1 = RGB(1, 2, 3);
  RGB color2 = RGB(2, 3, 2);
  RGB color3 = RGB(3, 4, 5);

  testPixels.addColor(color1);
  testPixels.addColor(color2);
  testPixels.addColor(color3);

  REQUIRE(testPixels.getElement(0).getRed() == 1);
  REQUIRE(testPixels.getElement(0).getGreen() == 2);
  REQUIRE(testPixels.getElement(0).getBlue() == 3);

  REQUIRE(testPixels.getElement(1).getRed() == 2);
  REQUIRE(testPixels.getElement(1).getGreen() == 3);
  REQUIRE(testPixels.getElement(1).getBlue() == 2);

  REQUIRE(testPixels.getElement(2).getRed() == 3);
  REQUIRE(testPixels.getElement(2).getGreen() == 4);
  REQUIRE(testPixels.getElement(2).getBlue() == 5);

}
