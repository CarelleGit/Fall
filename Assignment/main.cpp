#include <iostream>
#include <random>
#include <ctime>
#include "sfwdraw.h"
#include "Player.h"
#include "Helper.h"
#include "Emitter.h"
#include "Object.h"

using std::cout;
using std::cin;

int main()
{
	sfw::initContext(800, 600, "Fall");
	sfw::setBackgroundColor(BLACK);
	srand(time(NULL));
	int randx = 0;
	int gravity = 0;
	Player cal;
	cal.x = 400;
	cal.y = 50;
	cal.dimX = 50;
	cal.dimY = 100;
	cal.gravityForce = 6.26f;
	FObject Rock[30];
	for (int i = 0; i < 30; i++)
	{
		randx = rand() % 800;
		gravity = rand() % 10;
		Rock[i].oX = randx;
		Rock[i].oY = 600;
		Rock[i].life = 4.5f;
		Rock[i].gravity = gravity;
	}
	
	Emitter emitter;
		emitter.spawnInterval = 3.0;
	while (sfw::stepContext())
	{
		cal.draw();
		cal.update();
		for (int i = 0; i < 20; i++)
		{
			Rock[i].draw();
			Rock[i].update();
		}
			emitter.draw();
			emitter.update();
	}
	sfw::termContext();
	while (true){}
}