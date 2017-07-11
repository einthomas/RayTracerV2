#pragma once

#include "Sampler.h"

/*
Generates numSamples samples positioned randomly.
Bad 1D and 2D distribution.
*/
class RandomSampler : public Sampler {
public:
	RandomSampler(int numSamples);
	RandomSampler(int numSamples, int numSampleSets);
	void generateSamples();
};
