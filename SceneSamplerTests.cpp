#include "catch.hpp"
#include "SceneSampler.h"

TEST_CASE("SceneSampler: Construction")
{
  SceneSampler testSampler = SceneSampler(2, 4);

  REQUIRE(testSampler.getHeight() == 2);
  REQUIRE(testSampler.getWidth() == 4);
}

TEST_CASE("SceneSampler: Get Sample")
{
  SceneSampler testSampler = SceneSampler(10, 10);
  Sample testSample = testSampler.getSample();
  REQUIRE(testSample.getX() == 1);
  REQUIRE(testSample.getY() == -1);
  testSampler.canSample();
  testSample = testSampler.getSample();
  REQUIRE(testSample.getX() == 1);
  REQUIRE(testSample.getY() == -0.8f);
  testSampler.canSample();
  testSample = testSampler.getSample();
  REQUIRE(testSample.getX() == 1);
  REQUIRE(testSample.getY() == -0.6f);
}

TEST_CASE("SceneSampler: Check For Next Sample")
{
  int imageHeight = 10;
  int imageWidth = 10;
  SceneSampler testSampler = SceneSampler(imageHeight, imageWidth);
  Sample testSample = Sample(0,0);
  int count = 0;
  while(testSampler.canSample())
  {
    if (testSampler.canSample())
    {
      testSample = testSampler.getSample();
      count++;
    }
  }

  REQUIRE(count == (imageHeight + 1) * (imageWidth + 1));
  REQUIRE(testSampler.canSample() == false);
}
