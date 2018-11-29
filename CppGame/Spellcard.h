#ifndef SPELLCARD_H
#define SPELLCARD_H
#include "Item.h"
using namespace std;

class Spellcard : public Item {
public:
	Spellcard()
		: Item()
	{
		setRandSpell();
		setTemp(true);
	}

	void setRandSpell();

	void SpellToString();

	/*
	Dmg: Fireball, Icewave, Meteorite, Lighting Rod
	Heal: Helping Hand, Revive(rare), Oxide Plate
	Buffs: Hp+10, S+1d6,W+1d6,B+1d6
	Status: Skip (enemy), Double strike, Riot Shield
	*/
};

#endif SPELLCARD_H
