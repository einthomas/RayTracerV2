#include "Ray.h"

Ray::Ray() : origin(0.0), direction(0.0) {
}

Ray::Ray(const Vector3& origin, const Vector3& direction) : origin(origin), direction(direction) {
}

Ray::Ray(const Ray& ray) : origin(ray.origin), direction(ray.direction) {
}
