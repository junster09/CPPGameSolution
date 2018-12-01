//Use with Enemy.h
#include "stdafx.h"
#include "Enemy.h"

using namespace std;

string enemyNames[10] = { "witch", "..." };

string enemyBlurb[10] = { "this is a witch!", "..." }; //matches indexes of enemy names

unsigned int StatsTypeEnemyA[10] = { 1, 2, 3, 1, 2, 3, 1, 1, 1, 1 };

unsigned int StatsTypeEnemyD[10] = { 1, 2, 3, 1, 2, 3, 1, 1, 1, 1 };

void Enemy::setRandEnemy() {
	size_t randEnemy = (rand() % 10);
	setName(enemyNames[randEnemy]);
	setBlurb(enemyBlurb[randEnemy]);
	setAttackingStat(StatsTypeEnemyA[randEnemy]);
	setDefendingStat(StatsTypeEnemyD[randEnemy]);
}