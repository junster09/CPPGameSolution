// in use with CPPGame.cpp
#include <iostream>
#include <string>
#include <fstream>
#include "stdafx.h"
#include "Save.h"

using namespace std;

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
ifstream infile;

Save::Save() {};

void Save::checkSave(string fileName) {
	infile.open(fileName);
	infile >> fileCheck;
	cout << fileCheck;
	if (fileCheck != "") {
		cout << "You a save data 1" << endl;
		save1 = true;
	}

}
void Save::writeSave(string fileName) {
	infile.open(fileName);
	infile >> fileCheck;
	cout << fileCheck;
	if (fileCheck != "") {
		cout << "You a save data 1" << endl;
		save1 = true;
	}

}