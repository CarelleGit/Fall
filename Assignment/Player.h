#pragma once


class Player
{
public:
	float x;
	float y;
	float dimX;
	float dimY;
	float gravityForce;

	void draw();
	void update();
};
