#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"

class Inventory {
public:
	Inventory() {}

	bool isEmpty() const {
		return FirstItem == nullptr; //if true, then its empty
	}

	Item* GetItemByName(string name) {
		if (isEmpty()) {
			return FirstItem;
		}
		CurItem = FirstItem;

		while (CurItem != nullptr) {
			if (CurItem->getName() == name) {
				return CurItem;
			}
			else {
				CurItem = CurItem->getNextItemPtr();
			}

		}
		cout << "Could not find item of name: " << name << " Please try again";
		return nullptr;
	}

	void display() {
		if (isEmpty()) {
			cout << "Inventory is currently empty";
		}

		CurItem = FirstItem;
		int i = 0;

		while (CurItem != nullptr) {
			if (i % 3 == 0) {
				cout << "\n";
			}

			cout << CurItem->getName() << "  ";

			CurItem = CurItem->getNextItemPtr();

			i++;
		}
	}

	void AddNewRandomItem(unsigned int roomNumber) {
		Item* newItem = new Item();
		newItem->setRandStatsByRoom(roomNumber);
		if (isEmpty()) {
			FirstItem = LastItem = newItem;//If empty, therefore the new is the beggining, and the begginning is the end
		}
		else {
			LastItem->setNextItemPtr(newItem);
			LastItem = newItem;
		}
	}

	void RemoveFromItems(Item* ItemToDestroy) {
		if (isEmpty()) {
			cout << "ITS ALL GONE ALREADY!";
		}
		CurItem = FirstItem;
		while (CurItem != nullptr) {
			if (CurItem->getNextItemPtr() == ItemToDestroy) {
				CurItem->setNextItemPtr(ItemToDestroy->getNextItemPtr());
				delete ItemToDestroy;
				break;
			}
			CurItem = CurItem->getNextItemPtr();
		}

	}


private:
	Item* FirstItem;
	Item* LastItem;
	Item* CurItem;
	Item* TempItem;
};





#endif