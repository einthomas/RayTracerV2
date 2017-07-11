#pragma once

#include "Tracer.h"

class MultipleObjectsTracer : public Tracer {
public:
	MultipleObjectsTracer(World *world);
	Vector3 trace(const Ray &ray) override;
};
