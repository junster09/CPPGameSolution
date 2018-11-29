//Use with Room.h
#include<iostream>
#include<string>
#include "Room.h"

using namespace std;

void Room::setNumber(int Number) { 
	roomNumber = Number;
}

int Room::getNumber() { 
	return roomNumber;
}

void Room::setRandName() {
	string roomNames[10] = { "My Room", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
	name = roomNames[(rand() % 10)];
}

string Room::getName() { 
	return name;
}

void Room::toString() {
	cout << "Room: " << name << endl
		<< "# : " << roomNumber << endl;
}