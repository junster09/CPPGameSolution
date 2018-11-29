#ifndef ENEMY_H
#define ENEMY_H
#include "Stats.h"
using namespace std;

class Enemy : public Stats {
public:
	Enemy() 
		: Stats("no - name", 10, 
		(rand() % 10), (rand() % 10), (rand() % 10), "this is a blurb",1,1)
	{
		setRandEnemy();
	}

	void setRandEnemy();
};

#endif ENEMY_H
