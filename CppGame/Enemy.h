#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
#include "Stats.h"
using namespace std;

class Enemy : public Stats {
public:
	Enemy() 
		: Stats("no - name", 10, (rand() % 10), (rand() % 10), (rand() % 10), "this is a blurb")
	{
		setRandEnemy();
	}

	void setRandEnemy();
};

#endif ENEMY_H
