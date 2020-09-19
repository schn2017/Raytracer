#include "MathHelper.h"

Matrix3 MathHelper::add(Matrix3 m1, Matrix3 m2)
{
  Matrix3 sum = Matrix3();

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      sum.setElement(i, j, m1.getElement(i, j) + m2.getElement(i, j));
    }
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

float MathHelper::determinant(Matrix3 m1)
{
    int sum = 0;
    return sum;
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

float MathHelper::max(float x, float y)
{
  if (x > y)
  {
    return x;
  }
  else
  {
    return y;
  }
}

Matrix3 MathHelper::multiply(Matrix3 m1, Matrix3 m2)
{
  Matrix3 product = Matrix3();

  //int row = -1, col = -1;
  float value = 0;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      value = m1.getElement(i, 0) * m2.getElement(0, j)
              + m1.getElement(i, 1) * m2.getElement(1, j)
              + m1.getElement(i, 2) * m2.getElement(2, j);

      product.setElement(i, j, value);
    }
  }



  /*for (int i = 0; i < 9; i++)
  {
    col = i % 3;
    row = (i / 3) + (2 * (i / 3));

    value = (m1.getElements()[row] * m2.getElements()[col])
            +(m1.getElements()[row + 1] * m2.getElements()[col + 3])
            +(m1.getElements()[row + 2] * m2.getElements()[col + 6]);

    product.setElement(i, value);
  }*/

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

Vector3 MathHelper::multiply(Matrix3 m1, Vector3 v1)
{
  float dimensions[3];

  for (int i = 0; i < 3; i++)
  {
      dimensions[i] = m1.getElement(i, 0) * v1.getX()
                      + m1.getElement(i, 1) * v1.getY()
                      + m1.getElement(i, 2) * v1.getZ();
  }



  /*float x = (m1.getElements()[0] * v1.getX())
            + (m1.getElements()[1] * v1.getY())
            + (m1.getElements()[2] * v1.getZ());
  float y = (m1.getElements()[3] * v1.getX())
            + (m1.getElements()[4] * v1.getY())
            + (m1.getElements()[5] * v1.getZ());
  float z = (m1.getElements()[6] * v1.getX())
            + (m1.getElements()[7] * v1.getY())
            + (m1.getElements()[8] * v1.getZ());

  return Vector3(x, y, z);*/
  return Vector3(dimensions[0], dimensions[1], dimensions[2]);
}



Vector4 MathHelper::multiply(Matrix4 m1, Vector4 v1)
{
  float x = (m1.getElements()[0] * v1.getX())
            + (m1.getElements()[1] * v1.getY())
            + (m1.getElements()[2] * v1.getZ())
            + (m1.getElements()[3] *v1.getW());
  float y = (m1.getElements()[4] * v1.getX())
            + (m1.getElements()[5] * v1.getY())
            + (m1.getElements()[6] * v1.getZ())
            + (m1.getElements()[7] *v1.getW());
  float z = (m1.getElements()[8] * v1.getX())
            + (m1.getElements()[9] * v1.getY())
            + (m1.getElements()[10] * v1.getZ())
            + (m1.getElements()[11] *v1.getW());
  float w = (m1.getElements()[12] * v1.getX())
            + (m1.getElements()[13] * v1.getY())
            + (m1.getElements()[14] * v1.getZ())
            + (m1.getElements()[15] *v1.getW());

  return Vector4(x, y, z , w);
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

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      product.setElement(i, j, m1.getElement(i,j) * scalar);
    }
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

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      sum.setElement(i, j, m1.getElement(i,j) - m2.getElement(i,j));
    }
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


bool MathHelper::solveQuadratic(float a, float b, float c, float &t0, float &t1)
{
  float discriminant = (b * b) - (4 * a * c);

  if (discriminant < 0)
  {
    return false;
  }
  else if (discriminant == 0)
  {
    t0 = t1 = -0.5 * (b / a);
  }
  else
  {
    t0 = (-b - sqrt(discriminant)) / 2;
    t1 = (-b + sqrt(discriminant)) / 2;
  }
  return true;
}

Vector3 MathHelper::transformVector3(Matrix4 m1, Vector3 v1)
{
  float x = v1.getX();
  float y = v1.getY();
  float z = v1.getZ();

  Vector4 homogeneousV1 = Vector4(x, y, z, 1);

  Vector4 transformationVector = MathHelper::multiply(m1, homogeneousV1);

  return Vector3(transformationVector.getX() / transformationVector.getW(),
              transformationVector.getY() / transformationVector.getW(),
              transformationVector.getZ() / transformationVector.getW());
}
