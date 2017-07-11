#pragma once

#include "GeometricObject.h"

class Plane : public GeometricObject {
public:
	Vector3 point;
	Vector3 normal;

	Plane();
	Plane(const Vector3 &point, const Vector3 &normal, const Vector3 &color);
	bool hit(const Ray &ray, double &tMin, ShadingInfo &shadingInfo);
};
