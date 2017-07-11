#pragma once

#include "Sampler.h"

/*
Each pixel is divided into a sqrt(numSamples) x sqrt(numSamples) grid. Samples are generated at
the center each grid cell.
Good 2D distribution.
*/
class RegularSampler : public Sampler {
public:
	RegularSampler(int numSamples);
	RegularSampler(int numSamples, int numSampleSets);
	void generateSamples();
};
