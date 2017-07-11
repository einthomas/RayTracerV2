#pragma once

#include "Sampler.h"

/*
Each pixel is divided into a sqrt(numSamples) x sqrt(numSamples) grid. Samples are generated at
the center + a random value of each grid cell.
Good 2D distribution.
*/
class JitteredSampler : public Sampler {
public:
	JitteredSampler(int numSamples);
	JitteredSampler(int numSamples, int numSampleSets);
	void generateSamples();
};
