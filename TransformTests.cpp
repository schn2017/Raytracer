#include "catch.hpp"
#include "Transform.h"

TEST_CASE("Transform: LookAt Matrix")
{

}

TEST_CASE("Transform: Normalize the up direction")
{

}

TEST_CASE("Transform: Perspective Matrix")
{

}

TEST_CASE("Transform: Rotation Matrix - Construction")
{
  Matrix3 rotation1 = Transform::rotate(30, Vector3(0, 0, 1));
  Matrix3 rotation2 = Transform::rotate(90, Vector3(1, 0, 1));

  REQUIRE(floor(rotation1.getElements()[0] * 1000.0 + 0.5) / 1000.0 == 0.866);
  REQUIRE(rotation1.getElements()[1] == 0.5);
  REQUIRE(rotation1.getElements()[3] == -0.5);
  REQUIRE(floor(rotation1.getElements()[4] * 1000.0 + 0.5) / 1000.0 == 0.866);

  REQUIRE(floor(rotation2.getElements()[0] * 1000.0 + 0.5) / 1000.0 == 0.5);
  REQUIRE(floor(rotation2.getElements()[1] * 1000.0 + 0.5) / 1000.0 == 0.707);
  REQUIRE(floor(rotation2.getElements()[2] * 1000.0 + 0.5) / 1000.0 == 0.5);
  REQUIRE(floor(rotation2.getElements()[3] * 1000.0 + 0.5) / 1000.0 == -0.707);
  REQUIRE(floor(rotation2.getElements()[4] * 1000.0 + 0.5) / 1000.0 == 0);
  REQUIRE(floor(rotation2.getElements()[5] * 1000.0 + 0.5) / 1000.0 == 0.707);
  REQUIRE(floor(rotation2.getElements()[6] * 1000.0 + 0.5) / 1000.0 == 0.5);
  REQUIRE(floor(rotation2.getElements()[7] * 1000.0 + 0.5) / 1000.0 == -0.707);
  REQUIRE(floor(rotation2.getElements()[8] * 1000.0 + 0.5) / 1000.0 == 0.5);
}

TEST_CASE("Transform: Rotation Matrix - Multiplication")
{
  Matrix3 m1 = Matrix3(2, 0, 0, 0, 2, 0, 0, 0, 2);
  Matrix3 rotation1 = Transform::rotate(30, Vector3(0, 0, 1));
  Matrix3 product1 = MathHelper::multiply(m1, rotation1);

  Matrix3 rotation2 = Transform::rotate(90, Vector3(1, 0, 1));
  Matrix3 product2 = MathHelper::multiply(m1, rotation2);

  REQUIRE(floor(product1.getElements()[0] * 1000.0 + 0.5) / 1000.0 == 1.732);
  REQUIRE(product1.getElements()[1] == 1);
  REQUIRE(product1.getElements()[3] == -1);
  REQUIRE(floor(product1.getElements()[4] * 1000.0 + 0.5) / 1000.0 == 1.732);
  REQUIRE(product1.getElements()[8] == 2);

  REQUIRE(floor(product2.getElements()[0] * 1000.0 + 0.5) / 1000.0 == 1);
  REQUIRE(floor(product2.getElements()[1] * 1000.0 + 0.5) / 1000.0 == 1.414);
  REQUIRE(floor(product2.getElements()[2] * 1000.0 + 0.5) / 1000.0 == 1);
  REQUIRE(floor(product2.getElements()[3] * 1000.0 + 0.5) / 1000.0 == -1.414);
  REQUIRE(floor(product2.getElements()[4] * 1000.0 + 0.5) / 1000.0 == 0);
  REQUIRE(floor(product2.getElements()[5] * 1000.0 + 0.5) / 1000.0 == 1.414);
  REQUIRE(floor(product2.getElements()[6] * 1000.0 + 0.5) / 1000.0 == 1);
  REQUIRE(floor(product2.getElements()[7] * 1000.0 + 0.5) / 1000.0 == -1.414);
  REQUIRE(floor(product2.getElements()[8] * 1000.0 + 0.5) / 1000.0 == 1);
}

TEST_CASE("Transform: Scaling Matrix - Construction")
{
  Matrix4 scaling = Transform::scale(1, 2, 3);

  REQUIRE(scaling.getElements()[0] == 1);
  REQUIRE(scaling.getElements()[5] == 2);
  REQUIRE(scaling.getElements()[10] == 3);
}

TEST_CASE("Transform: Scaling Matrix Multiplication")
{
  Matrix4 m1 = Matrix4(1, 0, 0, 0,
                      0, 1, 0, 0,
                      0, 0, 1, 0,
                      0, 0, 0, 1);

  Matrix4 scaling = Transform::scale(2, 2, 2);

  Matrix4 product = MathHelper::multiply(m1, scaling);

  REQUIRE(product.getElements()[0] == 2);
  REQUIRE(product.getElements()[5] == 2);
  REQUIRE(product.getElements()[10] == 2);
}

TEST_CASE("Transform: Translation Matrix - Construction")
{

  Matrix4 translation = Transform::translate(5, 5, 5);

  REQUIRE(translation.getElements()[3] == 5);
  REQUIRE(translation.getElements()[7] == 5);
  REQUIRE(translation.getElements()[11] == 5);
}

TEST_CASE("Transform: Translation Matrix - Multiplication")
{
  Matrix4 m1 = Matrix4(1, 0, 0, 0,
                      0, 1, 0, 0,
                      0, 0, 1, 0,
                      0, 0, 0, 1);

  Matrix4 translation = Transform::translate(5, 5, 5);

  Matrix4 product = MathHelper::multiply(m1, translation);

  REQUIRE(product.getElements()[3] == 5);
  REQUIRE(product.getElements()[7] == 5);
  REQUIRE(product.getElements()[11] == 5);
}
