#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include "Stats.h"
#include "Item.h"
#include "Spellcard.h"
using namespace std;

class Player : public Stats {
public:
	Player(string, unsigned int, unsigned int, unsigned int, unsigned int, string);


	void getEquipChoice();

	void addToInventory(Item&);

	void addToSpells(Spellcard&);

	void equip(Item& item);

	void unequip(Item&);
private:
	unsigned int pML; //the player’s max level
	unsigned int pMHP; //max hit point a player can have
	unsigned int pI; // base inventory space available at a time for the player
	vector<Item> inventory;  // this will be a vector so we can use append / push_back whatever it’s called..
	vector<Spellcard> spells; //the spellcard inventory
};

#endif PLAYER_H