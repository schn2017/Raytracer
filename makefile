CXX = g++
VPATH = ./Unit_Tests
CXXFLAGS = -Wall -g -std=c++11
INCFLAGS = -I./
LDFLAGS = -lfreeimage
RM = rm -f

main: main.o Camera.o Intersection.o Lighting.o LightSource.o Materials.o MathHelper.o materials.o matrix3.o matrix4.o object.o PointLight.o pixels.o ray.o raytracer.o rgb.o sample.o scene.o \
			scenesampler.o sphere.o transform.o triangle.o vector3.o vector4.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o main main.o Camera.o Intersection.o Lighting.o LightSource.o MathHelper.o materials.o matrix3.o matrix4.o object.o\
	 																 PointLight.o pixels.o ray.o raytracer.o rgb.o sample.o scene.o \
																	 scenesampler.o sphere.o transform.o\
																	 triangle.o vector3.o vector4.o\
																	 
main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c main.cpp

Camera.o: Camera.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Camera.cpp

Intersection.o: Intersection.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Intersection.cpp

Lighting.o: Lighting.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Lighting.cpp

LightSource.o: LightSource.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c LightSource.cpp

Materials.o: Materials.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Materials.cpp

MathHelper.o: MathHelper.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c MathHelper.cpp

matrix3.o: Matrix3.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Matrix3.cpp

matrix4.o: Matrix4.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Matrix4.cpp

object.o: Object.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Object.cpp

PointLight.o: PointLight.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c PointLight.cpp

pixels.o: Pixels.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Pixels.cpp

ray.o: Ray.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Ray.cpp

raytracer.o: Raytracer.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Raytracer.cpp

rgb.o: RGB.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c RGB.cpp

sample.o: Sample.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Sample.cpp

scene.o: Scene.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Scene.cpp

scenesampler.o: SceneSampler.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c SceneSampler.cpp

sphere.o: Sphere.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Sphere.cpp

transform.o: Transform.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Transform.cpp

triangle.o: Triangle.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Triangle.cpp

vector3.o: Vector3.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Vector3.cpp

vector4.o: Vector4.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c Vector4.cpp

################################## Test Suite ##################################

tests: TestSuite.o CameraTests.o Camera.o IntersectionTests.o Intersection.o LightingTests.o Lighting.o LightSourceTests.o LightSource.o MaterialsTests.o Materials.o \
			 MathHelperTests.o MathHelper.o Matrix3Tests.o matrix3.o Matrix4Tests.o \
			 matrix4.o ObjectTests.o object.o	PointLightTests.o PointLight.o PixelsTests.o pixels.o \
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

PointLightTests.o: PointLightTests.cpp
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $(VPATH)/PointLightTests.cpp

PixelsTests.o: Pixels.cpp
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
