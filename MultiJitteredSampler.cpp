#include "MultiJitteredSampler.h"
#include "MathUtil.h"

MultiJitteredSampler::MultiJitteredSampler(int numSamples) :
	Sampler(numSamples)
{
	generateSamples();
}

MultiJitteredSampler::MultiJitteredSampler(int numSamples, int numSampleSets) :
	Sampler(numSamples, numSampleSets)
{
	generateSamples();
}

void MultiJitteredSampler::generateSamples() {
    // numSamples has to be a square
	int numSamplesSqrt = sqrt(numSamples);
	for (int i = 0; i < numSampleSets; i++) {
		// create initial samples
		for (int k = 0; k < numSamplesSqrt; k++) {
			for (int m = 0; m < numSamplesSqrt; m++) {
				samples.push_back(Vector2(
					(m + randFloat() + numSamplesSqrt * k) / numSamples,
					(k + randFloat() + numSamplesSqrt * m) / numSamples
				));
			}
		}
	}

	for (int i = 0; i < numSampleSets; i++) {
		// shuffle x coordinates
		for (int k = 0; k < numSamplesSqrt; k++) {
			for (int m = 0; m < numSamplesSqrt; m++) {
				int randIndex = randFloat(m, numSamplesSqrt - 1);
				double temp = samples[k * numSamplesSqrt + m + i * numSamples].x;
				samples[k * numSamplesSqrt + m + i * numSamples].x =
                    samples[k * numSamplesSqrt + randIndex + i * numSamples].x;
				samples[k * numSamplesSqrt + randIndex + i * numSamples].x = temp;
			}
		}

		// shuffle y coordinates
		for (int k = 0; k < numSamplesSqrt; k++) {
			for (int m = 0; m < numSamplesSqrt; m++) {
				int randIndex = randFloat(m, numSamplesSqrt - 1);
				double temp = samples[m * numSamplesSqrt + k + i * numSamples].y;
				samples[m * numSamplesSqrt + k + i * numSamples].y =
                    samples[randIndex * numSamplesSqrt + k + i * numSamples].y;
				samples[randIndex * numSamplesSqrt + k + i * numSamples].y = temp;
			}
		}
	}
}