#include "catch.hpp"
#include "Transform.h"

TEST_CASE("Transform: LookAt Matrix")
{
  Vector3 eye = Vector3(1, 2, 3);
  Vector3 center = Vector3(0, 1, 0);
  Vector3 up = Vector3(0, 0, 1);

  //u -1/sqrt(2) 1/sqrt(2), 0
  //v -3/sqrt(22) -3/sqrt(22) sqrt(2/11)
  //w  1/sqrt(11), 1/sqrt(11), 3/sqrt(11)

  //{{-1/sqrt(2), 1/sqrt(2), 0, 0}, {-3/sqrt(22), -3/sqrt(22), sqrt(2/11), 0}, {1/sqrt(11), 1/sqrt(11), 3/sqrt(11), 0}, {0, 0, 0, 1}} *{{1, 0, 0, -1}, {0, 1, 0, -2}, {0, 0, 1, -3}, {0, 0, 0, 1}}


  Matrix4 testMatrix = Transform::lookAt(eye, center, up);

  REQUIRE(floor(testMatrix.getElement(0, 0) * 1000.0) / 1000.0 == -0.708);
  REQUIRE(floor(testMatrix.getElement(0, 1) * 1000.0) / 1000.0 == 0.707);
  REQUIRE(floor(testMatrix.getElement(0, 2) * 1000.0) / 1000.0 == 0);
  REQUIRE(floor(testMatrix.getElement(0, 3) * 1000.0) / 1000.0 == -1);

  REQUIRE(floor(testMatrix.getElement(1, 0) * 1000.0) / 1000.0 == -0.64);
  REQUIRE(floor(testMatrix.getElement(1, 1) * 1000.0) / 1000.0 == -0.64);
  REQUIRE(floor(testMatrix.getElement(1, 2) * 1000.0) / 1000.0 == 0.426);
  REQUIRE(floor(testMatrix.getElement(1, 3) * 1000.0) / 1000.0 == -2);

  REQUIRE(floor(testMatrix.getElement(2, 0) * 1000.0) / 1000.0 == 0.301);
  REQUIRE(floor(testMatrix.getElement(2, 1) * 1000.0) / 1000.0 == 0.301);
  REQUIRE(floor(testMatrix.getElement(2, 2) * 1000.0) / 1000.0 == 0.904);
  REQUIRE(floor(testMatrix.getElement(2, 3) * 1000.0) / 1000.0 == -3);

  REQUIRE(floor(testMatrix.getElement(3, 0) * 1000.0) / 1000.0 == 0);
  REQUIRE(floor(testMatrix.getElement(3, 1) * 1000.0) / 1000.0 == 0);
  REQUIRE(floor(testMatrix.getElement(3, 2) * 1000.0) / 1000.0 == 0);
  REQUIRE(floor(testMatrix.getElement(3, 3) * 1000.0) / 1000.0 == 1);
}

TEST_CASE("Transform: Normalize the up direction")
{
  Vector3 v1 = Vector3(1, 2, 3);
  Vector3 v2 = Vector3(4, 5, 6);
  /*Vector3 up = Transform::up(30, v1, v2);

  REQUIRE(floor(up.getX() * 1000.0) / 1000.0 == -0.791);
  REQUIRE(floor(up.getY() * 1000.0) / 1000.0 == -0.094);
  REQUIRE(floor(up.getZ() * 1000.0) / 1000.0== 0.604);*/
}

TEST_CASE("Transform: Perspective Matrix")
{

  Matrix4 testMatrix = Transform::perspective(30, 20, 1, 100);

  // d = 3.73
  // A = -1.02
  // B = -2.02
  // d/aspect = 0.1865

  REQUIRE(floor(testMatrix.getElement(0, 0) * 1000.0) / 1000.0 == 0.186);
  REQUIRE(floor(testMatrix.getElement(0, 1) * 1000.0) / 1000.0 == 0);
  REQUIRE(floor(testMatrix.getElement(0, 2) * 1000.0) / 1000.0 == 0);
  REQUIRE(floor(testMatrix.getElement(0, 3) * 1000.0) / 1000.0 == 0);

  REQUIRE(floor(testMatrix.getElement(1, 0) * 1000.0) / 1000.0 == 0);
  REQUIRE(floor(testMatrix.getElement(1, 1) * 1000.0) / 1000.0 == 3.732);
  REQUIRE(floor(testMatrix.getElement(1, 2) * 1000.0) / 1000.0 == 0);
  REQUIRE(floor(testMatrix.getElement(1, 3) * 1000.0) / 1000.0 == 0);

  REQUIRE(floor(testMatrix.getElement(2, 0) * 1000.0) / 1000.0 == 0);
  REQUIRE(floor(testMatrix.getElement(2, 1) * 1000.0) / 1000.0 == 0);
  REQUIRE(floor(testMatrix.getElement(2, 2) * 1000.0) / 1000.0 == -1.021);
  REQUIRE(floor(testMatrix.getElement(2, 3) * 1000.0) / 1000.0 == -1);

  REQUIRE(floor(testMatrix.getElement(3, 0) * 1000.0) / 1000.0 == 0);
  REQUIRE(floor(testMatrix.getElement(3, 1) * 1000.0) / 1000.0 == 0);
  REQUIRE(floor(testMatrix.getElement(3, 2) * 1000.0) / 1000.0 == -2.021);
  REQUIRE(floor(testMatrix.getElement(3, 3) * 1000.0) / 1000.0 == 0);

}

