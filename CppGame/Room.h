#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
using namespace std;

class Room {
public:
	Room() { setRandName(); setNumber(1); }

	void setNumber(int Number);
	int getNumber();

	void setRandName();
	string getName();

	Room& operator++() {
		++roomNumber;
		setRandName();
		return *this;
	}

	void toString();

private:
	string name;
	int roomNumber;
};

#endif ROOM_H
