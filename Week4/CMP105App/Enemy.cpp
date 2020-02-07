#include "Enemy.h"

void Enemy::moveEnemy(float dt,int maxX,int maxY)
{

	int enemyPosX = getPosition().x;
	int enemyPosY = getPosition().y;

	if (enemyPosX + 80 >= maxX || enemyPosX <= 0)
	{
		dirX = -dirX;
	}
	else if (enemyPosY <= 0 || enemyPosY + 80 >= maxY)
	{
		dirY = -dirY;
	}

	move(velocity.x * dt * dirX, velocity.y * dt * dirY);
}
