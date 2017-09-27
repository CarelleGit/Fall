#pragma once


class FObject
{
public:
	float oX;
	float oY;
	int rad;
	float gravity;
	bool enabled;

	virtual void draw();
	virtual void update();

};
