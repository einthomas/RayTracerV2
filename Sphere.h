#pragma once

#include "GeometricObject.h"

class Sphere : public GeometricObject {
public:
	float radius;
	Vector3 position;

	Sphere();
	Sphere(float radius, Vector3 position, Vector3 color);
	bool hit(const Ray &ray, double &tMin, ShadingInfo &shadingInfo);
};
