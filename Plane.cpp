#include "Plane.h"

Plane::Plane() :
	GeometricObject(Vector3(1.0f))
{ }

Plane::Plane(const Vector3& point, const Vector3& normal, const Vector3 &color) :
	point(point), normal(normal), GeometricObject(color)
{ }

/*
	Plane equation
	<(p - a), n> = 0

	Replace p with the ray equation (o + t * d)
	<(o + t * d - a), n> = 0

	Solve for t
	t = (a - o) * n / (<d, n>)
*/
bool Plane::hit(const Ray& ray, double &tMin, ShadingInfo& shadingInfo) {
	double t = (point - ray.origin) * normal / (ray.direction * normal);
	if (t > 1e-90) {
		tMin = t;
		shadingInfo.hitObject = true;
		shadingInfo.hitpointNormal = normal;
		shadingInfo.hitpoint = ray.origin + t * ray.direction;
		return true;
	} else {
		shadingInfo.hitObject = false;
		return false;
	}
}
