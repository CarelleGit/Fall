#include "Emitter.h"
#include "sfwdraw.h"
#include <random>
#include <ctime>
Emitter::Emitter()
{
	textureID = sfw::loadTextureMap("Rain.png");
	
	spawnAccumulator = 0.0f;
	for (int i = 0; i < 100; i++)
	{
		rock[i].enabled = false;
		rock[i].textureID = textureID;
	}
}

void Emitter::update()
{
	// check if it's time to spawn a new one
	//if so, create one!
	    spawnAccumulator += sfw::getDeltaTime();


//update all of the particles that are active

	float timer = sfw::getDeltaTime();

	if (spawnAccumulator > spawnInterval)
	{
		//look for a particle that isn't in use
		for (int i = 0; i < 100; i++)
		{
			//float tmpTime = 0.0f;
			//tmpTime += sfw::getDeltaTime();

			//while(tmpTime < 1.0f)
			//{
			//	int hi = 0;
			//	hi += 1;
			//}

				if (rock[i].enabled == false)
				{
					//reactivate it
					FObject& baby = rock[i];

					baby.oX = (rand() % 800 + 1);
					baby.oY = (rand() % 600 + 700);

					baby.gravity = (rand() % 100 + 80) * sfw::getDeltaTime();



					baby.enabled = true;

					rock[i].aTime = 0.0f;
					rock[i].life = 15.5f;

					spawnAccumulator = 0.0f;
					//tmpTime = 0.0f;
					break;
				}


		}



	}
	//update all of the particles that are active
	//for (int i = 0; i < 100; i++)
	//{

	//	if (rock[i].aTime > timer + 1.5f)
	//	{
	//		rock[i].enabled == false;
	//	}
	//}

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
