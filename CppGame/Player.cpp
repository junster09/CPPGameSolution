#include "stdafx.h"
#include <random>
#include <iomanip>
#include "Player.h"

Player::Player(string Name, unsigned int pH, unsigned int pS, unsigned int pW, unsigned int pB, string pBlurb)
	: Stats(Name, pH, pS, pW, pB, pBlurb,3,1) {};

void Player::getEquipChoice() {
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
	//maybe serepate the each to different function
	*/
}

void Player::addToInventory(Item item) {
} //add new found item to the inventory

void Player::addToSpells(Spellcard spell) {
} //add new found spell(s) to the spell section

void Player::equip(Item& item) {
	if (item.getType() == "item") {
		changeStats(item, true);
	}
	else if ((item.getType() == "armor" && !equippedArmor)) {
		changeStats(item, true);
		defendingStat = item.getDefending();
		cout << "\nArmor Equipped!";
		equippedArmor = true;
	}
	else if ((item.getType() == "weapon" && !equippedWeapon)) {
		changeStats(item, true);
		attackingStat = item.getAttacking();
		equippedWeapon = true;
		cout << "\nWeapon Equipped!";
	}
	else {
		cout << "\nUnable to equip type: " << item.getType() << " try unequipping an item first.\n";
	}

	if (item.getTemp() == true) {
	}
	if (item.getTemp() != true) { item.setEquipState(true); }
}

void Player::unequip(Item& item) {
	if (item.getType() == "item") {
		changeStats(item, false);
	}
	else if ((item.getType() == "armor" && equippedArmor)) {
		changeStats(item, false);
		defendingStat = 1;//default speed
		equippedArmor = false;
	}
	else if ((item.getType() == "weapon" && equippedWeapon)) {
		changeStats(item, false);
		attackingStat = 3;//default brawn
		equippedWeapon = false;
	}
	item.setEquipState(false);
}

void Player::changeStats(Item& item, bool isAdding) {
	if (isAdding) {
		hp += item.getHP();
		s += item.getStat(1);
		w += item.getStat(2);
		b += item.getStat(3);
	}
	else {//safetey measure incase if a stat goes below 0
		if (item.getStat(1) >= s) { s = 0; }
		else { s -= item.getStat(1); }

		if (item.getStat(2) >= w) { w = 0; }
		else { w -= item.getStat(2); }

		if (item.getStat(3) >= b) { b = 0; }
		else { b -= item.getStat(3); }
	}

}

void Player::showInventory() {
	itemBag.display();
}

Inventory* Player::getItemBag() {
	return &itemBag;
}

Inventory* Player::getSpellBag(){
	return &spellBag;
}