#pragma once

#include <vector>

#include "ViewPlane.h"
#include "Plane.h"
#include "Sphere.h"
#include "MultipleObjectsTracer.h"
#include "Window.h"
#include "Vector2.h"
#include "RandomSampler.h"
#include "RegularSampler.h"
#include "JitteredSampler.h"
#include "NRooks.h"
#include "MultiJitteredSampler.h"
#include "HammersleySampler.h"

class World {
public:
	ViewPlane viewPlane;
	Vector3 backgroundColor;
	Tracer *tracer;

	World(Window *window);
	void build();
	void renderScene();
	ShadingInfo hitObjects(const Ray &ray);

private:
	std::vector<GeometricObject*> geometricObjects;

	Window *window;
};
