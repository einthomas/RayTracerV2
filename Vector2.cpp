#include "Vector2.h"

Vector2::Vector2()
	: x(0.0), y(0.0)
{ }

Vector2::Vector2(double xy)
	: x(xy), y(xy)
{ }

Vector2::Vector2(double x, double y)
	: x(x), y(y)
{ }

Vector2::Vector2(const Vector2 &vector)
	: x(vector.x), y(vector.y)
{ }

double Vector2::length() {
	return sqrt(x * x + y * y);
}

void Vector2::normalize() {
	double length = sqrt(x * x + y * y);
	x /= length;
	y /= length;
}

Vector2 Vector2::getNormalized() {
	double length = sqrt(x * x + y * y);
	return Vector2(x / length, y / length);
}
