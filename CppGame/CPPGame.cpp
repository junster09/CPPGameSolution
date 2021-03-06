/// CPPGame.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Enemy.h"
#include "Room.h"
#include <iostream>
#include <iomanip>
#include <random>
#include <fstream>
using namespace std;

//dem function prototypes
void clearBuffer();
void itemMenu();
void roomMenu();
void optionsMenu();
void mainHelpList();
void readInput(string& com, string& tar);
Item* useItemsByName(string target);

string JUNK;
Room theRoom;
Player player("name", 18, 2, 2, 2, "This is the player");
string menuC;
string name; // for new players
string choice; 
string statRead; // V below are for save file reads
string indata;
string fileCheck;
string fname;
string fhp;
string fbrawn;
string fwit;
string fspeed; 
bool save1 = false;
bool save2 = false;
bool save3 = false; // ^

//temp
string currentSave = "player.txt";

// using file stream, write to file after  program closes
//fstream theFile("player.txt", ios::in | ios::out | ios::app);

int main()
{
	srand((unsigned)time(0));


	cout << "\n\n\tWelcome to Tower Climber V1.3" << endl;
	ifstream infile;
	infile.open("save1.txt");
	infile >> fileCheck;
	if (fileCheck != "") {
		save1 = true;
	}
	fileCheck = "";
	infile.close();
	infile.open("save2.txt");
	infile >> fileCheck;
	if (fileCheck != "") {
		save2 = true;
	}
	fileCheck = "";
	infile.close();
	infile.open("save3.txt");
	infile >> fileCheck;
	if (fileCheck != "") {
		save3 = true;
	}
	fileCheck = "";
	infile.close();
	while (currentSave != "save1.txt" || currentSave != "save2.txt" || currentSave != "save3.txt") {
		if (save1 == true || save2 == true || save3 == true) {
			cout << "\n\tYou have a save file, would you like to continue on any of them? (yes/no)";
			cin >> choice;
			if (choice == "yes" || choice == "y") {
				cout << "\n\tCurrent save files are: " << endl;
				if (save1 == true) {
					cout << "\t1.Save 1" << endl;
				}
				if (save2 == true) {
					cout << "\t2.Save 2" << endl;
				}
				if (save3 == true) {
					cout << "\t3.Save 3" << endl;
				}
				cout << "\n\tPlease type the save number your would like to use (1/2/3): ";
				cin >> currentSave;
				if (currentSave == "1") {
					infile.open("save1.txt");
					infile >> fileCheck;
					infile.close();
					if (fileCheck == "") {
						cout << "\n\tThis file doesn't have a save data, please choose another one" << endl;
					}
					else {
						infile.open("save1.txt");
						while (!infile.eof()) {
							infile >> indata;
							size_t a = indata.find("/") + 1;
							string statRead = indata.substr(a, indata.find(":") - a);
							if (statRead == "n") {
								size_t b = indata.find(":") + 1;
								fname = indata.substr(b, indata.find("") - b);
								player.setName(fname);
								cout << "\n\tWelcome back " << fname << endl;
							}
							else if (statRead == "h") {
								size_t b = indata.find(":") + 1;
								fhp = indata.substr(b, indata.find("") - b);
								unsigned int nhp = stoul(fhp);
								player.setHP(nhp);
							}
							else if (statRead == "b") {
								size_t b = indata.find(":") + 1;
								fbrawn = indata.substr(b, indata.find("") - b);
								unsigned int nbrawn = stoul(fbrawn);
								player.setStat(3, nbrawn);
							}
							else if (statRead == "w") {
								size_t b = indata.find(":") + 1;
								fwit = indata.substr(b, indata.find("") - b);
								unsigned int nwit = stoul(fwit);
								player.setStat(2, nwit);
							}
							else if (statRead == "s") {
								size_t b = indata.find(":") + 1;
								fspeed = indata.substr(b, indata.find("") - b);
								unsigned int nspeed = stoul(fspeed);
								player.setStat(1, nspeed);
							}
							else {
								cout << endl;
							}
						}
						infile.close();
						currentSave = "save1.txt";
						break;
					}
					fileCheck = "";
				}
				else if (currentSave == "2") {
					infile.open("save2.txt");
					infile >> fileCheck;
					infile.close();
					if (fileCheck == "") {
						cout << "\n\tThis file doesn't have a save data, please choose another one" << endl;
					}
					else {
						infile.open("save2.txt");
						while (!infile.eof()) {
							infile >> indata;
							size_t a = indata.find("/") + 1;
							string statRead = indata.substr(a, indata.find(":") - a);
							if (statRead == "n") {
								size_t b = indata.find(":") + 1;
								fname = indata.substr(b, indata.find("") - b);
								player.setName(fname);
								cout << "\n\tWelcome back " << fname << endl;
							}
							else if (statRead == "h") {
								size_t b = indata.find(":") + 1;
								fhp = indata.substr(b, indata.find("") - b);
								unsigned int nhp = stoul(fhp);
								player.setHP(nhp);
							}
							else if (statRead == "b") {
								size_t b = indata.find(":") + 1;
								fbrawn = indata.substr(b, indata.find("") - b);
								unsigned int nbrawn = stoul(fbrawn);
								player.setStat(3, nbrawn);
							}
							else if (statRead == "w") {
								size_t b = indata.find(":") + 1;
								fwit = indata.substr(b, indata.find("") - b);
								unsigned int nwit = stoul(fwit);
								player.setStat(2, nwit);
							}
							else if (statRead == "s") {
								size_t b = indata.find(":") + 1;
								fspeed = indata.substr(b, indata.find("") - b);
								unsigned int nspeed = stoul(fspeed);
								player.setStat(1, nspeed);
							}
							else {
								cout << endl;
							}
						}
						infile.close();
						currentSave = "save2.txt";
						break;
					}
					fileCheck = "";
				}
				else if (currentSave == "3") {
					infile.open("save3.txt");
					infile >> fileCheck;
					infile.close();
					if (fileCheck == "") {
						cout << "\n\tThis file doesn't have a save data, please choose another one" << endl;
					}
					else {
						infile.open("save3.txt");
						while (!infile.eof()) {
							infile >> indata;
							size_t a = indata.find("/") + 1;
							string statRead = indata.substr(a, indata.find(":") - a);
							if (statRead == "n") {
								size_t b = indata.find(":") + 1;
								fname = indata.substr(b, indata.find("") - b);
								player.setName(fname);
								cout << "\n\tWelcome back " << fname << endl;
							}
							else if (statRead == "h") {
								size_t b = indata.find(":") + 1;
								fhp = indata.substr(b, indata.find("") - b);
								unsigned int nhp = stoul(fhp);
								player.setHP(nhp);
							}
							else if (statRead == "b") {
								size_t b = indata.find(":") + 1;
								fbrawn = indata.substr(b, indata.find("") - b);
								unsigned int nbrawn = stoul(fbrawn);
								player.setStat(3, nbrawn);
							}
							else if (statRead == "w") {
								size_t b = indata.find(":") + 1;
								fwit = indata.substr(b, indata.find("") - b);
								unsigned int nwit = stoul(fwit);
								player.setStat(2, nwit);
							}
							else if (statRead == "s") {
								size_t b = indata.find(":") + 1;
								fspeed = indata.substr(b, indata.find("") - b);
								unsigned int nspeed = stoul(fspeed);
								player.setStat(1, nspeed);
							}
							else {
								cout << endl;
							}
						}
						infile.close();
						currentSave = "save3.txt";
						break;
					}
					fileCheck = "";
				}
			}
			else if (choice == "no" || choice == "n") {
				cout << "\n\tNo save file picked, starting a new game" << endl;
				cout << "\n\tPlease Enter a name for your character: ";
				cin >> name;
				player.setName(name);
				if (name == "Link") {
					cout << "\n\thaye";
					// include code for extra 10 inventory slot
				}
				else if (name == "AJ") {
					cout << "\n\tyooo";
					// include some special stat
				}
				else if (name == "kandersson") {
					cout << "\n\t....";
					// include speed by 10
				}
				else if (name == "rbreez") {
					cout << "\n\t...";
					// include some special stat
				}
				else if (name == "Bineet") {
					cout << "\n\tneed them A's";
					// include all by 10
				}
				else {
					cout << "\n\tYour name is " << name << endl;
				}
				currentSave = "save1.txt";
				break;
			}
			else {
				cout << "\n\tThat's not a choice, please enter a valid answer" << endl;
			}
			choice = "";

		}
		else {
			cout << "\n\tPlease Enter a name for your character: ";
			getline(cin, name);
			player.setName(name);
			if (name == "Link") {
				cout << "haye" << endl;
				// include code for extra 10 inventory slot
			}
			else if (name == "AJ") {
				cout << "yooo" << endl;
				// include some special stat
			}
			else if (name == "kandersson") {
				cout << "...." << endl;
				// include speed by 10
			}
			else if (name == "rbreez") {
				cout << "..." << endl;
				// include some special stat
			}
			else if (name == "Bineet") {
				cout << "need them A's" << endl;
				// include all by 10
			}
			else {
				cout << "\n\t your name is " << name << endl;
			}
			break;
		}
	}
	
	while (true) {//main
		string command{ "" };
		string target{ "" };
		cout << "\n\t*********************************************" << endl
			<< "\n\tActions: " << endl
			<< "\tstats/s" << endl
			<< "\troom/r" << endl
			<< "\titem/i" << endl
			<< "\toptions/o" << endl
			<< "\texit/e" << endl
			<< "\tType help/h to view what each command does" << endl
			<< "\n\t*********************************************" << endl;
		cout << "\n\tPlease enter a command (main): ";
		getline(cin, command);

		if ("help" == command || "h" == command) {
			mainHelpList();
		}
		else if ("stats" == command || "s" == command) {
			cout << player.toString();
		}
		else if ("room" == command || "r" == command) {
			roomMenu();
		}
		else if ("item" == command || "i" == command) {
			itemMenu();
		}
		else if ("options" == command || "o" == command) {
			optionsMenu();
		}
		else if ("exit" == command || "e" == command) {
			cout << "\n\tAre you sure? (yes/no)";
			readInput(command, target);
			if ("no" == command || "n" == command) {
				continue;
			}
			else { break; }
		}
		else {
			cout << "\n\n\tunidentified keword \"" << command << "\" has been inputted, please type \"help\" for a list of keywords";
		}


	}

	ofstream outfile;
	if (currentSave == "save1.txt") {
		infile.open("save1.txt");
		infile >> fileCheck;
		if (fileCheck != "") {
			currentSave = "save2.txt";
		}
		else {
			//saving to file 1
			outfile.open("save1.txt");
			outfile << "/n:" << player.getName() << endl;
			outfile << "/h:" << player.getHP() << endl;
			outfile << "/b:" << player.getStat(3) << endl;
			outfile << "/w:" << player.getStat(2) << endl;
			outfile << "/s:" << player.getStat(1) << endl;
			outfile.close();
		}
		fileCheck = "";
		infile.close();
	}
	else if (currentSave == "save2.txt") {
		infile.open("save2.txt");
		infile >> fileCheck;
		if (fileCheck != "") {
			currentSave = "save3.txt";
		}
		else {
			//saving to file 2
			outfile.open("save2.txt");
			outfile << "/n:" << player.getName() << endl;
			outfile << "/h:" << player.getHP() << endl;
			outfile << "/b:" << player.getStat(3) << endl;
			outfile << "/w:" << player.getStat(2) << endl;
			outfile << "/s:" << player.getStat(1) << endl;
			outfile.close();
		}
		fileCheck = "";
		infile.close();
	}
	else if (currentSave == "save3.txt") {
		infile.open("save3.txt");
		infile >> fileCheck;
		if (fileCheck != "") {
			cout << "\n\tThere is no more save files avaliable, would you like to" << endl
				<< "\tsave to Save 3 or delete the current progress? (save/delete)";
			cin >> choice;
			if (choice == "save" || choice == "s") {
				outfile.open("save3.txt");
				outfile << "/n:" << player.getName() << endl;
				outfile << "/h:" << player.getHP() << endl;
				outfile << "/b:" << player.getStat(3) << endl;
				outfile << "/w:" << player.getStat(2) << endl;
				outfile << "/s:" << player.getStat(1) << endl;
				outfile.close();
			} 
			else if (choice == "delete" || choice == "d") {
				cout << "\n\tProgress deleted" << endl;
			}
			choice = "";
		}
		else {
			//saving to file 3
			outfile.open("save3.txt");
			outfile << "/n:" << player.getName() << endl;
			outfile << "/h:" << player.getHP() << endl;
			outfile << "/b:" << player.getStat(3) << endl;
			outfile << "/w:" << player.getStat(2) << endl;
			outfile << "/s:" << player.getStat(1) << endl;
			outfile.close();
		}
		fileCheck = "";
		infile.close();
	}

	cout << "\n\n\tThank you for playing" << endl
		<< "\t";
	//return 0;
}
//input type functions
void clearBuffer() {
	getline(cin, JUNK);
}

