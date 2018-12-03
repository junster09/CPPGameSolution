#include "stdafx.h"
#include <string>
#include <iostream>
#include <random>
#include <iomanip>
#include "Stats.h"
using namespace std;

Stats::Stats(string Name, unsigned int health, unsigned int speed, unsigned int wit, 
	unsigned int brawn, string Blurb, unsigned int aStat, unsigned int dStat)
	: name(Name), hp(health), s(speed), w(wit), b(brawn), blurb(Blurb), attackingStat(aStat), defendingStat(dStat) {};

//begin getters and setters
void Stats::setName(string Name) { name = Name; }
string Stats::getName() { return name; }

void Stats::setHP(unsigned int HP) { hp = HP; }
unsigned int Stats::getHP() { return hp; }

void Stats::setStat(unsigned int selector, unsigned int change) {
	switch (selector) {
	case 1://its speed
		s = change;
		break;
	case 2://its wit
		w = change;
		break;
	case 3://its brawn
		b = change;
		break;
	default:
		cout << "Setter machine broke";//it :b:roke
	}
}

const unsigned int Stats::getStat(unsigned int selector) {
	switch (selector) {
	case 1://its speed
		return s;
		break;
	case 2://its wit
		return w;
		break;
	case 3://its brawn
		return b;
		break;
	default:
		return 0;
		cout << "getter machine broke";//it :b:roke
	}
}

void Stats::setBlurb(string Blurb) { blurb = Blurb; }

unsigned int Stats::roll(unsigned int numberOfRolls) { //simulates rolls of a six-sided dice
	unsigned int sum{ 0 };
	for (unsigned int i{ 1 };i <= numberOfRolls;i++) {
		sum += (rand() % 6) + 1;
	}
	return sum;
}

string Stats::toString() const {
	ostringstream output;
	output << "Name: " << name << endl
		<< blurb << endl
		<< "HP: " << hp << endl
		<< "Speed: " << s << endl
		<< "Wit: " << w << endl
		<< "Brawn: " << b << endl;
	return output.str();
}

void Stats::setIsDead(bool Dead) { isDead = Dead; }

void Stats::dealDamage(Stats& target) {
	unsigned int damage = roll(getStat(attackingStat));
	target.takeDamage(damage);
}

void Stats::takeDamage(unsigned int damage) {
	unsigned int defendRoll = roll(getStat(defendingStat));
	if (damage <= defendRoll) {
		damage = 0;
	}
	else {
		damage = damage - defendRoll;
	}

	cout << "\n" << name << " took " << damage << " damage!";

	if (damage >= hp) {
		cout << " and died";
		hp = 0;
	}
	else {
		hp -= damage;
	}
	cout << endl;
}

const unsigned int Stats::getAttacking() {return attackingStat;}
const unsigned int Stats::getDefending() {return defendingStat;}
void Stats::setAttackingStat(unsigned int a) { attackingStat = a; }
void Stats::setDefendingStat(unsigned int d) { defendingStat = d; }

const string Stats::getNameOfStat(unsigned int selector) {
	switch (selector) {
	case 1://its speed
		return "Speed";
		break;
	case 2://its wit
		return "Wit";
		break;
	case 3://its brawn
		return "Brawn";
		break;
	default:
		return ":B:roke";
	}

}