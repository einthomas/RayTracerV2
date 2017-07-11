#pragma once

class World;

//#include "World.h"
#include "Vector3.h"


class ShadingInfo {
public:
	bool hitObject;
	Vector3 hitpoint;
	Vector3 hitpointNormal;
	Vector3 color;
	World &world;

	ShadingInfo(World &world);
	ShadingInfo(const ShadingInfo &shadingInfo);
};
