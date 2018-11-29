//Use with Room.h
#include "stdafx.h"
#include "Room.h"

using namespace std;

string roomNames[10] = { "My Room", "2", "3", "4", "5", "6", "7", "8", "9", "10" };

unsigned int StatsTypeRooms[10] = { 1, 2, 3, 1, 2, 3, 1, 1, 1, 1 };

void Room::setNumber(int Number) { 
	roomNumber = Number;
}

int Room::getNumber() { 
	return roomNumber;
}

void Room::setRandName(unsigned int index) {
	name = roomNames[index];
}

string Room::getName() { 
	return name;
}

void Room::toString() {
	cout << "Room: " << name << endl
		<< "# : " << roomNumber << endl;
}

void Room::setRandRoom() {
	size_t randRoom = (rand() % 10 + 1);
	setRandName(randRoom);
	StatChallengeType = StatsTypeRooms[randRoom];

}

bool Room::ChallengePlayerStat(Player* player) {
	unsigned int challengeNumber{ player->roll(roomNumber) };
	cout << "Player needs to roll: " << challengeNumber << " in " <<StatChallengeType<<endl;

	unsigned int PlayerRoll{ player->roll(player->getStat(StatChallengeType)) };
	cout << "Player rolled: " << PlayerRoll << " and ";

	if (PlayerRoll >= challengeNumber) {
		cout << "succeeded!" << endl;
		RewardPlayer(player);
		return true;
	}
	else {
		cout << "failed!" << endl;
		player->takeDamage(player->roll(roomNumber));
		return false;
	}
}

void Room::RewardPlayer(Player* player) {
	Item newItem;
	player->addToInventory(newItem);
}

Room& Room::operator++() {
	roomNumber++;
	setRandRoom();
	return *this;
}

bool Room::RoomAction(Player* player) {
	switch (ChallengeType) {
	case 1://stat challenge
		if (ChallengePlayerStat(player)) {
			RewardPlayer(player);
			return true;
		}
		break;
	
	

	}


}