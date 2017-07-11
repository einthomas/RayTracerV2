#pragma once

#include "Ray.h"
#include "ShadingInfo.h"

class GeometricObject {
public:
	Vector3 color;

	GeometricObject(Vector3 color);
	virtual bool hit(const Ray& ray, double &tMin, ShadingInfo& shadingInfo) = 0;
};
