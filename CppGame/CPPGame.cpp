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
Item* useItemsByName(string target);

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
	if (name == "Link") {
		cout << "haye";
		// include code for extra 10 inventory slot
	}
	else if (name == "AJ") {
		cout << "yooo";
		// include some special stat
	}
	else if (name == "kandersson") {
		cout << "....";
		// include speed by 10
	}
	else if (name == "rbreez") {
		cout << "...";
		// include some special stat
	}
	else if (name == "Bineet") {
		cout << "need them A's";
		// include all by 10
	}
	else {
		cout << "";
	}

	cout << "Welcome Traveler" << endl;
	while (true) {//main
		string command{ "" };
		string target{""};
		cout << "Actions: " << endl
			<< "stats/s" << endl
			<< "room/r" << endl
			<< "item/i" << endl
			<< "exit/e" << endl
			<< "Type help/h to view what each command does" << endl;
		cout << "\nPlease enter a command (main): ";
		readInput(command, target);
		if ("help" == command || "h" == command){
			mainHelpList();
		}

		else if ("stats" == command || "s" == command) {
			cout<<player.toString();
		}

		else if ("room" == command || "r" == command) {
			roomMenu();
		}

		else if ("item" == command || "i" == command) {
			itemMenu();
		}

		else if ("exit" == command || "e" == command) {
			cout << "\nAre you sure? ";
			readInput(command, target);
			if ("no" == command) {
				continue;
			}
			else { break; }
		}
		else{
			cout << "\n\nunidentified keword \""<< command <<"\" has been inputted, please type \"help\" for a list of keywords";
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
		tar += input[i];
		i++;
	}
	//cout << "command is: "<< com;
	//cout << "\ntarget is: " << tar;
}

//helplist type funcitons
void mainHelpList() {
	cout << "\nhelp/h: shows all the possible keywords for main menu" << endl
		<< "stats/s: opens the stats menu for you character" << endl
		<< "room/r: opens the room menu" << endl
		<< "item/i: opens the item menu" << endl
		<< "exit/e: will prompt you to exit the game" << endl;
}
//menu type functions

void roomMenu() {
	while (true) {
		string command{ "" };
		string target{ "" };
		cout << "\nActions: " << endl
			<< "do/d" << endl
			<< "view/v" << endl
			<< "back/b" << endl
			<< "Type help/h to view what each command does" << endl;
		cout << "\nPlease enter a command (room): ";
		readInput(command, target);
		if ("help" == command) {
			cout << "\ndo/d: display possible action for the room" << endl
				<< "view/v: display the information of the room" << endl
				<< "back/b: go back to main menu" << endl;
		}

		else if ("do" == command || "d" == command) {
			if (theRoom.RoomAction(&player)) {
				++theRoom;
			}
		}
		else if ("view" == command || "v" == command) {
			theRoom.toString();
		}

		else if ("back" == command || "b"==command) {
			break;
		}
	}
}

void itemMenu() {

	while (true) {
		string command{ "" };
		string target{ "" };
		Item* tempPtr;
		cout << "\nActions: " << endl
			<< "view/v" << endl
			<< "use/u" << endl
			<< "back/b" << endl
			<< "Type help/h to view what each command does" << endl;
		cout << "\nPlease enter a command (item): ";
		readInput(command, target);
		if ("help" == command) {
			cout << "\nhelp: shows all the possible keywords for item menu" << endl
				<< "back: brings you back to the main menu" << endl;
		}
		else if ("view" == command || "v" == command && "" != target) {
			tempPtr = useItemsByName(target);
			if (tempPtr != nullptr) {
				cout << tempPtr->toString();
			}
		}
		else if ("view" == command || "v" == command) {
			player.showInventory();
		}

		else if ("use" == command || "u" == command && "" != target) {

			tempPtr = useItemsByName(target);
			if (tempPtr != nullptr) {
				player.equip(*tempPtr);
			}
		}
		else if ("use" == command || "u" == command) {
			cout << "What Item to use/equip?";
			player.showInventory();
			cout << endl<<endl;
			getline(cin, target);
			tempPtr = useItemsByName(target);
			if (tempPtr != nullptr) {
				player.equip(*tempPtr);
			}
		}

		else if ("back" == command || "b" == command) {
			break;
		}
	
	
	}

}

Item* useItemsByName(string target) {
	if (player.getItemBag()->GetItemByName(target).getName() == target) {
		return &player.getItemBag()->GetItemByName(target);
	}
	else {
		cout << "Name not found, try enetering the name again";
		return nullptr;
	}
}
