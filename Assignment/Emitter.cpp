#include "Emitter.h"
#include "sfwdraw.h"
#include <random>
#include <ctime>
Emitter::Emitter()
{
	for (int i = 0; i < 100; i++)
	{
		rock[i].enabled = false;
	}
}

void Emitter::update()
{
	// check if it's time to spawn a new one
	//if so, create one!\
	    spawnAccumulator += sfw::getDeltaTime();


//update all of the particles that are active

	float timer = sfw::getDeltaTime();

	if (spawnAccumulator > spawnInterval)
	{
		//look for a particle that isn't in use
		for (int i = 0; i < 100; i++)
		{
			if (rock[i].enabled == false)
			{
				//reactivate it
				FObject& baby = rock[i];

				baby.oX = (rand() % 800 + 1);
				baby.oY = 600;

				baby.gravity = (rand() % 10 + (-5));
				


				baby.enabled = true;

				rock[i].aTime = 0.0f;
				rock[i].life = 0.5f;

				spawnAccumulator = 0.0f;
				break;

			}
		}



	}
	//update all of the particles that are active
	for (int i = 0; i < 100; i++)
	{

		if (rock[i].aTime > timer + 1.5f)
		{
			rock[i].enabled == false;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		if (rock[i].enabled == true)
		{
			rock[i].update();
		}
	}

}

void Emitter::draw()
{
	for (int i = 0; i < 100; i++)
	{
		if (rock[i].enabled == true)
		{
			rock[i].draw();
		}

	}
}
