#include "MultipleObjectsTracer.h"
#include "World.h"

MultipleObjectsTracer::MultipleObjectsTracer(World *world) :
	Tracer(world)
{
}

Vector3 MultipleObjectsTracer::trace(const Ray &ray) {
	ShadingInfo shadingInfo(world->hitObjects(ray));
	if (shadingInfo.hitObject) {
		return shadingInfo.color;
	}
	return world->backgroundColor;
}
