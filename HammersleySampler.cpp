#include "HammersleySampler.h"
#include "MathUtil.h"

#include <iostream>

HammersleySampler::HammersleySampler(int numSamples) :
	Sampler(numSamples)
{
	generateSamples();
}

HammersleySampler::HammersleySampler(int numSamples, int numSampleSets) :
	Sampler(numSamples, numSampleSets)
{
	generateSamples();
}

void HammersleySampler::generateSamples() {
	for (int i = 0; i < numSamples; i++) {
		samples.push_back(Vector2(static_cast<float>(i) / numSamples, phi(i)));
	}
}

float HammersleySampler::phi(int i) {
	float result = 0.0f;
	float factor = 0.5f;

	while (i) {
		result += factor * (i & 1);
		factor *= 0.5f;
		i /= 2;
	}

	return result;
}
