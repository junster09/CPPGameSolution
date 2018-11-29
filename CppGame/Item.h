#ifndef ITEM_H
#define ITEM_H
#include "Stats.h"
using namespace std;

class Item : public Stats {
public:
	Item()
		: Stats("no - name", 10, 1, 1, 1, "this is a blurb",1,1) {
		setRandItem();
	}

	void setTemp(bool Temp);
	bool getTemp();
	string stringTemp();

	void setType(string Type);
	string getType();

	void setEquipState(bool State);
	bool getEquipState();

	void setRandItem();

	void ItemToString();

protected:
	bool temp; //if item is a single use(like a potion) or permanent(like an equippable weapon)
	bool equip; //if item is equipped to player
	string type;

};

#endif ITEM_H