CXX = g++
VPATH = ./Unit_Tests
CXXFLAGS = -Wall -g -std=c++11
INCFLAGS = -I./
LDFLAGS = -lfreeimage
RM = rm -f

main: main.o Camera.o Lighting.o LightSource.o Materials.o MathHelper.o materials.o matrix3.o matrix4.o object.o PointLight.o pixels.o ray.o raytracer.o rgb.o sample.o scene.o \
			scenesampler.o sphere.o transform.o triangle.o vector3.o vector4.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o main main.o Camera.o Lighting.o LightSource.o MathHelper.o materials.o matrix3.o matrix4.o object.o\
	 																 PointLight.o pixels.o ray.o raytracer.o rgb.o sample.o scene.o \
																	 scenesampler.o sphere.o transform.o\
																	 triangle.o vector3.o vector4.o\

main.o: main.cpp Scene.h
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c main.cpp

Camera.o: Camera.cpp Camera.h Ray.h Vector3.h
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Camera.cpp

Lighting.o: Lighting.cpp Lighting.h
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Lighting.cpp

LightSource.o: LightSource.cpp LightSource.h
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c LightSource.cpp

Materials.o: Materials.cpp Materials.h
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Materials.cpp

MathHelper.o: MathHelper.cpp MathHelper.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c MathHelper.cpp

matrix3.o: Matrix3.cpp Matrix3.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Matrix3.cpp

matrix4.o: Matrix4.cpp Matrix3.h Matrix4.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Matrix4.cpp

object.o: Object.cpp Object.h
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Object.cpp

PointLight.o: PointLight.cpp PointLight.h
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c PointLight.cpp

pixels.o: Pixels.cpp Pixels.h FreeImage.h RGB.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Pixels.cpp

ray.o: Ray.cpp Ray.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Ray.cpp

raytracer.o: Raytracer.cpp Raytracer.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Raytracer.cpp

rgb.o: RGB.cpp RGB.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c RGB.cpp

sample.o: Sample.cpp Sample.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Sample.cpp

scene.o: Scene.cpp Scene.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Scene.cpp

scenesampler.o: SceneSampler.cpp SceneSampler.h Scene.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c SceneSampler.cpp

sphere.o: Sphere.cpp Sphere.h Vector3.h Shape.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Sphere.cpp

transform.o: Transform.cpp MathHelper.h Matrix3.h Matrix4.h Vector3.h Vector4.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Transform.cpp

triangle.o: Triangle.cpp Triangle.h Shape.h Vector3.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Triangle.cpp

vector3.o: Vector3.cpp Vector3.h
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Vector3.cpp

vector4.o: Vector4.cpp Vector4.h
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Vector4.cpp

################################## Test Suite ##################################

tests: TestSuite.o CameraTests.o Camera.o LightingTests.o Lighting.o LightSourceTests.o LightSource.o MaterialsTests.o Materials.o \
			 MathHelperTests.o MathHelper.o Matrix3Tests.o matrix3.o Matrix4Tests.o \
			 matrix4.o ObjectTests.o object.o	PointLightTests.o PointLight.o PixelsTests.o pixels.o \
			 RayTests.o ray.o raytracer.o RGBTests.o rgb.o SampleTests.o sample.o SceneSamplerTests.o \
			 scenesampler.o SceneTests.o Scene.o SphereTests.o sphere.o \
			 TransformTests.o transform.o TriangleTests.o triangle.o Vector3Tests.o \
			 vector3.o Vector4Tests.o vector4.o

	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o tests TestSuite.o \
	CameraTests.o Camera.o \
	LightingTests.o Lighting.o \
	LightSourceTests.o LightSource.o \
	MaterialsTests.o Materials.o \
	MathHelperTests.o MathHelper.o \
	Matrix3Tests.o matrix3.o \
	Matrix4Tests.o matrix4.o \
	ObjectTests.o object.o \
	PointLightTests.o PointLight.o \
	PixelsTests.o pixels.o \
	RayTests.o ray.o \
	raytracer.o \
	RGBTests.o rgb.o \
	SampleTests.o sample.o \
	SphereTests.o sphere.o \
	SceneTests.o scene.o \
	SceneSamplerTests.o scenesampler.o \
	TransformTests.o transform.o \
	TriangleTests.o triangle.o	\
	Vector3Tests.o Vector3.o \
	Vector4Tests.o Vector4.o

TestSuite.o: TestSuite.cpp catch.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/TestSuite.cpp

CameraTests.o: CameraTests.cpp Camera.h catch.hpp
	$(CXX) -c $(CXXFLAGS) $(INCFLAGS) $(VPATH)/CameraTests.cpp

LightingTests.o: LightingTests.cpp
	$(CXX) -c $(CXXFLAGS) $(INCFLAGS) $(VPATH)/LightingTests.cpp

LightSourceTests.o: LightSourceTests.cpp catch.hpp
	$(CXX) -c $(CXXFLAGS) $(INCFLAGS) $(VPATH)/LightSourceTests.cpp

MaterialsTests.o: MaterialsTests.cpp Materials.h
		$(CXX) -c $(CXXFLAGS) $(INCFLAGS) $(VPATH)/MaterialsTests.cpp

MathHelperTests.o: MathHelperTests.cpp MathHelper.h Matrix3.h Matrix4.h Vector3.h Vector4.h catch.hpp
	$(CXX) -c $(CXXFLAGS) $(INCFLAGS) $(VPATH)/MathHelperTests.cpp

Matrix3Tests.o: Matrix3Tests.cpp Matrix3.h catch.hpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/Matrix3Tests.cpp

Matrix4Tests.o: Matrix4Tests.cpp Matrix3.h Matrix4.h Vector3.h Vector4.h catch.hpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/Matrix4Tests.cpp

ObjectTests.o: ObjectTests.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/ObjectTests.cpp

PointLightTests.o: PointLightTests.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/PointLightTests.cpp

PixelsTests.o: Pixels.cpp Pixels.h RGB.h FreeImage.h catch.hpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/PixelsTests.cpp

RayTests.o: RayTests.cpp Ray.h catch.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/RayTests.cpp

RGBTests.o: RGBTests.cpp RGB.h catch.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/RGBTests.cpp

SampleTests.o: SampleTests.cpp Sample.h catch.hpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/SampleTests.cpp

SceneTests.o: SceneTests.cpp Scene.h catch.hpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/SceneTests.cpp

SceneSamplerTests.o: SceneSamplerTests.cpp SceneSampler.h Scene.h catch.hpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/SceneSamplerTests.cpp

SphereTests.o: SphereTests.cpp catch.hpp Sphere.h
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/SphereTests.cpp

TransformTests.o: TransformTests.cpp Matrix3.h Matrix4.h catch.hpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/TransformTests.cpp

TriangleTests.o: TriangleTests.cpp Triangle.h Vector3.h catch.hpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/TriangleTests.cpp

Vector3Tests.o: Vector3Tests.cpp Vector3.h catch.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/Vector3Tests.cpp

Vector4Tests.o: Vector4Tests.cpp Vector4.h catch.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/Vector4Tests.cpp

clean:
	$(RM) *.o main tests *.png
