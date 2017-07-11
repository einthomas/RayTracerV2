#include "NRooks.h"
#include "MathUtil.h"

NRooks::NRooks(int numSamples) :
	Sampler(numSamples)
{
	generateSamples();
}

NRooks::NRooks(int numSamples, int numSampleSets) :
	Sampler(numSamples, numSampleSets)
{
	generateSamples();
}

void NRooks::generateSamples() {
	for (int i = 0; i < numSampleSets; i++) {
		// create samples along the diagonal
		for (int k = 0; k < numSamples; k++) {
			samples.push_back(Vector2(
				(i + randFloat()) / numSamples,
				(k + randFloat()) / numSamples
			));
		}
	}

	for (int i = 0; i < numSampleSets; i++) {
		// shuffle samples horizontally
		for (int k = 0; k < numSamples; k++) {
			int randIndex = rand() % numSamples + i * numSamples;
			double temp = samples[k + i * numSamples].x;
			samples[k + i * numSamples].x = samples[randIndex].x;
			samples[randIndex].x = temp;
		}

		// shuffle samples vertically
		for (int k = 0; k < numSamples; k++) {
			int randIndex = rand() % numSamples + i * numSamples;
			double temp = samples[k + i * numSamples].y;
			samples[k + i * numSamples].y = samples[randIndex].y;
			samples[randIndex].y = temp;
		}
	}
}
