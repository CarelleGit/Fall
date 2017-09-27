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
	int randx = 0;
	int gravity = 0;
	Player cal;
	cal.x = 400;
	cal.y = 50;
	cal.dimX = 50;
	cal.dimY = 100;
	cal.gravityForce = 2.5f;
	FObject fRock;
	fRock.oX = 800;
	fRock.oY = 600;
	fRock.gravity = 1.5f;
	Emitter rock;
	rock.spawnInterval = 3.0f;
	while (sfw::stepContext())
	{
		cal.draw();
		cal.update();

		fRock.draw();
		fRock.update();

		rock.draw();
		rock.update();
	}
	sfw::termContext();
	while (true){}
}