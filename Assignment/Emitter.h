#pragma once
#include "Object.h"

class Emitter : FObject
{
	float spawnAccumulator;

public:
	Emitter();

	// Collection of all particles
	FObject rock[100];

	// Current particle id.
	int rockId;

	// Time between each particle spawned.
	float spawnInterval;

	virtual void update();
	virtual void draw();

};