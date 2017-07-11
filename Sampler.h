#pragma once

#include "Vector2.h"
#include "Vector3.h"

#include <vector>

class Sampler {
public:
	int numSamples;

	Sampler();
	Sampler(int numSamples);
	Sampler(int numSamples, int numSampleSets);
	Vector2 getNextUnitSquareSample();
	Vector2 getNextUnitDiskSample();
	void mapSamplesToUnitDisk();
	void mapSamplestoUnitHemisphere(float e);
	virtual void generateSamples() = 0;

protected:
	std::vector<Vector2> samples;
	std::vector<Vector2> diskSamples;
	std::vector<Vector3> hemisphereSamples;
	int numSampleSets;
	long currentSquareIndex, currentDiskIndex;
	int squareJump, diskJump;

private:
	std::vector<int> shuffledIndices;

	void setupShuffledIndices();
};
