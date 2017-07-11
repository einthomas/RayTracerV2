#include "Sphere.h"
#include "MathUtil.h"

Sphere::Sphere() :
	GeometricObject(Vector3(1.0f)) 
{ }

Sphere::Sphere(float radius, Vector3 position, Vector3 color) :
	radius(radius), position(position), GeometricObject(color)
{ }

/*
	Surface of a sphere is defined as follows
	{p : |p - c| = r}
	p ... a point
	c ... center of the sphere
	r ... radius

	If c = (a, b, c) and p = (x, y, z) then
	(x - a) + (y - b) + (z - c) - r = 0

	To the power of two
	(x - a)^2 + (y - b)^2 + (z - c)^2 - r^2 = 0
	which equals
	<p - c, p - c> - r^2 = 0

	Replace p with the ray equation (o + t * d)
	<o + t * d - c, o + t * d - c> - r^2 = 0
	
	Expanding gives a quadratic equation of the form a * t^2 + b * t + c = 0
	Therefore
	a = <d, d>
	b = <2 * (o - d), d>
	c = <o - c, o - c> - r^2

	The quadratic formula is used to solve the equation
	(-b +- sqrt(b^2 - 4ac)) / 2a
*/
bool Sphere::hit(const Ray& ray, double &tMin, ShadingInfo& shadingInfo) {
	double a = ray.direction * ray.direction;
	double b = 2.0f * (ray.origin - position) * ray.direction;
	double c = (ray.origin - position) * (ray.origin - position) - radius * radius;

	double discriminant = b * b - 4 * a * c;
	if (discriminant < 0) {		// no root
		return false;
	} else {
		double denominator = 2.0 * a;
		double t = (-b - sqrt(discriminant)) / denominator;
		if (t > 1e-90) {
			tMin = t;
			shadingInfo.hitpoint = ray.origin + t * ray.direction;
			shadingInfo.hitpointNormal = (shadingInfo.hitpoint - position).getNormalized();
			return true;
		}

		t = (-b + sqrt(discriminant)) / denominator;
		if (t > 1e-90) {
			tMin = t;
			shadingInfo.hitpoint = ray.origin + t * ray.direction;
			shadingInfo.hitpointNormal = (shadingInfo.hitpoint - position).getNormalized();
			return true;
		}
	}

	return false;
}
