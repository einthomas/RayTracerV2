#include <algorithm>

#include "Sampler.h"
#include "MathUtil.h"

Sampler::Sampler() :
	currentSquareIndex(0), currentDiskIndex(0)
{
	setupShuffledIndices();
}

Sampler::Sampler(int numSamples) :
	numSamples(numSamples), numSampleSets(1), currentSquareIndex(0), currentDiskIndex(0)
{
	setupShuffledIndices();
}

Sampler::Sampler(int numSamples, int numSampleSets) :
	numSamples(numSamples), numSampleSets(numSampleSets), currentSquareIndex(0),
    currentDiskIndex(0)
{
	setupShuffledIndices();
}

Vector2 Sampler::getNextUnitSquareSample() {
	if (currentSquareIndex == 0) {
        // randomly choose a sample set
		squareJump = (rand() % numSampleSets) * numSamples;
	}

	return samples[squareJump + shuffledIndices[currentSquareIndex++ % numSamples + squareJump]];
}

Vector2 Sampler::getNextUnitDiskSample() {
	if (currentDiskIndex == 0) {
        // randomly choose a sample set
		diskJump = (rand() % numSampleSets) * numSamples;
	}

	return samples[diskJump + shuffledIndices[currentDiskIndex++ % numSamples + diskJump]];
}

void Sampler::setupShuffledIndices() {
	shuffledIndices.reserve(numSamples * numSampleSets);

	std::vector<int> indices;
	for (int i = 0; i < numSamples; i++) {
		indices.push_back(i);
	}

	for (int i = 0; i < numSampleSets; i++) {
		std::random_shuffle(indices.begin(), indices.end());
		shuffledIndices.insert(shuffledIndices.end(), indices.begin(), indices.end());
	}
}

/*
 * Map unit square sample to a unit disk by using the concentric map approach described in the
 * paper "A Low Distortion Map Between Disk and Square" by Peter Shirley.
 */
void Sampler::mapSamplesToUnitDisk() {
	float r, phi;
	Vector2 samplePoint;
    float piBy4 = MathUtil::PI / 4;

	diskSamples.reserve(samples.size());
	for (int i = 0; i < samples.size(); i++) {
		// map x, y to [-1, 1]
		samplePoint.x = samples[i].x * 2.0f - 1.0f;
		samplePoint.y = samples[i].y * 2.0f - 1.0f;

		if (samplePoint.x > -samplePoint.y) {
			if (samplePoint.x > samplePoint.y) {
				r = samplePoint.x;
				phi = piBy4 * (samplePoint.y / samplePoint.x);
			} else {
				r = samplePoint.y;
				phi = piBy4 * (2 - samplePoint.x / samplePoint.y);
			}
		} else {
			if (samplePoint.x < samplePoint.y) {
				r = -samplePoint.x;
				phi = piBy4 * (4 + samplePoint.y / samplePoint.x);
			} else {
				r = -samplePoint.y;
				if (samplePoint.y != 0.0f) {
					phi = piBy4 * (6 - samplePoint.x / samplePoint.y);
				} else {
					phi = 0.0f;
				}
			}
		}

		diskSamples[i].x = r * cos(phi);
		diskSamples[i].y = r * sin(phi);
	}
}

void Sampler::mapSamplestoUnitHemisphere(float e) {
	float phi, theta;
	float sinPhi, cosPhi, sinTheta, cosTheta;

	hemisphereSamples.reserve(samples.size());
	for (int i = 0; i < hemisphereSamples.size(); i++) {
		// map coordinates (x, y) to hemisphere coordinates (phi, theta) (= angles)
		phi = 2 * MathUtil::PI * samples[i].x;
		theta = std::pow(1.0f - samples[i].y, 1.0f / (e + 1.0f));

		// spherical coordinate equations
		sinPhi = sin(phi);
		cosPhi = cos(phi);
		cosTheta = theta;
		sinTheta = sqrt(1.0f - cosTheta * cosTheta);

		hemisphereSamples.push_back(Vector3(
			sinTheta * cosPhi,
			sinTheta * sinPhi,
			cosTheta
		));
	}
}
