#include "ShadingInfo.h"

ShadingInfo::ShadingInfo(World& world) :
	hitObject(false),
	world(world)
{ }

ShadingInfo::ShadingInfo(const ShadingInfo& shadingInfo) :
	hitObject(shadingInfo.hitObject),
    hitpoint(shadingInfo.hitpoint),
	hitpointNormal(shadingInfo.hitpointNormal),
	color(shadingInfo.color),
	world(shadingInfo.world)
{ }
