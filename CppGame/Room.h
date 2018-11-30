#ifndef ROOM_H
#define ROOM_H
#include "Player.h"

class Room {
public:
	Room() {
		setRandRoom();
		setNumber(1); 
	}

	void setNumber(int Number);

	int getNumber();

	void setRandName(unsigned int);

	string getName();

	void setRandRoom();

	Room& operator++();

	void toString();

	bool ChallengePlayerStat(Player*);

	void RewardPlayer(Player*);

	bool RoomAction(Player*);

private:
	string name;
	int roomNumber;
	unsigned int ChallengeType{ 1 };
	unsigned int StatChallengeType{ 0 };
};
#endif ROOM_H

