#pragma once
#include "sfwdraw.h"

class Score
{
public:
	float sTime;
	int font = sfw::loadTextureMap("fontmap.png", 16, 16);
	int min;
	int sec;
	void update();
	void draw();


};