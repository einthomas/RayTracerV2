#include "World.h"

#include <iostream>
#include <chrono>
#include <thread>

World::World(Window *window) :
	window(window),
	viewPlane(ViewPlane()),
	tracer(nullptr)
{
	srand(time(nullptr));
}

void World::build() {
	viewPlane = ViewPlane(200.0f, 200.0f, 1.0f, 1.0f);
	viewPlane.setSampler(new MultiJitteredSampler(16));
	tracer = new MultipleObjectsTracer(this);

	geometricObjects.push_back(new Sphere(80.0f, Vector3(0, -25, 0), Vector3(255.0f, 0.0f, 0.0f)));
	geometricObjects.push_back(new Sphere(60.0f, Vector3(0, 30, 0), Vector3(255.0f, 255.0f, 0.0f)));
	geometricObjects.push_back(new Plane(Vector3(0.0f), Vector3(0.0f, 1.0f, 1.0f), Vector3(0.0f, 63.75f, 0.0f)));
}

void World::renderScene() {
	float x, y;
	float z = 100.0f;
	Ray ray;
	ray.direction = Vector3(0.0f, 0.0f, -1.0f);
    float viewPlaneDistance = 1.0f;

	for (int i = 0; i < viewPlane.verticalResolution; i++) {
		for (int k = 0; k < viewPlane.horizontalResolution; k++) {
			Vector3 color;
			for (int m = 0; m < viewPlane.sampler->numSamples; m++) {
				Vector2 samplePoint = viewPlane.sampler->getNextUnitSquareSample();
				ray.origin = Vector3(
                    viewPlane.pixelSize * (k - viewPlane.horizontalResolution / 2.0f + samplePoint.x),
                    viewPlane.pixelSize * (i - viewPlane.verticalResolution / 2.0f + samplePoint.y),
                    viewPlaneDistance
                );
				color += tracer->trace(ray);
			}
			color /= viewPlane.sampler->numSamples;

			// display calculated color on screen
			COLORREF colorref = RGB(color.x, color.y, color.z);
			window->setPixel(k, viewPlane.verticalResolution - i - 1, colorref);
		}
	}
}

ShadingInfo World::hitObjects(const Ray &ray) {
	double t = 0.0;
	double tMin = DBL_MAX;
	ShadingInfo shadingInfo(*this);

	for (int i = 0; i < geometricObjects.size(); i++) {
		if (geometricObjects[i]->hit(ray, t, shadingInfo) && (t < tMin)) {
			shadingInfo.hitObject = true;
			shadingInfo.color = geometricObjects[i]->color;
			tMin = t;
		}
	}

	return shadingInfo;
}
