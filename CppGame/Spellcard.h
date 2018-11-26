#ifndef SPELLCARD_H
#define SPELLCARD_H
#include <iostream>
#include <string>
#include "Item.h"
#include "Stats.h"
using namespace std;

class Spellcard : private Item {
public:
	Spellcard()
		: Stats("no - name", 10, (rand() % 5), (rand() % 5), (rand() % 5), "this is a blurb")
	{
		setRandSpell();
		setTemp(true);
	}

	void setRandSpell() {
		string spellNames[14] = { "Fireball", "Icewave", "Meteorite", "Lightning Rod",
								 "Helping Hand", "Revive", "Oxide Plate",
								 "HP +10", "S +1d6", "W +1d6", "B +1d6",
								 "Skip Enemy", "Double Strike", "Riot Shield" };
		string spellBlurb[14] = { "Fire!", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14" };
		//matches indexes of spell names
		size_t randIndex = (rand() % 14 + 1);
		string spellType[14] = { "Damage", "Damage", "Damage", "Damage",
								"Heal", "Heal", "Heal",
								"Buff", "Buff", "Buff", "Buff",
								"Status", "Status", "Status" };
		setType(spellType[randIndex]);
		//setName(spellNames[randIndex]);
		//setBlurb(spellBlurb[randIndex]);
	}

	void SpellToString() {
		//toString();
		cout << "Type: " << getType();
	}

	/*
	Dmg: Fireball, Icewave, Meteorite, Lighting Rod
	Heal: Helping Hand, Revive(rare), Oxide Plate
	Buffs: Hp+10, S+1d6,W+1d6,B+1d6
	Status: Skip (enemy), Double strike, Riot Shield
	*/
};

#endif SPELLCARD_H
