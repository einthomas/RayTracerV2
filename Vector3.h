#pragma once

#include <math.h>

#include "Matrix4.h"

class Vector3 {
public:
	double x, y, z;

	Vector3();
	Vector3(double xyz);
	Vector3(double x, double y, double z);
	Vector3(const Vector3 &vector);
	double length();
	void normalize();
	Vector3 getNormalized();

	Vector3 operator+(const Vector3 &vector) const;
	Vector3 &operator+=(const Vector3 &vector);
	Vector3 operator-()  const;
	Vector3 operator-(const Vector3 &vector) const;
	Vector3 operator*(const double a) const;
	double operator*(const Vector3 &vector) const;
	Vector3 &operator*=(const double a);
	Vector3 operator/(const double a) const;
	Vector3 &operator/=(const double a);
	Vector3 operator^(const Vector3 &vector) const;
};

// addition
inline Vector3 Vector3::operator+(const Vector3 &vector) const {
	return Vector3(x + vector.x, y + vector.y, z + vector.z);
}

inline Vector3 &Vector3::operator+=(const Vector3 &vector) {
	x += vector.x;
	y += vector.y;
	z += vector.z;
	return *this;
}

// subtraction
inline Vector3 Vector3::operator-() const {
	return Vector3(-x, -y, -z);
}

inline Vector3 Vector3::operator-(const Vector3 &vector) const {
	return Vector3(x - vector.x, y - vector.y, z - vector.z);
}

// multiplication
inline Vector3 Vector3::operator*(const double a) const {		// vector * a
	return Vector3(x * a, y * a, z * a);
}

inline double Vector3::operator*(const Vector3 &vector) const {		// dot product
	return x * vector.x + y * vector.y + z * vector.z;
}

inline Vector3 &Vector3::operator*=(const double a) {
	x *= a;
	y *= a;
	z *= a;
	return *this;
}

// division
inline Vector3 Vector3::operator/(const double a) const {		// vector / a
	return Vector3(x / a, y / a, z / a);
}

inline Vector3 &Vector3::operator/=(const double a) {
	x /= a;
	y /= a;
	z /= a;
	return *this;
}

// cross product
inline Vector3 Vector3::operator^ (const Vector3 &vector) const {
	return Vector3(y * vector.z - z * vector.y, z * vector.x - x * vector.z, x * vector.y - y * vector.x);
}

// multiplication
Vector3 operator*(const double a, const Vector3 &vector);

inline Vector3 operator*(const double a, const Vector3 &vector) {		// a * vector
	return Vector3(vector.x * a, vector.y * a, vector.z * a);
}

Vector3 operator*(const Matrix4 &matrix, const Vector3 &vector);

inline Vector3 operator*(const Matrix4 &matrix, const Vector3 &vector) {	// matrix * vector
	return Vector3(
		matrix.values[0][0] * vector.x + matrix.values[0][1] * vector.y + matrix.values[0][2] * vector.z,
		matrix.values[1][0] * vector.x + matrix.values[1][1] * vector.y + matrix.values[1][2] * vector.z,
		matrix.values[2][0] * vector.x + matrix.values[2][1] * vector.y + matrix.values[2][2] * vector.z
	);;
}
