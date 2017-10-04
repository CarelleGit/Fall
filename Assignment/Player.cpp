#include "Player.h"
#include "sfwdraw.h"






void Player::draw()
{
	//sfw::drawCircle(x, y + 20, 20, 12, GREEN);
	if (forward == true)
	{
		sfw::drawTexture(TextureID, x, y, 50, 100);
	}

	if (sfw::getKey('A'))
	{
		sfw::drawTexture(LtextureID, x, y, 50, 100);
	}
	if (sfw::getKey('D'));
	{
		sfw::drawTexture(RtextureID, x, y, 50, 100);
	}
	if (!sfw::getKey('D') || !sfw::getKey('D'))
	{
		forward = true;
	}
	
	//float halfX = dimX / 2.0f;
	//float halfY = dimY / 2.0f;

	
	//left
	//sfw::drawLine(x - halfX, y - halfY, x - halfX, y + halfY);
	//right
	//sfw::drawLine(x + halfX, y - halfY, x + halfX, y + halfY);
	//top
	//sfw::drawLine(x - halfX, y + halfY, x + halfX, y + halfY);
	//bottom
	//sfw::drawLine(x - halfX, y - halfY, x + halfX, y - halfY);

}

void Player::update()
{
	RtextureID = sfw::loadTextureMap("RPlayer.png");
	TextureID = sfw::loadTextureMap("Player.png");
	LtextureID = sfw::loadTextureMap("LPlayer.png");
	
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
		forward = false;
		x -= 5;
	}
	if (sfw::getKey('D'))
	{
		forward = false;
		x += 5;
	}
	if ((y - dimY / 2) >= 20 )
	{
		y -= gravityForce;
	}
	if (x <= 0)
	{
		x = 800;
	}
	else if (x >= 800)
	{
		x = 0;
	}

	
	
}
