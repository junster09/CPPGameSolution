//Use with Item.h
#include "stdafx.h"
#include "Item.h"

using namespace std;

string itemNames[10] = { "Normal Armor", "Stick", 
"Dark Armor", "Big Stick", "An Armor", "An Sword", "thingy", "thingy2", "thingy3", "thingy4" };

string itemBlurb[10] = { "\n\tNormal Armor: an armor made of mesh or something",
"\n\tStick: a slightly sharp stick you found off of the ground", 
"\n\tDark Armor: its like normal armor, but painted black", 
"\n\tBig Stick: a slightly bigger stick you found off of the ground, its not particularly better than a stick", 
"\n\tAn Armor: its armor, it doesn't look and or smell good", 
"\n\tAn Sword: its a sword you found off the ground, it doesn't look or smell good", 
"\n\tthingy: something that you found on the ground, it looks cool at least", 
"\n\tthingy2: something that you found on the ground, it smells good at least", 
"\n\tthingy3: something that you found on the ground, it makes a pleasant sound", 
"\n\tthingy4: something that you found on the ground, it tastes like strawberries" };

bool itemTemp[10] = { false,false,false,false,false,false,true,true,true,true };

string itemType[10] = { "armor", "weapon", "armor", "weapon", "armor", "weapon", "item", "item", "item", "item" };

unsigned int StatsType[10] = { 1, 2, 3, 1, 2, 3, 1, 1, 1, 1 };

unsigned int StatsTypeItems[10] = { 1, 2, 3, 1, 2, 3, 1, 1, 1, 1 };

void Item::setTemp(bool Temp) {
	temp = Temp;
}

bool Item::getTemp() {
	return temp; 
}

string Item::stringTemp() const {
	if (temp == true) { return "Yes"; }
	else {
		return "No";
	}
}

void Item::setType(string Type) { 
	type = Type;
}

string Item::getType() const { 
	return type;
}

void Item::setEquipState(bool State) { 
	equip = State;
}

bool Item::getEquipState() const {
	return equip;
}

void Item::setRandItem() {
	size_t randIndex = (rand() % 10);
	setType(itemType[randIndex]);
	setName(itemNames[randIndex]);
	setBlurb(itemBlurb[randIndex]);
	setTemp(itemTemp[randIndex]);
	setAttackingStat(StatsType[randIndex]);
	setDefendingStat(StatsType[randIndex]);
}

void Item::setRandStatsByRoom(unsigned int room) {
	setHP(((rand() % 10 + 10)*room));
	setStat(1, ((rand() % 3 + 1)*room));
	setStat(2, ((rand() % 3 + 1)*room));
	setStat(3, ((rand() % 3 + 1)*room));
}

string Item::toString() const {
	ostringstream output;
	output <<"\n"<< Stats::toString()<<"Is Consumable: " << stringTemp() << endl
		<< "Equip State : " << getEquipState() << endl
		<< "Type : " << getType()<<"\n";
	return output.str();
}

Item* Item::getNextItemPtr() const {
	return nextItemPtr;
}