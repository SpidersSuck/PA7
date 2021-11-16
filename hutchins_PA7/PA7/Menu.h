
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Data.h"
#include "List.h"
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
using std::fstream;
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::stoi;
using std::to_string;

//class menu
class Menu
{
public:
	//c.contructor, contructor, deconstructor
	Menu();
	Menu(Menu& copy);
	~Menu();
	// Menu
	void runMenu();
	void printList();
	void loadList();
	void importList();
	void storeList();
	void reportAll();
	void reportMarked();
	void editAbsence();//bonus
	string markAbs(string name);
private:
	List<Data>* masterList; // all student list
};

