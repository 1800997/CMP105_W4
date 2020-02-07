#pragma once
#include "Framework/GameObject.h"

class Enemy: public GameObject
{
public:
	int dirX = 1;
	int dirY = 1;
	void moveEnemy(float,int,int);
};

