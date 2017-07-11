#include "JitteredSampler.h"
#include "MathUtil.h"

JitteredSampler::JitteredSampler(int numSamples) :
	Sampler(numSamples)
{
	generateSamples();
}

JitteredSampler::JitteredSampler(int numSamples, int numSampleSets) :
	Sampler(numSamples, numSampleSets)
{
	generateSamples();
}

void JitteredSampler::generateSamples() {
	int numSamplesSqrt = sqrt(numSamples);
	for (int i = 0; i < numSampleSets; i++) {
		for (int k = 0; k < numSamplesSqrt; k++) {
			for (int m = 0; m < numSamplesSqrt; m++) {
				samples.push_back(Vector2(
					(m + randFloat()) / numSamplesSqrt,
					(k + randFloat()) / numSamplesSqrt)
				);
			}
		}
	}
}
