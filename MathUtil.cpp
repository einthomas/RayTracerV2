#include "MathUtil.h"

const double MathUtil::PI = 3.14159265359f;

double MathUtil::degToRad(double deg) {
	return deg * MathUtil::PI / 180.0f;
}

double MathUtil::radToDeg(double rad) {
	return rad * 180 / MathUtil::PI;
}

double MathUtil::clamp(double n, double lower, double upper) {
	return std::max(lower, std::min(n, upper));
}
