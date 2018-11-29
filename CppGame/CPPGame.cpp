// CPPGame.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Enemy.h"
#include "Room.h"
#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

//dem function prototypes
void clearBuffer();
void itemMenu();
void roomMenu();
void mainHelpList();
void readInput(string& com, string& tar);

string JUNK;
Room theRoom;
Player player("name", 18, 2, 2, 2, "This is the player");

int main()
{
	srand((unsigned)time(0));


	cout << "Please Enter a name for your character: ";
	string name{""};
	getline(cin, name);
	player.setName(name);

	while (true) {//main
		string command{ "" };
		string target{""};

		cout << "\nPlease enter a command (main): ";
		readInput(command, target);
		if ("help" == command){
			mainHelpList();
		}

		else if ("stats" == command) {
			cout<<player.toString();
		}

		else if ("room" == command) {
			roomMenu();
		}

		else if ("item" == command) {
			itemMenu();
		}

		else if ("exit" == command) {
			cout << "\nAre you sure? ";
			readInput(command, target);
			if ("no" == command) {
				continue;
			}
			else { break; }
		}
		else{
			cout << "\n\nunidentified keword \""<<command<<"\" has been inputted, please type \"help\" for a list of keywords";
		}
	
	
	
	}

    return 0;
}
//input type functions
void clearBuffer() {
	getline(cin, JUNK);
}
void readInput(string& com, string& tar) {
	com="";
	tar="";
	string input;
	getline(cin,input);
	unsigned int i{ 0 };
	while (i < input.length()) {
		if (isspace(input[i])) {
			i++;
			break;
		}
		com += input[i];
		i++;
	}
	while (i < input.length()) {
		if (isspace(input[i])) {
			i++;
			break;
		}
		tar += input[i];
		i++;
	}
	//cout << "command is: "<< com;
	//cout << "\ntarget is: " << tar;
}

//helplist type funcitons
void mainHelpList() {
	cout << "\nhelp: shows all the possible keywords for main menu" << endl
		<< "stats: opens the stats menu for you character" << endl
		<< "room: opens the room menu" << endl
		<< "item: opens the item menu" << endl
		<< "exit: will prompt you to exit the game" << endl;
}
//menu type functions

void roomMenu() {
	while (true) {
		string command{ "" };
		string target{ "" };

		cout << "\nPlease enter a command (room): ";
		readInput(command, target);
		if ("help" == command) {}

		else if ("do" == command) {
			if (theRoom.RoomAction(&player)) {
				++theRoom;
			}
		}
		else if ("view" == command) {
			theRoom.toString();
		}

		else if ("back" == command || "exit"==command) {
			break;
		}
	}
}

void itemMenu() {

	while (true) {
		string command{ "" };
		string target{ "" };
		cout << "\nPlease enter a command (item): ";
		readInput(command, target);
		if ("help" == command) {
			cout << "\nhelp: shows all the possible keywords for item menu" << endl
				<< "back: brings you back to the main menu" << endl;
		}
		else if ("view" == command) {
			player.showInventory();
		}
		else if ("back" == command) {
			break;
		}
	
	
	}

}
