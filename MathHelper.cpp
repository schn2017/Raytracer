#include "MathHelper.h"

Matrix3 MathHelper::add(Matrix3 m1, Matrix3 m2)
{
  Matrix3 sum = Matrix3();

  for (int i = 0; i < 9; i++)
  {
    sum.setElement(i, m1.getElements()[i] + m2.getElements()[i]);
  }

  return sum;
}

Matrix4 MathHelper::add(Matrix4 m1, Matrix4 m2)
{
  Matrix4 sum = Matrix4();

  for (int i = 0; i < 16; i++)
  {
    sum.setElement(i, m1.getElements()[i] + m2.getElements()[i]);
  }

  return sum;
}

Vector3 MathHelper::cross(Vector3 v1, Vector3 v2)
{
  //    i j k
  // v1 x y z
  // v2 x y z

  float i = (v1.getY() * v2.getZ()) - (v1.getZ() * v2.getY());
  float j = -1 * ((v1.getX() * v2.getZ()) - (v1.getZ() * v2.getX()));
  float k = (v1.getX() * v2.getY()) - (v1.getY() * v2.getX());

  return Vector3(i, j, k);
}

float MathHelper::dot(Vector3 v1, Vector3 v2)
{
  return (v1.getX() * v2.getX())
          + (v1.getY() * v2.getY())
          + (v1.getZ() * v2.getZ());
}

float MathHelper::dot(Vector4 v1, Vector4 v2)
{
  return (v1.getX() * v2.getX()
          + (v1.getY() * v2.getY())
          + (v1.getZ() * v2.getZ())
          + (v1.getW() * v2.getW()));
}

float MathHelper::magnitude(Vector3 v1)
{
  return sqrt((v1.getX() * v1.getX())
              +(v1.getY() * v1.getY())
              +(v1.getZ() * v1.getZ()));
}

float MathHelper::magnitude(Vector4 v1)
{
  return sqrt((v1.getX() * v1.getX())
              +(v1.getY() * v1.getY())
              +(v1.getZ() * v1.getZ())
              +(v1.getW() * v1.getW()));
}

Matrix3 MathHelper::multiply(Matrix3 m1, Matrix3 m2)
{
  Matrix3 product = Matrix3();

  int row = -1, col = -1;
  float value = 0;

  for (int i = 0; i < 9; i++)
  {
    col = i % 3;
    row = (i / 3) + (2 * (i / 3));

    value = (m1.getElements()[row] * m2.getElements()[col])
            +(m1.getElements()[row + 1] * m2.getElements()[col + 3])
            +(m1.getElements()[row + 2] * m2.getElements()[col + 6]);

    product.setElement(i, value);
  }

  return product;
}

Matrix4 MathHelper::multiply(Matrix4 m1, Matrix4 m2)
{
  Matrix4 product = Matrix4();

  int row = -1, col = -1;
  float value = 0;

  for (int i = 0; i < 16; i++)
  {
    col = i % 4;
    row = (i / 4) * 4;

    value = (m1.getElements()[row] * m2.getElements()[col])
            +(m1.getElements()[row + 1] * m2.getElements()[col + 4])
            +(m1.getElements()[row + 2] * m2.getElements()[col + 8])
            +(m1.getElements()[row + 3] * m2.getElements()[col + 12]);

    product.setElement(i, value);
  }

  return product;
}

Vector3 MathHelper::normalize(Vector3 v1)
{
  float magnitude = MathHelper::magnitude(v1);

  return Vector3(v1.getX() / magnitude,
                 v1.getY() / magnitude,
                 v1.getZ() / magnitude);
}

Vector4 MathHelper::normalize(Vector4 v1)
{
  float magnitude = MathHelper::magnitude(v1);

  return Vector4(v1.getX() / magnitude,
                 v1.getY() / magnitude,
                 v1.getZ() / magnitude,
                 v1.getW() / magnitude);
}

float MathHelper::radians(float angle)
{
  return angle * (PI/180);
}

Matrix3 MathHelper::scalarMultiply(float scalar, Matrix3 m1)
{
  Matrix3 product = Matrix3();

  for (int i = 0; i < 9; i++)
  {
    product.setElement(i, m1.getElements()[i] * scalar);
  }

  return product;
}

Matrix4 MathHelper::scalarMultiply(float scalar, Matrix4 m1)
{
  Matrix4 product = Matrix4();

  for (int i = 0; i < 16; i++)
  {
    product.setElement(i, m1.getElements()[i] * scalar);
  }

  return product;
}


Matrix3 MathHelper::sub(Matrix3 m1, Matrix3 m2)
{
  Matrix3 sum = Matrix3();

  for (int i = 0; i < 9; i++)
  {
    sum.setElement(i, m1.getElements()[i] - m2.getElements()[i]);
  }

  return sum;
}

Matrix4 MathHelper::sub(Matrix4 m1, Matrix4 m2)
{
  Matrix4 sum = Matrix4();

  for (int i = 0; i < 16; i++)
  {
    sum.setElement(i, m1.getElements()[i] - m2.getElements()[i]);
  }

  return sum;
}
