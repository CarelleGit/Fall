#include "Score.h"
#include "sfwdraw.h"

void Score::update()
{
		sTime += sfw::getDeltaTime();
		min = sTime / 60;
		//sec = sTime % 60;

}

void Score::draw()
{
	sfw::drawString(font, "Clock ", 30, 510, 11, 11);
	//sfw::drawString(font, , 100, 510, 11, 11);
}
