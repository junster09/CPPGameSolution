//Use with Spellcard.h
#include "stdafx.h"
#include<iostream>
#include<string>
#include "Spellcard.h"
#include "Item.h"
#include "Stats.h"

using namespace std;

string spellNames[14] = { "Fireball", "Icewave", "Meteorite", "Lightning Rod",
	"Helping Hand", "Revive", "Oxide Plate",
	"HP +10", "S +1d6", "W +1d6", "B +1d6",
	"Skip Enemy", "Double Strike", "Riot Shield" };

string spellBlurb[14] = { "Fire!", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14" }; //matches indexes of spell names

string spellType[14] = { "Damage", "Damage", "Damage", "Damage",
	"Heal", "Heal", "Heal",
	"Buff", "Buff", "Buff", "Buff",
	"Status", "Status", "Status" };

void Spellcard::setRandSpell() {

	
	size_t randIndex = (rand() % 14);

	setType(spellType[randIndex]);
	setName(spellNames[randIndex]);
	setBlurb(spellBlurb[randIndex]);
}

void Spellcard::SpellToString() {
	toString();
	cout << "Type: " << getType();
}