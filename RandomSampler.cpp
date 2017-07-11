#include "RandomSampler.h"
#include "MathUtil.h"

RandomSampler::RandomSampler(int numSamples) :
	Sampler(numSamples)
{
	generateSamples();
}

RandomSampler::RandomSampler(int numSamples, int numSampleSets) :
	Sampler(numSamples, numSampleSets)
{
	generateSamples();
}

void RandomSampler::generateSamples() {
	for (int i = 0; i < numSampleSets; i++) {
		for (int k = 0; k < numSamples; k++) {
			samples.push_back(Vector2(randFloat(), randFloat()));
		}
	}
}
