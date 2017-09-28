#include "Emitter.h"
#include "sfwdraw.h"
Emitter::Emitter()
{
	for (int i = 0; i < 100; ++i)
	{
		rock[i].enabled = false;
	}

	spawnAccumulator = 0.0f;

}

void Emitter::update()
{
	spawnAccumulator += sfw::getDeltaTime();

	// check if it's time to spawn a new one
	// if so, create one!
	if (spawnAccumulator > spawnInterval)
	{
		// look for a particle that isn't in use
		for (int i = 0; i < 100; ++i)
		{
			if (rock[i].enabled == false)
			{
				// reactivate it
				FObject& baby = rock[i];

				baby.oX = 400;
				baby.oY = 300;
				baby.gravity = 0.5f;

				baby.enabled = true;

				spawnAccumulator = 1.0f;
				if (rock[i].oY <= 5)
				{
					break;
				}
			}
		}
	}

	// update all of the particles that are active
	for (int i = 0; i < 100; ++i)
	{
		if (rock[i].enabled == true)
		{
			rock[i].update();
		}
	}
}

void Emitter::draw()
{
	
	for (int i = 0; i < 100; ++i)
	{
		rock[i].enabled = false;
	}

	spawnAccumulator = 1.0f;

}
