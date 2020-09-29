CXX = g++
VPATH = ./Unit_Tests
PATH = ./Source/
CXXFLAGS = -Wall -g -std=c++11
INCFLAGS = -I./
LDFLAGS = -lfreeimage
RM = /bin/rm -f

main: main.o Camera.o Intersection.o Lighting.o LightSource.o Materials.o MathHelper.o materials.o matrix3.o matrix4.o object.o Point.o PointLight.o pixels.o ray.o raytracer.o rgb.o sample.o scene.o \
			scenesampler.o sphere.o transform.o triangle.o vector3.o vector4.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o main main.o Camera.o Intersection.o Lighting.o LightSource.o MathHelper.o materials.o matrix3.o matrix4.o object.o\
	 																 Point.o PointLight.o pixels.o ray.o raytracer.o rgb.o sample.o scene.o \
																	 scenesampler.o sphere.o transform.o\
																	 triangle.o vector3.o vector4.o\

main.o: ./Source/main.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c  $(PATH)main.cpp

Camera.o: ./Source/Camera.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Camera.cpp

Intersection.o: ./Source/Intersection.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Intersection.cpp

Lighting.o: ./Source/Lighting.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Lighting.cpp

LightSource.o: ./Source/LightSource.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)LightSource.cpp

Materials.o: ./Source/Materials.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Materials.cpp

MathHelper.o: ./Source/MathHelper.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)MathHelper.cpp

matrix3.o: ./Source/Matrix3.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Matrix3.cpp

matrix4.o: ./Source/Matrix4.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Matrix4.cpp

object.o: ./Source/Object.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Object.cpp

Point.o: ./Source/Point.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Point.cpp

PointLight.o: ./Source/PointLight.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)PointLight.cpp

pixels.o: ./Source/Pixels.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Pixels.cpp

ray.o: ./Source/Ray.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Ray.cpp

raytracer.o: ./Source/Raytracer.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Raytracer.cpp

rgb.o: ./Source/RGB.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)RGB.cpp

sample.o: ./Source/Sample.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Sample.cpp

scene.o: ./Source/Scene.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Scene.cpp

scenesampler.o: ./Source/SceneSampler.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)SceneSampler.cpp

sphere.o: ./Source/Sphere.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Sphere.cpp

transform.o: ./Source/Transform.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Transform.cpp

triangle.o: ./Source/Triangle.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Triangle.cpp

vector3.o: ./Source/Vector3.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Vector3.cpp

vector4.o: ./Source/Vector4.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(PATH)Vector4.cpp

################################## Test Suite ##################################

tests: TestSuite.o CameraTests.o Camera.o IntersectionTests.o Intersection.o LightingTests.o Lighting.o LightSourceTests.o LightSource.o MaterialsTests.o Materials.o \
			 MathHelperTests.o MathHelper.o Matrix3Tests.o matrix3.o Matrix4Tests.o \
			 matrix4.o ObjectTests.o object.o	PointTests.o Point.o PointLightTests.o PointLight.o PixelsTests.o pixels.o \
			 RayTests.o ray.o RaytracerTests.o raytracer.o RGBTests.o rgb.o SampleTests.o sample.o SceneSamplerTests.o \
			 scenesampler.o SceneTests.o Scene.o SphereTests.o sphere.o \
			 TransformTests.o transform.o TriangleTests.o triangle.o Vector3Tests.o \
			 vector3.o Vector4Tests.o vector4.o

	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o tests TestSuite.o \
	CameraTests.o Camera.o \
	IntersectionTests.o Intersection.o \
	LightingTests.o Lighting.o \
	LightSourceTests.o LightSource.o \
	MaterialsTests.o Materials.o \
	MathHelperTests.o MathHelper.o \
	Matrix3Tests.o matrix3.o \
	Matrix4Tests.o matrix4.o \
	ObjectTests.o object.o \
	PointTests.o Point.o \
	PointLightTests.o PointLight.o \
	PixelsTests.o pixels.o \
	RayTests.o ray.o \
	RaytracerTests.o raytracer.o \
	RGBTests.o rgb.o \
	SampleTests.o sample.o \
	SphereTests.o sphere.o \
	SceneTests.o scene.o \
	SceneSamplerTests.o scenesampler.o \
	TransformTests.o transform.o \
	TriangleTests.o triangle.o \
	Vector3Tests.o Vector3.o \
	Vector4Tests.o Vector4.o

TestSuite.o: TestSuite.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/TestSuite.cpp

CameraTests.o: CameraTests.cpp
	$(CXX) -c $(CXXFLAGS) $(INCFLAGS) $(VPATH)/CameraTests.cpp

IntersectionTests.o: IntersectionTests.cpp
	$(CXX) -c $(CXXFLAGS) $(INCFLAGS) $(VPATH)/IntersectionTests.cpp

LightingTests.o: LightingTests.cpp
	$(CXX) -c $(CXXFLAGS) $(INCFLAGS) $(VPATH)/LightingTests.cpp

LightSourceTests.o: LightSourceTests.cpp
	$(CXX) -c $(CXXFLAGS) $(INCFLAGS) $(VPATH)/LightSourceTests.cpp

MaterialsTests.o: MaterialsTests.cpp
		$(CXX) -c $(CXXFLAGS) $(INCFLAGS) $(VPATH)/MaterialsTests.cpp

MathHelperTests.o: MathHelperTests.cpp
	$(CXX) -c $(CXXFLAGS) $(INCFLAGS) $(VPATH)/MathHelperTests.cpp

Matrix3Tests.o: Matrix3Tests.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/Matrix3Tests.cpp

Matrix4Tests.o: Matrix4Tests.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/Matrix4Tests.cpp

ObjectTests.o: ObjectTests.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/ObjectTests.cpp

PointTests.o: PointTests.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/PointTests.cpp

PointLightTests.o: PointLightTests.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/PointLightTests.cpp

PixelsTests.o: PixelsTests.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/PixelsTests.cpp

RayTests.o: RayTests.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/RayTests.cpp

RaytracerTests.o: RaytracerTests.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/RaytracerTests.cpp

RGBTests.o: RGBTests.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/RGBTests.cpp

SampleTests.o: SampleTests.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/SampleTests.cpp

SceneTests.o: SceneTests.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/SceneTests.cpp

SceneSamplerTests.o: SceneSamplerTests.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/SceneSamplerTests.cpp

SphereTests.o: SphereTests.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/SphereTests.cpp

TransformTests.o: TransformTests.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/TransformTests.cpp

TriangleTests.o: TriangleTests.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/TriangleTests.cpp

Vector3Tests.o: Vector3Tests.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/Vector3Tests.cpp

Vector4Tests.o: Vector4Tests.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/Vector4Tests.cpp

clean:
	$(RM) *.o main tests *.png
