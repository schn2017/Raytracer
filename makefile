CXX = g++
CXXFLAGS = -Wall -g -std=c++11
INCFLAGS = -I./
LDFLAGS = -lfreeimage
RM = rm -f

main: main.o MathHelper.o matrix3.o matrix4.o scene.o sphere.o transform.o triangle.o vector3.o vector4.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o main main.o MathHelper.o matrix3.o matrix4.o scene.o sphere.o transform.o triangle.o vector3.o vector4.o

main.o: main.cpp FreeImage.h MathHelper.h Matrix3.h Matrix4.h Scene.h transform.h Vector3.h Vector4.h
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c main.cpp

Camera.o: Camera.cpp Camera.h Vector3.h
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Camera.cpp

MathHelper.o: MathHelper.cpp MathHelper.h Matrix3.h Matrix4.h Vector3.h Vector4.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c MathHelper.cpp

matrix3.o: Matrix3.cpp Matrix3.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Matrix3.cpp

matrix4.o: Matrix4.cpp Matrix3.h Matrix4.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Matrix4.cpp

scene.o: Scene.cpp Scene.h Camera.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Scene.cpp

sphere.o: Sphere.cpp Sphere.h Vector3.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Sphere.cpp

transform.o: Transform.cpp MathHelper.h Matrix3.h Matrix4.h Vector3.h Vector4.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Transform.cpp

triangle.o: Triangle.cpp Triangle.h Vector3.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Triangle.cpp

vector3.o: Vector3.cpp Vector3.h
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Vector3.cpp

vector4.o: Vector4.cpp Vector4.h
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Vector4.cpp

################################## Test Suite ##################################

tests: TestSuite.o CameraTests.o Camera.o MathHelperTests.o MathHelper.o Matrix3Tests.o matrix3.o Matrix4Tests.o matrix4.o SceneTests.o Scene.o SphereTests.o sphere.o TransformTests.o transform.o TriangleTests.o triangle.o Vector3Tests.o vector3.o Vector4Tests.o vector4.o
	$(CXX) $(CXXFLAGS) -o tests TestSuite.o \
									CameraTests.o Camera.o \
									MathHelperTests.o MathHelper.o \
									Matrix3Tests.o matrix3.o \
									Matrix4Tests.o matrix4.o \
									SphereTests.o sphere.o \
									SceneTests.o scene.o \
									TransformTests.o transform.o \
								 	TriangleTests.o triangle.o	\
									Vector3Tests.o Vector3.o \
									Vector4Tests.o Vector4.o \

TestSuite.o: TestSuite.cpp catch.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c TestSuite.cpp

CameraTests.o: CameraTests.cpp Camera.h catch.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c CameraTests.cpp

MathHelperTests.o: MathHelperTests.cpp MathHelper.h Matrix3.h Matrix4.h Vector3.h Vector4.h catch.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c MathHelperTests.cpp

Matrix3Tests.o: Matrix3Tests.cpp Matrix3.h catch.hpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Matrix3Tests.cpp

Matrix4Tests.o: Matrix4Tests.cpp Matrix3.h Matrix4.h Vector3.h Vector4.h catch.hpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Matrix4Tests.cpp

SceneTests.o: SceneTests.cpp Scene.h catch.hpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c SceneTests.cpp

SphereTests.o: SphereTests.cpp Sphere.h Vector3.h catch.hpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c SphereTests.cpp

TransformTests.o: TransformTests.cpp Matrix3.h Matrix4.h catch.hpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c TransformTests.cpp

TriangleTests.o: TriangleTests.cpp Triangle.h Vector3.h catch.hpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c TriangleTests.cpp

Vector3Tests.o: Vector3Tests.cpp Vector3.h catch.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Vector3Tests.cpp

Vector4Tests.o: Vector4Tests.cpp Vector4.h catch.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Vector4Tests.cpp

clean:
	$(RM) *.o main tests
