#ifndef ITEM_H
#define ITEM_H
#include "Stats.h"
using namespace std;

class Item : public Stats {
public:
	Item()
		: Stats("no - name", 10, 1, 1, 1, "this is a blurb", 1, 1), nextItemPtr{ nullptr }{
		setRandItem();
	}

	void setTemp(bool Temp);
	bool getTemp();
	string stringTemp() const;

	void setType(string Type);
	string getType() const;

	void setEquipState(bool State);
	bool getEquipState() const;

	void setRandItem();

	void setRandStatsByRoom(unsigned int);

	virtual std::string toString() const override;

	Item* getNextItemPtr() const;
	void setNextItemPtr(Item* tempPtr) { nextItemPtr = tempPtr; }

protected:
	bool temp; //if item is a single use(like a potion) or permanent(like an equippable weapon)
	bool equip; //if item is equipped to player
	string type;
	Item* nextItemPtr;
	//Item* prevItemPtr;

};

#endif ITEM_H