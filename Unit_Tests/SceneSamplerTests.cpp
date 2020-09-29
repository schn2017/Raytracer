#include "catch.hpp"
#include "./Source/SceneSampler.h"

TEST_CASE("SceneSampler: Construction")
{
  SceneSampler testSampler = SceneSampler(2, 4);

  REQUIRE(testSampler.getHeight() == 2);
  REQUIRE(testSampler.getWidth() == 4);
  REQUIRE(testSampler.getAspectRatio() == 2);
}

TEST_CASE("SceneSampler: Get Sample")
{
  SceneSampler testSampler = SceneSampler(10, 10);
  Sample testSample = testSampler.getSample();
  REQUIRE(testSample.getRow() == 0.9f);
  REQUIRE(testSample.getColumn() == -0.9f);
  testSampler.canSample();
  testSample = testSampler.getSample();
  REQUIRE(testSample.getRow() == 0.9f);
  REQUIRE(testSample.getColumn() == -0.7f);
  testSampler.canSample();
  testSample = testSampler.getSample();
  REQUIRE(testSample.getRow() == 0.9f);
  REQUIRE(testSample.getColumn() == -0.5f);
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

  REQUIRE(count == imageHeight * imageWidth);
  REQUIRE(testSampler.canSample() == false);
}
