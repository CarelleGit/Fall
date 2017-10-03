#include "Player.h"
#include "sfwdraw.h"






void Player::draw()
{
	float halfX = dimX / 2.0f;
	float halfY = dimY / 2.0f;

	//sfw::drawCircle(x, y + 40, 30, 12 ,GREEN);
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
	
	if (sfw::getKey('W') && isJump == false)
	{
		y += 30;
		
	}
	if (y >= 120 && isJump == false)
	{
		isJump = true;
	}
	else if (y <= 120 && isJump == true)
	{
		isJump = false;
	}
	
	if (sfw::getKey('A'))
	{
		x -= 5;
	}
	if (sfw::getKey('D'))
	{
		x += 5;
	}
	if ((y - dimY / 2) >= 0)
	{
		
		y -= gravityForce;
		Ismellbad;
	}
	if (x == 0)
	{
		x = 800;
	}
	else if (x == 800)
	{
		x = 0;
	}

	
	
}
