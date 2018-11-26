#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include "Stats.h"
using namespace std;

class Item : protected Stats {
public:
	Item()
		: Stats("no - name", 10, (rand() % 5), (rand() % 5), (rand() % 5), "this is a blurb") {
		setRandItem();
	}

	void setTemp(bool Temp) { temp = Temp; }
	bool getTemp() { return temp; }
	string stringTemp() {
		if (temp = true) { return "Temporary"; }
		else {
			return "Permanent";
		}
	}

	void setType(string Type) { type = Type; }
	string getType() { return type; }

	void setEquipState(bool State) { equip = State; }
	bool getEquipState() { return equip; }

	void setRandItem() {
		string itemNames[10] = { "Stick", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
		string itemBlurb[10] = { "AJ please add details", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
		bool itemTemp[10] = { false,false,false,false,false,false,false,false,false,false };
		//matches indexes of item names
		string itemType[10] = { "Crustacean", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
		size_t randIndex = (rand() % 10 + 1);
		setType(itemType[randIndex]);
		setName(itemNames[randIndex]);
		setBlurb(itemBlurb[randIndex]);
		setTemp(itemTemp[randIndex]);
	}

	void ItemToString() {
		toString();
		cout << "Is Temporary: " << stringTemp() << endl
			<< "Equip State : " << getEquipState() << endl
			<< "Type : " << getType();
	}

protected:
	bool temp; //if item is a single use(like a potion) or permanent(like an equippable weapon)
	bool equip; //if item is equipped to player
	string type;

};

#endif ITEM_H