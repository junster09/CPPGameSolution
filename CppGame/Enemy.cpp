//Use with Enemy.h
#include<iostream>
#include<string>
#include "Enemy.h"
#include "Stats.h"

using namespace std;

void Enemy::setRandEnemy() {
	string enemyNames[10] = { "witch", "..." };
	string enemyBlurb[10] = { "this is a witch!", "..." }; //matches indexes of enemy names
	size_t randEnemy = (rand() % 10 + 1);
	setName(enemyNames[randEnemy]);
	setBlurb(enemyBlurb[randEnemy]);
}