#include "Transform.h"

Matrix4 Transform::lookAt(Point eye, Point center, Vector3 up)
{

  Vector3 w = MathHelper::normalize(eye - center);
  Vector3 u = MathHelper::normalize(MathHelper::cross(up,w));
  Vector3 v = MathHelper::normalize(MathHelper::cross(w,u));
  Matrix4 rotationMatrix = Matrix4(u.getX(), u.getY(), u.getZ(), 0,
                                   v.getX(), v.getY(), v.getZ(), 0,
                                   w.getX(), w.getY(), w.getZ(), 0,
                                   0, 0, 0, 1);

  Matrix4 translationMatrix = Transform::translate(-1 * eye.getX(),
                                                   -1 * eye.getY(),
                                                   -1 * eye.getZ());

  return translationMatrix * rotationMatrix;
}

Matrix4 Transform::perspective(float fovy, float aspect, float zNear, float zFar)
{
  float theta = fovy / 2;
  float d = 1 / tan(MathHelper::radians(theta));
  float A = -1 * (zFar + zNear) / (zFar - zNear);
  float B = -2 * (zFar * zNear) / (zFar - zNear);
  Matrix4 perspectiveMatrix = Matrix4(d/aspect, 0 , 0, 0,
                                      0, d, 0, 0,
                                      0, 0, A, -1,
                                      0, 0, B, 0);
  return perspectiveMatrix;
}

Matrix4 Transform::scale(float sx, float sy, float sz)
{
  Matrix4 scalingMatrix = Matrix4(sx, 0, 0, 0,
                                  0, sy, 0, 0,
                                  0, 0, sz, 0,
                                  0, 0, 0, 1);

  return scalingMatrix;
}

Matrix3 Transform::rotate(float degrees, Vector3 axis)
{
  Vector3 newAxis = MathHelper::normalize(axis);
  Matrix3 identity = Matrix3(1, 0, 0,
                             0, 1, 0,
                             0, 0, 1);

	float angle = MathHelper::radians(degrees);

	Matrix3 k = Matrix3(0, -1 * newAxis.getZ(), newAxis.getY(),
								      newAxis.getZ(), 0, -1 * newAxis.getX(),
								      -1 * newAxis.getY(), newAxis.getX(), 0);

	Matrix3 kSquared = MathHelper::multiply(k, k);
  identity = MathHelper::scalarMultiply(cos(angle), identity);

	Matrix3 rotation = MathHelper::add(identity, MathHelper::add(MathHelper::scalarMultiply(sin(angle),k), MathHelper::scalarMultiply(1 - cos(angle), kSquared)));

	return rotation;
}

Matrix4 Transform::translate(float tx, float ty, float tz)
{
  Matrix4 translationMatrix = Matrix4(1, 0, 0, tx,
                                      0, 1, 0, ty,
                                      0, 0, 1, tz,
                                      0, 0, 0, 1);

  return translationMatrix;
}

// Normalize the up direction and construct a coordinate frame.
/*void Transform::up(float degrees, Vector3& eye, Vector3& up)
{
	Vector3 findAxis = MathHelper::cross(eye,up);
	up = MathHelper::multiply(Transform::rotate(degrees, MathHelper::normalize(findAxis)), up);
	eye = MathHelper::multiply(Transform::rotate(degrees, MathHelper::normalize(findAxis)), eye);
}*/


Vector3 Transform::up(Vector3 up, Vector3 zvec)
{
  Vector3 x = MathHelper::cross(up, zvec);
  Vector3 y = MathHelper::cross(zvec, x);
  Vector3 ret = MathHelper::normalize(y);
  return ret;
}
