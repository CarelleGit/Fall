#pragma once
#include "Collision.h"

class Player : public Collision
{
public:
	float x;
	float y;
	float dimX;
	float dimY;
	bool enable = true;
	float gravityForce;
	bool isJump = false;
	void draw();
	void update();
};
