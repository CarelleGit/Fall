#pragma once
#include "Collision.h"

class Player : public Collision
{
public:
	int TextureID;
	int LtextureID;
	int RtextureID;
	bool forward = true;
	float x;
	float y;
	float dimX;
	float dimY;
	bool enable = true;
	float gravityForce;
	bool isJump = false;
	bool isFalling = false;
	void draw();
	void update();
};
