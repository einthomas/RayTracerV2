#pragma once

#include "Vector3.h"
#include "Ray.h"

class World;

class Tracer {
public:
	Tracer(World *world);
	virtual Vector3 trace(const Ray &ray);

protected:
	World *world;
};
