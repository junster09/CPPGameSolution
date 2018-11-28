//Use with Item.h
#include <iostream>
#include <string>
#include "Item.h"
#include "Stats.h"

using namespace std;

void Item::setTemp(bool Temp) {
	temp = Temp;
}

bool Item::getTemp() {
	return temp; 
}

string Item::stringTemp() {
	if (temp = true) { return "Temporary"; }
	else {
		return "Permanent";
	}
}

void Item::setType(string Type) { 
	type = Type;
}

string Item::getType() { 
	return type;
}

void Item::setEquipState(bool State) { 
	equip = State;
}

bool Item::getEquipState() {
	return equip;
}

void Item::setRandItem() {

	string itemNames[10] = { "Stick", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
	string itemBlurb[10] = { "AJ please add details", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
	bool itemTemp[10] = { false,false,false,false,false,false,false,false,false,false };
	string itemType[10] = { "armor", "weapon", "armor", "weapon", "armor", "weapon", "item", "item", "item", "item" };
	unsigned int StatsType[10] = { 1, 2, 3, 1, 2, 3, 1, 1, 1, 1 };
	//matches indexes of item names

	size_t randIndex = (rand() % 10 + 1);
	setType(itemType[randIndex]);
	setName(itemNames[randIndex]);
	setBlurb(itemBlurb[randIndex]);
	setTemp(itemTemp[randIndex]);
	setAttackingStat(StatsType[randIndex]);
	setDefendingStat(StatsType[randIndex]);
}

void Item::ItemToString() {
	toString();
	cout << "Is Temporary: " << stringTemp() << endl
		<< "Equip State : " << getEquipState() << endl
		<< "Type : " << getType();
}