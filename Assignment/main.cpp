#include <iostream>
#include <random>
#include <ctime>
#include "sfwdraw.h"
#include "Player.h"
#include "Helper.h"
#include "Emitter.h"
#include "Object.h"
#include "Collision.h"

using std::cout;
using std::cin;

int main()
{
	sfw::initContext(800, 600, "Rain");
	sfw::setBackgroundColor(BLACK);
	srand(time(NULL));
	int randx = 0;
	float gravity = 0;
	Collision col;
	Player cal;
	cal.x = 400;
	cal.y = 50;
	cal.dimX = 50;
	cal.dimY = 100;
	cal.gravityForce = 6.26f;
	/*FObject Rock[30];
	

	for (int i = 0; i < 30; i++)
	{
		randx = rand() % 800 + 1;
		gravity = rand() % 10 + 3;
		Rock[i].oX = randx;
		Rock[i].oY = 700;
		Rock[i].life = 4.5f;
		Rock[i].gravity = gravity;
		Rock[i].aTime = 0.0f;
	}*/

	Emitter emitter;
	emitter.spawnInterval = 0.0;
	while (sfw::stepContext())
	{
	for (int i = 0; i < 30; i++)
	{
		if (emitter.rock[i].enabled)//(rock[i].enabled)
		{
			if (col.collide(cal.x, cal.y, emitter.rock[i].oX, emitter.rock[i].oY, 30, 10))
			{
				cal.enable = false;
			}
			if (sfw::getKey('R'))
			{
				cal.enable = true;
			}
		}
	}
		if (cal.enable == true)
		{
			cal.draw();
			cal.update();
			
		}
		emitter.draw();
		emitter.update();
	}
	sfw::termContext();
}