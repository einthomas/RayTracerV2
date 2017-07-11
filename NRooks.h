#pragma once

#include "Sampler.h"

/*
Samples are first generated diagonally and are then shuffled vertically and horizontally
so that there's not more than one sample in each row and column.
Good 1D distribution, the 2D distribution is comparable to that of the random sampler.
*/
class NRooks : public Sampler {
public:
	NRooks(int numSamples);
	NRooks(int numSamples, int numSampleSets);
	void generateSamples();
};
