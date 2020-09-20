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

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      sum.setElement(i, j, m1.getElement(i, j) + m2.getElement(i, j));
    }
  }

  return sum;
}

Matrix4 MathHelper::adjugateMatrix4X4(Matrix4 m1)
{
  Matrix4 adjugateMatrix = Matrix4();
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      float determinant = pow(-1, i + j) *  MathHelper::determinant(MathHelper::determinantSubArray3X3(m1, i, j));
      adjugateMatrix.setElement(i, j, determinant);
    }
  }

  return adjugateMatrix;
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
    int value = 0;
    float subArray[4];

    for (int i = 0; i < 3; i++)
    {
      MathHelper::determinantSubArray2X2(m1, 0, i, subArray);

      value = m1.getElement(0, i) * ((subArray[0] * subArray[3]) - (subArray[1] * subArray[2]));

      if (i == 1)
      {
        value *= -1;

      }

      sum = value + sum;
    }

    return sum;
}

float MathHelper::determinantMatrix4(Matrix4 m1)
{
  Matrix3 a11 = MathHelper::determinantSubArray3X3(m1, 0, 0);
  float determinantA11 = MathHelper::determinant(a11) * m1.getElement(0, 0);

  Matrix3 a21 = MathHelper::determinantSubArray3X3(m1, 1, 0);
  float determinantA21 = -1 * MathHelper::determinant(a21) * m1.getElement(1, 0);

  Matrix3 a31 = MathHelper::determinantSubArray3X3(m1, 2, 0);
  float determinantA31 = MathHelper::determinant(a31) * m1.getElement(2, 0);

  Matrix3 a41 = MathHelper::determinantSubArray3X3(m1, 3, 0);
  float determinantA41 = -1 * MathHelper::determinant(a41) * m1.getElement(3, 0);

  float totalDeterminant = determinantA11 + determinantA21 + determinantA31 + determinantA41;

  return totalDeterminant;
}

void MathHelper::determinantSubArray2X2(Matrix3 m1, int row, int column, float array[4])
{
  int count = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (i != row && j != column)
      {
        array[count] = m1.getElement(i, j);
        count++;
      }
    }
  }
}

Matrix3 MathHelper::determinantSubArray3X3(Matrix4 m1, int row, int column)
{
  Matrix3 subMatrix = Matrix3();
  int r = 0;
  int c = 0;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (i != row && j != column)
      {
        if (c == 3)
        {
          r++;
          c = 0;
        }

        subMatrix.setElement(r, c, m1.getElement(i, j));
        c++;
      }
    }
  }
  return subMatrix;
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

Matrix4 MathHelper::inverseMatrix4(Matrix4 m1)
{
  float reciprocalDeterminant = 1 / determinantMatrix4(m1);
  Matrix4 adjugateMatrix = MathHelper::adjugateMatrix4X4(m1);
  adjugateMatrix = MathHelper::scalarMultiply(reciprocalDeterminant, adjugateMatrix);

  return adjugateMatrix;
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

  return product;
}

Matrix4 MathHelper::multiply(Matrix4 m1, Matrix4 m2)
{
  Matrix4 product = Matrix4();

  float value = 0;

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      value = m1.getElement(i, 0) * m2.getElement(0, j)
              + m1.getElement(i, 1) * m2.getElement(1, j)
              + m1.getElement(i, 2) * m2.getElement(2, j)
              + m1.getElement(i, 3) * m2.getElement(3, j);

      product.setElement(i, j, value);
    }
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
  float x = (m1.getElement(0, 0) * v1.getX())
            + (m1.getElement(0, 1) * v1.getY())
            + (m1.getElement(0, 2) * v1.getZ())
            + (m1.getElement(0, 3) * v1.getW());
  float y = (m1.getElement(1, 0) * v1.getX())
            + (m1.getElement(1, 1) * v1.getY())
            + (m1.getElement(1, 2) * v1.getZ())
            + (m1.getElement(1, 3) * v1.getW());
  float z = (m1.getElement(2, 0) * v1.getX())
            + (m1.getElement(2, 1) * v1.getY())
            + (m1.getElement(2, 2) * v1.getZ())
            + (m1.getElement(2, 3) * v1.getW());
  float w = (m1.getElement(3, 0) * v1.getX())
            + (m1.getElement(3, 1) * v1.getY())
            + (m1.getElement(3, 2) * v1.getZ())
            + (m1.getElement(3, 3) * v1.getW());

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

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      product.setElement(i, j, m1.getElement(i, j) * scalar);
    }
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

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      sum.setElement(i, j, m1.getElement(i,j) - m2.getElement(i,j));
    }
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
