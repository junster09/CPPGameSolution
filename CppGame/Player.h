#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include "Stats.h"
#include "Item.h"
#include "Spellcard.h"
using namespace std;

class Player : protected Stats {
public:
	Player(string Name, unsigned int pH, unsigned int pS, unsigned int pW, unsigned int pB, string pBlurb)
		: Stats(Name, pH, pS, pW, pB, pBlurb) {}


	void getEquipChoice() {
		/*
		armorB = player.armorE; //get equiped armor’s brawn
		armorS = player.armorE; //get equiped armor’s speed
		armorW = player.armorE; //get equiped armor’s wit
		weaponB = player.weaponE; //get equiped weapon’s brawn
		weaponS = player.weaponE; //get equiped weapon’s speed
		weaponW = player.weaponE; //get equiped wepaon’s wit
		totalB = armorB + weaponB;
		totalS = armorS + weaponS;
		totalW = armorW + weaponW;
		maybe serepate the each to different function
		*/
	}

	void addToInventory(Item& item) {
		inventory.push_back(item);
	} //add new found item to the inventory

	void addToSpells(Spellcard& spell) {
		spells.push_back(spell);
	} //add new found spell(s) to the spell section

	void equip(Item& item) {
		/*
		hp += item.getHp();
		s += item.getS();
		w += item.getW();
		b += item.getB();
		if (item.temp == true) {
			inventory.erase(item);
		}
		if (item.temp != true) { item.setEquipState(true); }
		*/
	}

	void unequip(Item& item) {
		/*
		hp -= item.hp;
		s -= item.s;
		w -= item.w;
		b -= item.b;
		item.setEquipState(false);
		*/
	}
private:
	unsigned int pML; //the player’s max level
	unsigned int pMHP; //max hit point a player can have
	unsigned int pI; // base inventory space available at a time for the player
	vector<Item> inventory;  // this will be a vector so we can use append / push_back whatever it’s called..
	vector<Spellcard> spells; //the spellcard inventory
};

#endif PLAYER_H