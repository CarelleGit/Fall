#include <iostream>
#include <random>
#include <ctime>
#include "sfwdraw.h"
#include "Player.h"
#include "Helper.h"
#include "Emitter.h"
#include "Object.h"
#include "Collision.h"
#include "Score.h"
#include <string>
using std::cout;
using std::cin;

int main()
{
	unsigned int texture;
	unsigned int cloudT;
	unsigned int cloudT2;
	//unsigned int Time;
	sfw::initContext(800, 600, "Rain");
	//sfw::setBackgroundColor(GREEN);
	srand(time(NULL));
	
	int randx = 0;
	float gravity = 0;
	
	texture = sfw::loadTextureMap("Background.png");
	cloudT = sfw::loadTextureMap("Clouds.png");

	Collision col;
	Player cal;
	cal.x = 400;
	cal.y = 63;
	cal.dimX = 50;
	cal.dimY = 100;
	cal.gravityForce = 6.26f;
	
	Score score;
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
	emitter.spawnInterval = 0.05f;
	while (sfw::stepContext())
	{
		score.update();
		score.draw();
		sfw::drawTexture(cloudT, 400, 550, 800, 100);
		emitter.draw();
		emitter.update();
		if (cal.enable == true)
		{
			cal.update();
			cal.draw();
		}
		

		for (int i = 0; i < 100; i++)
		{


			if (emitter.rock[i].enabled)//(rock[i].enabled)
			{
				if (col.collide(cal.x, cal.y + 20, emitter.rock[i].oX, emitter.rock[i].oY, 20, 10))
				{
					cal.enable = false;
				}
				if (sfw::getKey('R') && cal.enable == false)
				{
					cal.enable = true;
					cal.x = 400;
				}
				if (sfw::getKey(KEY_TAB))
				{
					cal.x = 400;
				}
			}
		}
		sfw::drawTexture(texture, 400, 300, 800, 600);
	}
	sfw::termContext();
}