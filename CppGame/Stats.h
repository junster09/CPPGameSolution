#ifndef STATS_H
#define STATS_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Stats {
public:
	Stats(string Name, unsigned int health, unsigned int speed, unsigned int wit, unsigned int brawn, string Blurb)
		: name(Name), hp(health), s(speed), w(wit), b(brawn), blurb(Blurb) {}

	void setName(string Name) { name = Name; }

	string getName() { return name; }

	void setHP(unsigned int HP) { hp = HP; }
	unsigned int getHP() { return hp; }

	void setS(unsigned int S) { s = S; }
	unsigned int getS() { return s; }

	void setBlurb(string Blurb) { blurb = Blurb; }

	unsigned int roll(unsigned int numberOfRolls) { //simulates rolls of a six-sided dice

	}

	string toString() const {
		ostringstream output;
		output << name << endl
			<< blurb << endl
			<< "HP: " << hp << endl
			<< "Speed: " << s << endl
			<< "Wit: " << w << endl
			<< "Brawn: " << b << endl;
		return output.str();
	}

	void setIsDead(bool Dead) { isDead = Dead; }

	void dealDamage() {
		//insert dmg function...
	}

	void takeDamage(unsigned int damage) {
		setHP(getHP() - damage);
		if ((getHP() <= 0) && !isDead) {
			setIsDead(true);
		}
	}

protected:
	string name;
	unsigned int hp; //hit point / health
	unsigned int s;  //speed
	unsigned int w;  //wit
	unsigned int b;  //brawn
	//string attackingStat[s, b, w];
	//string defendingStat[s, b, w];
	bool isDead{ false };
	string blurb; //text blurb for the item / player / enemy
};

#endif STATS_H