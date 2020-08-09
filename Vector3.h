
class Vector3{
  public:
    Vector3(float x, float y, float z);
    Vector3();
    float getX();
    float getY();
    float getZ();
    bool isEqual(Vector3 other);

  private:
    float x;
    float y;
    float z;;
};
