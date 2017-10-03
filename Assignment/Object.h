#pragma once
#include "Collision.h"

class FObject 
{
public:
	float oX;
	float oY;
	int rad;
	float life;
	float aTime;
	float gravity;
	bool enabled;

	virtual void draw();
	virtual void update();

};
