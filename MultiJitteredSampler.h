#pragma once

#include "Sampler.h"

/*
Combination of jittered and n-rooks sampling.
Good 1D and 2D distribution.
*/
class MultiJitteredSampler : public Sampler {
public:
	MultiJitteredSampler(int numSamples);
	MultiJitteredSampler(int numSamples, int numSampleSets);
	void generateSamples();
};
