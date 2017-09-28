#include "Player.h"
#include "sfwdraw.h"






void Player::draw()
{
	float halfX = dimX / 2.0f;
	float halfY = dimY / 2.0f;

	//left
	sfw::drawLine(x - halfX, y - halfY, x - halfX, y + halfY);
	//right
	sfw::drawLine(x + halfX, y - halfY, x + halfX, y + halfY);
	//top
	sfw::drawLine(x - halfX, y + halfY, x + halfX, y + halfY);
	//bottom
	sfw::drawLine(x - halfX, y - halfY, x + halfX, y - halfY);

}

void Player::update()
{
	if (sfw::getKey('W'))
	{
		y += 10;

		if (y >= 200)
		{
			y = 200;
		}
		
	}
	if (sfw::getKey('A'))
	{
		x -= 5;
	}
	if (sfw::getKey('D'))
	{
		x += 5;
	}
	if ((y - dimY / 2) > 0)
	{
		y -= gravityForce;

	}
}
