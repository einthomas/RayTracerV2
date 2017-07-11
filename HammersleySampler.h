#pragma once

#include "Sampler.h"

class HammersleySampler : public Sampler {
public:
	HammersleySampler(int numSamples);
	HammersleySampler(int numSamples, int numSampleSets);
	void generateSamples();

private:
	float phi(int i);
};
