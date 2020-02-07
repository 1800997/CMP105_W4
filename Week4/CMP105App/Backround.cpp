#include "Backround.h"


int Backround::moveView(int viewCenter,int viewSize)
{
	int speed=0;
	if (input->isKeyDown(sf::Keyboard::D) && (viewCenter+(viewSize/2)) <= 11038)
	{
		 speed = 3;
	}
	if (input->isKeyDown(sf::Keyboard::A) && (viewCenter - (viewSize / 2)) >= 0)
	{
		 speed = -3;
	}
	return speed;
}