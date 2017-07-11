#include "ViewPlane.h"

ViewPlane::ViewPlane() {
}

ViewPlane::ViewPlane(
    int verticalResolution, int horizontalResolution, float pixelSize, float gamma
) :
	verticalResolution(verticalResolution),
	horizontalResolution(horizontalResolution),
	pixelSize(pixelSize),
	gamma(gamma),
	invGamma(1.0 / gamma)
{
}

void ViewPlane::setSampler(Sampler *sampler) {
	if (this->sampler != nullptr) {
		delete this->sampler;
		this->sampler = nullptr;
	}

	this->sampler = sampler;
}
