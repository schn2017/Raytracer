class Matrix4
{
public:
  Matrix4(float r0x, float r0y, float r0z, float r0w,
          float r1x, float r1y, float r1z, float r1w,
          float r2x, float r2y, float r2z, float r2w,
          float r3x, float r3y, float r3z, float r3w);

  Matrix4(Matrix3 mat3, float r0w, float r1w, float r2w, float r3x,
          float r3y, float r3z, float r3w);
  Matrix4(Matrix3 mat3);
  Matrix4();

  float * getElements();
  void setElement(int elementNumber, float value);
  void print();
  bool isEqual(Matrix4 other);
private:
  float elements[16];
};
