
#pragma once
#ifndef STATS_H
#define STATS_H

#include <iostream>
#include <string>
#include <sstream>

class Stats {
public:
	Stats(std::string, unsigned int, unsigned int, 
		unsigned int, unsigned int, std::string, unsigned int, unsigned int);

	//begin getters and setters
	void setName(std::string);
	std::string getName();

	void setHP(unsigned int);
	unsigned int getHP();

	void setStat(unsigned int, unsigned int);

	const unsigned int getStat(unsigned int);

	void setBlurb(std::string);

	unsigned int roll(unsigned int);

	virtual std::string toString() const;

	void setIsDead(bool);

	void dealDamage(Stats&);

	void takeDamage(unsigned int damage);

	const unsigned int getAttacking();
	void setAttackingStat(unsigned int);
	const unsigned int getDefending();
	void setDefendingStat(unsigned int);

	const std::string getNameOfStat(unsigned int);

protected:
	std::string name;
	unsigned int hp; //hit point / health
	unsigned int s;  //speed
	unsigned int w;  //wit
	unsigned int b;  //brawn
	std::string attackingDefendingStats[4] { "shhh",
		"Speed", "Wit", "Brawn" };
	unsigned int attackingStat;
	unsigned int defendingStat;
	bool isDead{ false };
	std::string blurb; //text blurb for the item / player / enemy
};

#endif STATS_H