#include "Object.h"
#include "sfwdraw.h"

void FObject::draw()
{
	sfw::drawCircle(oX, oY, 10);
}

void FObject::update()
{
	oY -= gravity;

}
