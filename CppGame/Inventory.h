#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"

class Inventory {
public:
	Inventory() {}

	bool isEmpty() const {
		return FirstItem == nullptr; //if true, then its empty
	}

	Item& GetItemByName(string name) {
		if (isEmpty()) {
			return *LastItem;
		}
		CurItem = FirstItem;
		while (CurItem != nullptr) {
			if (CurItem->getName() == name) {
				return *CurItem;
			}
			else {
				CurItem = CurItem->getNextItemPtr();
			}

		}
		cout << "Could not find item of name: " << name << "Please try again";
		return *LastItem;
	}

	void display() {
		if (isEmpty()) {
			cout << "Inventory is currently empty";
		}

		CurItem = FirstItem;
		int i = 0;

		while (CurItem != nullptr) {
			if (i % 5 == 0) {
				cout << "\n";
			}

			cout << CurItem->getName() << " ";

			CurItem = CurItem->getNextItemPtr();

			i++;
		}
	}

	void AddNewRandomItem() {
		Item* newItem = new Item();
		if (isEmpty()) {
			FirstItem = LastItem = newItem;//If empty, therefore the new is the beggining, and the begginning is the end
		}
		else {
			LastItem->setNextItemPtr(newItem);
			LastItem = newItem;
		}
	}
	//void AddNewItem() {}


private:
	Item* FirstItem;
	Item* LastItem;
	Item* CurItem;
	Item* TempItem;
};





#endif