TEST_CASE("Transform: Rotation Matrix - Construction")
{
  Matrix3 rotation1 = Transform::rotate(30, Vector3(0, 0, 1));
  Matrix3 rotation2 = Transform::rotate(90, Vector3(1, 0, 1));
/*
  REQUIRE(floor(rotation1.getElement(0, 0) * 1000.0 + 0.5) / 1000.0 == 0.866);
  REQUIRE(rotation1.getElement(0, 1) == 0.5);
  REQUIRE(rotation1.getElement(1, 0) == -0.5);
  REQUIRE(floor(rotation1.getElement(1, 1) * 1000.0 + 0.5) / 1000.0 == 0.866);

  REQUIRE(floor(rotation2.getElement(0, 0) * 1000.0 + 0.5) / 1000.0 == 0.5);
  REQUIRE(floor(rotation2.getElement(0, 1) * 1000.0 + 0.5) / 1000.0 == 0.707);
  REQUIRE(floor(rotation2.getElement(0, 2) * 1000.0 + 0.5) / 1000.0 == 0.5);
  REQUIRE(floor(rotation2.getElement(1, 0) * 1000.0 + 0.5) / 1000.0 == -0.707);
  REQUIRE(floor(rotation2.getElement(1, 1) * 1000.0 + 0.5) / 1000.0 == 0);
  REQUIRE(floor(rotation2.getElement(1, 2) * 1000.0 + 0.5) / 1000.0 == 0.707);
  REQUIRE(floor(rotation2.getElement(2, 0) * 1000.0 + 0.5) / 1000.0 == 0.5);
  REQUIRE(floor(rotation2.getElement(2, 1) * 1000.0 + 0.5) / 1000.0 == -0.707);
  REQUIRE(floor(rotation2.getElement(2, 2) * 1000.0 + 0.5) / 1000.0 == 0.5);*/
}

TEST_CASE("Transform: Rotation Matrix - Multiplication")
{
  Matrix3 m1 = Matrix3(2, 0, 0, 0, 2, 0, 0, 0, 2);
  Matrix3 rotation1 = Transform::rotate(30, Vector3(0, 0, 1));
  Matrix3 product1 = MathHelper::multiply(m1, rotation1);

  Matrix3 rotation2 = Transform::rotate(90, Vector3(1, 0, 1));
  Matrix3 product2 = MathHelper::multiply(m1, rotation2);
/*
  REQUIRE(floor(product1.getElement(0, 0) * 1000.0 + 0.5) / 1000.0 == 1.732);
  REQUIRE(product1.getElement(0, 1) == 1);
  REQUIRE(product1.getElement(1, 0) == -1);
  REQUIRE(floor(product1.getElement(1, 1) * 1000.0 + 0.5) / 1000.0 == 1.732);
  REQUIRE(product1.getElement(2, 2) == 2);

  REQUIRE(floor(product2.getElement(0, 0) * 1000.0 + 0.5) / 1000.0 == 1);
  REQUIRE(floor(product2.getElement(0, 1) * 1000.0 + 0.5) / 1000.0 == 1.414);
  REQUIRE(floor(product2.getElement(0, 2) * 1000.0 + 0.5) / 1000.0 == 1);
  REQUIRE(floor(product2.getElement(1, 0) * 1000.0 + 0.5) / 1000.0 == -1.414);
  REQUIRE(floor(product2.getElement(1, 1) * 1000.0 + 0.5) / 1000.0 == 0);
  REQUIRE(floor(product2.getElement(1, 2) * 1000.0 + 0.5) / 1000.0 == 1.414);
  REQUIRE(floor(product2.getElement(2, 0) * 1000.0 + 0.5) / 1000.0 == 1);
  REQUIRE(floor(product2.getElement(2, 1) * 1000.0 + 0.5) / 1000.0 == -1.414);
  REQUIRE(floor(product2.getElement(2, 2) * 1000.0 + 0.5) / 1000.0 == 1);*/
}

TEST_CASE("Transform: Scaling Matrix - Construction")
{
  Matrix4 scaling = Transform::scale(1, 2, 3);

  REQUIRE(scaling.getElement(0, 0) == 1);
  REQUIRE(scaling.getElement(1, 1) == 2);
  REQUIRE(scaling.getElement(2, 2) == 3);
}

TEST_CASE("Transform: Scaling Matrix Multiplication")
{
  Matrix4 m1 = Matrix4(1, 0, 0, 0,
                      0, 1, 0, 0,
                      0, 0, 1, 0,
                      0, 0, 0, 1);

  Matrix4 scaling = Transform::scale(2, 2, 2);

  Matrix4 product = MathHelper::multiply(m1, scaling);

  REQUIRE(product.getElement(0, 0) == 2);
  REQUIRE(product.getElement(1, 1) == 2);
  REQUIRE(product.getElement(2, 2) == 2);
}

TEST_CASE("Transform: Translation Matrix - Construction")
{

  Matrix4 translation = Transform::translate(5, 5, 5);

  REQUIRE(translation.getElement(0, 3) == 5);
  REQUIRE(translation.getElement(1, 3) == 5);
  REQUIRE(translation.getElement(2, 3) == 5);
}

TEST_CASE("Transform: Translation Matrix - Multiplication")
{
  Matrix4 m1 = Matrix4(1, 0, 0, 0,
                      0, 1, 0, 0,
                      0, 0, 1, 0,
                      0, 0, 0, 1);

  Matrix4 translation = Transform::translate(5, 5, 5);

  Matrix4 product = MathHelper::multiply(m1, translation);

  REQUIRE(product.getElement(0, 3) == 5);
  REQUIRE(product.getElement(1, 3) == 5);
  REQUIRE(product.getElement(2, 3) == 5);
}
