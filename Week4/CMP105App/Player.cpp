#include "Player.h"

void Player::handleInput(float dt) 
{


	if (input->isKeyDown(sf::Keyboard::Right)) 
	{ 
		move(velocity.x * dt,0); 
	}
	
	if (input->isKeyDown(sf::Keyboard::Left)) 
	{ 
		move(-velocity.x * dt,0); 
	}

	if (input->isKeyDown(sf::Keyboard::Up))
	{
		move(0,-velocity.y * dt);
	}

	if (input->isKeyDown(sf::Keyboard::Down))
	{
		move(0,velocity.y * dt);
	}
}