void readInput(string& com, string& tar) {
	com = "";
	tar = "";
	string input;
	getline(cin, input);
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
	cout << "\n\t*********************************************" << endl
		<< "\n\thelp/h: shows all the possible keywords for main menu" << endl
		<< "\tstats/s: opens the stats menu for you character" << endl
		<< "\troom/r: opens the room menu" << endl
		<< "\titem/i: opens the item menu" << endl
		<< "\texit/e: will prompt you to exit the game" << endl
		<< "\n\t*********************************************" << endl;
}
//menu type functions

void roomMenu() {
	while (true) {
		string command{ "" };
		string target{ "" };
		cout << "\n\t*********************************************" << endl
			<< "\n\tActions: " << endl
			<< "\tdo/d" << endl
			<< "\tview/v" << endl
			<< "\titem/i" << endl
			<< "\tback/b" << endl
			<< "\tType help/h to view what each command does" << endl
			<< "\n\t*********************************************" << endl;
		cout << "\n\tPlease enter a command (room): ";
		readInput(command, target);
		if ("help" == command || "h" == command) {
			cout << "\ndo/d: do the possible action for the room" << endl
				<< "view/v: display the information of the room" << endl
				<< "item/i: go to item menu" << endl
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
		else if ("item" == command || "i" == command) {
			itemMenu();
		}
		else if ("back" == command || "b" == command) {
			break;
		}
	}
}

void itemMenu() {

	while (true) {
		string command{ "" };
		string target{ "" };
		Item* tempPtr;
		cout << "\n\t*********************************************" << endl
			<< "\n\tActions: " << endl
			<< "\tview/v" << endl
			<< "\tuse/u" << endl
			<< "\troom/r" << endl
			<< "\tback/b" << endl
			<< "\tType help/h to view what each command does" << endl
			<< "\n\t*********************************************" << endl;
		cout << "\n\tPlease enter a command (item): ";
		readInput(command, target);
		if ("help" == command || "h" == command) {
			cout << "\n\tview: view the gears in your inventory" << endl
				<< "\tuse: equip an item" << endl
				<< "\troom: go to room menu" << endl
				<< "\tback: brings you back to the main menu" << endl;
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
			cout << "\n\tWhat Item to use/equip?";
			player.showInventory();
			cout << endl << endl;
			getline(cin, target);
			tempPtr = useItemsByName(target);
			if (tempPtr != nullptr) {
				player.equip(*tempPtr);
			}
		}
		else if ("room" == command || "r" == command) {
			roomMenu();
		}
		else if ("back" == command || "b" == command) {
			break;
		}


	}

}

void optionsMenu() {
	while (true) {
		string command{ "" };
		string target{ "" };
		cout << "\n\t*********************************************" << endl
			<< "\n\tActions: " << endl
			<< "\tname/n" << endl
			<< "\treset/r" << endl
			<< "\tcredits/c" << endl
			<< "\tback/b" << endl
			<< "\tType help/h to view what each command does" << endl
			<< "\n\t*********************************************" << endl;
		cout << "\n\tPlease enter a command (options): ";
		readInput(command, target);
		if ("help" == command || "h" == command) {
			cout << "\ndo/d: display possible action for the room" << endl
				<< "view/v: display the information of the room" << endl
				<< "back/b: go back to main menu" << endl;
		}
		else if ("name" == command || "n" == command) {
			cout << "\tWould you like to change your name? (yes/no) ";
			cin >> choice;
			if (choice == "yes" || choice == "y") {
				cout << "\n\tWhat would you like to change it to? ";
				cin >> name;
				player.setName(name);
				//write to file;
				cout << "\n\tYou changed your name to " << name << endl;
			}
			else if (choice == "no" || choice == "n") {
				cout << "\tNo worries, your name is still " << name << endl;
			}
			else {
				cout << "\tNot a choice, please try again" << endl;
			}
			choice = "";
		}
		else if ("reset" == command || "r" == command) {
			cout << "\tDo you want to reset all your file data? (yes/no) ";
			cin >> choice;
			if (choice == "yes" || choice == "y") {
				ofstream outfile;
				outfile.open("save1.txt");
				outfile << "" << endl;
				outfile.open("save2.txt");
				outfile << "" << endl;
				outfile.open("save3.txt");
				outfile << "" << endl;
				cout << "\tAll your file has been resetted" << endl;
			}
			else if (choice == "no" || choice == "n") {
				cout << "\tNo worries, your game is still here" << endl;
			}
			else {
				cout << "\tNot a choice, please try again" << endl;
			}
			choice = "";
		}
		else if ("credit" == command || "c" == command) {
			cout << "\n\tDon't worry about the STARDUST that made this game, they all already went to a quiet place" << endl;
		}
		else if ("back" == command || "b" == command) {
			break;
		}
	}
}

Item* useItemsByName(string target) {
	if (player.getItemBag()->isEmpty()) {
		cout << "\n\tInventory is currently empty";
		return nullptr;
	}
	else if (player.getItemBag()->GetItemByName(target) == nullptr) {
		return nullptr;
	}
	else {
		return player.getItemBag()->GetItemByName(target);
	}
}
