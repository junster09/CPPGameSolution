#include "stdafx.h"
#include <string>
#include <iostream>
#include <random>
#include <iomanip>
#include "Stats.h"
#include "Player.h"

Player::Player(string Name, unsigned int pH, unsigned int pS, unsigned int pW, unsigned int pB, string pBlurb)
	: Stats(Name, pH, pS, pW, pB, pBlurb) {};

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
	maybe serepate the each to different function
	*/
}

void Player::addToInventory(Item& item) {
	inventory.push_back(item);
} //add new found item to the inventory

void Player::addToSpells(Spellcard& spell) {
	spells.push_back(spell);
} //add new found spell(s) to the spell section

void Player::equip(Item& item) {
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

void Player::unequip(Item& item) {
	/*
	hp -= item.hp;
	s -= item.s;
	w -= item.w;
	b -= item.b;
	item.setEquipState(false);
	*/
}