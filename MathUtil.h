#pragma once

#include <algorithm>

class MathUtil {
public:
	static const double MathUtil::PI;

	static double degToRad(double deg);
	static double radToDeg(double rad);
	static double clamp(double n, double lower, double upper);
};

float randFloat();

float randFloat(int min, int max);

inline float randFloat() {
	return (float)rand() / RAND_MAX;
}

inline float randFloat(int min, int max) {
	return randFloat() * (max - min) + min;
}
