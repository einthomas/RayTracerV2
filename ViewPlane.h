#pragma once

#include "Sampler.h"

class ViewPlane {
public:
	int verticalResolution;
	int horizontalResolution;
	float pixelSize;
	float gamma;
	float invGamma;
	Sampler *sampler = NULL;

	ViewPlane();
	ViewPlane(int verticalResolution, int horizontalResolution, float pixelSize, float gamma);
	void setSampler(Sampler *sampler);
};
