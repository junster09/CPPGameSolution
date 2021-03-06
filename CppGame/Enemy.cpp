//Use with Enemy.h
#include "stdafx.h"
#include "Enemy.h"

using namespace std;

string enemyNames[10] = { "witch", "librarian","bob","skeleton","goblin",
"floating Head","Not A Floating Head","something","placeholder","notBob" };

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

void Enemy::setRandEnemyByRoom(unsigned int room) {
	setRandEnemy();
	setHP(((rand() % 10 + 10)*room));
	setStat(1, ((rand() % 3 + 1)*room));
	setStat(2, ((rand() % 3 + 1)*room));
	setStat(3, ((rand() % 3 + 1)*room));
}