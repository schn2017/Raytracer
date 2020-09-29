#include "catch.hpp"
#include "./Source/Pixels.h"

TEST_CASE("Pixels: Adding Color Samples")
{
  Pixels testPixels = Pixels(10, 10);
  RGB color1 = RGB(1, 2, 3);
  RGB color2 = RGB(2, 3, 2);
  RGB color3 = RGB(3, 4, 5);

  testPixels.addColor(color1);
  testPixels.addColor(color2);
  testPixels.addColor(color3);

  REQUIRE(testPixels.getElement(0).getRed() == 255);
  REQUIRE(testPixels.getElement(0).getGreen() == 255);
  REQUIRE(testPixels.getElement(0).getBlue() == 255);

  REQUIRE(testPixels.getElement(1).getRed() == 255);
  REQUIRE(testPixels.getElement(1).getGreen() == 255);
  REQUIRE(testPixels.getElement(1).getBlue() == 255);

  REQUIRE(testPixels.getElement(2).getRed() == 255);
  REQUIRE(testPixels.getElement(2).getGreen() == 255);
  REQUIRE(testPixels.getElement(2).getBlue() == 255);

}

TEST_CASE("Pixels: Create Output Image")
{
  Pixels testPixels = Pixels(1, 6);
  RGB color1 = RGB(1, 0, 0);
  RGB color2 = RGB(0, 1, 0);
  RGB color3 = RGB(0, 0, 1);
  RGB color4 = RGB(1, 0, 0);
  RGB color5 = RGB(0, 1, 0);
  RGB color6 = RGB(0, 0, 1);

  testPixels.addColor(color1);
  testPixels.addColor(color2);
  testPixels.addColor(color3);
  testPixels.addColor(color4);
  testPixels.addColor(color5);
  testPixels.addColor(color6);

  REQUIRE(testPixels.createFinalImage() == true);
}
