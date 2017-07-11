#include "RegularSampler.h"

RegularSampler::RegularSampler(int numSamples) :
	Sampler(numSamples)
{
	generateSamples();
}

RegularSampler::RegularSampler(int numSamples, int numSampleSets) :
	Sampler(numSamples, numSampleSets)
{
	generateSamples();
}

void RegularSampler::generateSamples() {
	int numSamplesSquared = sqrt(numSamples);
	for (int i = 0; i < numSampleSets; i++) {
		for (int k = 0; k < numSamplesSquared; k++) {
			for (int m = 0; m < numSamplesSquared; m++) {
				samples.push_back(Vector2(
					(m + 0.5f) / numSamplesSquared,
					(k + 0.5f) / numSamplesSquared)
				);
			}
		}
	}
}
