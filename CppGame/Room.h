#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
using namespace std;

class Room {
public:
	Room() { setRandName(); setNumber(1); }

	void setNumber(int Number) { roomNumber = Number; }
	int getNumber() { return roomNumber; }

	void setRandName() {
		string roomNames[10] = { "My Room", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
		name = roomNames[(rand() % 10)];
	}
	string getName() { return name; }

	Room& operator++() {
		++roomNumber;
		setRandName();
		return *this;
	}

	void toString() {
		cout << "Room: " << name << endl
			<< "# : " << roomNumber << endl;
	}

private:
	string name;
	int roomNumber;
};

#endif ROOM_H
