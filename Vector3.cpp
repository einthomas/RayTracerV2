#include "Vector3.h"

Vector3::Vector3()
	: x(0.0), y(0.0), z(0.0)
{ }

Vector3::Vector3(double xyz)
	: x(xyz), y(xyz), z(xyz)
{ }

Vector3::Vector3(double x, double y, double z)
	: x(x), y(y), z(z)
{ }

Vector3::Vector3(const Vector3 &vector)
	: x(vector.x), y(vector.y), z(vector.z)
{ }

double Vector3::length() {
	return sqrt(x * x + y * y + z * z);
}

void Vector3::normalize() {
	double length = sqrt(x * x + y * y + z * z);
	x /= length;
	y /= length;
	z /= length;
}

Vector3 Vector3::getNormalized() {
	double length = sqrt(x * x + y * y + z * z);
	return Vector3(x / length, y / length, z / length);
}
