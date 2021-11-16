
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"
using std::fstream;
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::stoi;
// data class
class Data
{
private:
	int Fresh_Record;
	int Fresh_Id;
	int Fresh_Total_Absence;
	string Fresh_Name;
	string Fresh_Email;
	string Fresh_Units;
	string Fresh_Major;
	string Fresh_Level;
	Stack* Fresh_Absence;
public:
	//c.contructor, contructor, deconstructor
	Data();
	Data(Data& copy);
	~Data();
	//setters & getter
	void setRecord(int newRec);
	void setId(int newId);
	void setName(string NewN);
	void setEmail(string newE);
	void setUnits(string newU);
	void setMajor(string newM);
	void setLevel(string newL);
	void setTotalAbs();
	void setTotalAbs(int newA);
	void setAbsence(string newAbs);
	void findAbs(string date);
	int getRecord();
	int getId();
	string getName();
	string getEmail();
	string getUnits();
	string getMajor();
	string getLevel();
	int getTotalAbs();
	string getAbsence();

};