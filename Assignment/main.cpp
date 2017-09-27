#include <iostream>
#include "sfwdraw.h"
using std::cout;
using std::cin;

int main()
{
	sfw::initContext(800, 600);
	sfw::setBackgroundColor(BLACK);




	while (sfw::stepContext)
	{

	}
	sfw::termContext();

}