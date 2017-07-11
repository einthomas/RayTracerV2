#pragma once

#include <math.h>

#include "Matrix4.h"

class Vector2 {
public:
	double x, y;

	Vector2();
	Vector2(double xy);
	Vector2(double x, double y);
	Vector2(const Vector2 &vector);
	double length();
	void normalize();
	Vector2 getNormalized();

	Vector2 operator+(const Vector2 &vector) const;
	Vector2 &operator+=(const Vector2 &vector);
	Vector2 operator-()  const;
	Vector2 operator-(const Vector2 &vector) const;
	Vector2 operator*(const double a) const;
	double operator*(const Vector2 &vector) const;
	Vector2 &operator*=(const double a);
	Vector2 operator/(const double a) const;
	Vector2 &operator/=(const double a);
};

// addition
inline Vector2 Vector2::operator+(const Vector2 &vector) const {
	return Vector2(x + vector.x, y + vector.y);
}

inline Vector2 &Vector2::operator+=(const Vector2 &vector) {
	x += vector.x;
	y += vector.y;
	return *this;
}

// subtraction
inline Vector2 Vector2::operator-() const {
	return Vector2(-x, -y);
}

inline Vector2 Vector2::operator-(const Vector2 &vector) const {
	return Vector2(x - vector.x, y - vector.y);
}

// multiplication
inline Vector2 Vector2::operator*(const double a) const {		// vector * a
	return Vector2(x * a, y * a);
}

inline double Vector2::operator*(const Vector2 &vector) const {		// dot product
	return x * vector.x + y * vector.y;
}

inline Vector2 &Vector2::operator*=(const double a) {
	x *= a;
	y *= a;
	return *this;
}

// division
inline Vector2 Vector2::operator/(const double a) const {		// vector / a
	return Vector2(x / a, y / a);
}

inline Vector2 &Vector2::operator/=(const double a) {
	x /= a;
	y /= a;
	return *this;
}

// multiplication
Vector2 operator*(const double a, const Vector2 &vector);

inline Vector2 operator*(const double a, const Vector2 &vector) {		// a * vector
	return Vector2(vector.x * a, vector.y * a);
}
