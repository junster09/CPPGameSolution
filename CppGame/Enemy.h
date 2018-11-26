#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
#include "Stats.h"
using namespace std;

class Enemy : private Stats {
public:
	Enemy()
		: Stats("no - name", 10, (rand() % 10), (rand() % 10), (rand() % 10), "this is a blurb")
	{
		setRandEnemy();
	}

	void setRandEnemy() {
		string enemyNames[10] = { "witch", "..." };
		string enemyBlurb[10] = { "this is a witch!", "..." }; //matches indexes of enemy names
		size_t randEnemy = (rand() % 10 + 1);
		setName(enemyNames[randEnemy]);
		setBlurb(enemyBlurb[randEnemy]);
	}
};

#endif ENEMY_H
