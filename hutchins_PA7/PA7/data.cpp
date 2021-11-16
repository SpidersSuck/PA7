#include "Data.h"
// data field
Data::Data()
{
	this->Fresh_Email = "";
	this->Fresh_Name = "";
	this->Fresh_Id = 0;
	this->Fresh_Level = "";
	this->Fresh_Major = "";
	this->Fresh_Record = 0;
	this->Fresh_Units = "";
	this->Fresh_Total_Absence = 0;
	this->Fresh_Absence = new Stack();
}
//Copy Constructor
Data::Data(Data& copy)
{
	Fresh_Id = copy.Fresh_Id;
	Fresh_Record = copy.Fresh_Record;
	Fresh_Name = copy.Fresh_Name;
	Fresh_Email = copy.Fresh_Email;
	Fresh_Units = copy.Fresh_Units;
	Fresh_Major = copy.Fresh_Major;
	Fresh_Level = copy.Fresh_Level;
	Fresh_Total_Absence = copy.Fresh_Total_Absence;
	Fresh_Absence = copy.Fresh_Absence;

}
//deconstructor
Data::~Data()
{
}
// getter & setters
void Data::setRecord(int newRec)
{
	Fresh_Record = newRec;
}

void Data::setId(int newId)
{
	Fresh_Id = newId;
}

void Data::setName(string NewN)
{
	Fresh_Name = NewN;
}

void Data::setEmail(string newE)
{
	Fresh_Email = newE;
}

void Data::setUnits(string newU)
{
	Fresh_Units = newU;
}

void Data::setMajor(string newM)
{
	Fresh_Major = newM;
}

void Data::setLevel(string newL)
{
	Fresh_Level = newL;
}

void Data::setTotalAbs()
{
	Fresh_Total_Absence = Fresh_Absence->size();
}

void Data::setTotalAbs(int newA)
{
	Fresh_Total_Absence = newA;
}

void Data::setAbsence(string newAbs)
{
	Fresh_Absence->push(newAbs);
}

void Data::findAbs(string date)
{
	this->Fresh_Absence->FindTime(date);
}

int Data::getRecord()
{
	return Fresh_Record;
}

int Data::getId()
{
	return Fresh_Id;
}

string Data::getName()
{
	return Fresh_Name;
}

string Data::getEmail()
{
	return Fresh_Email;
}

string Data::getUnits()
{
	return Fresh_Units;
}

string Data::getMajor()
{
	return Fresh_Major;
}

string Data::getLevel()
{
	return Fresh_Level;

}

int Data::getTotalAbs()
{
	return this->Fresh_Total_Absence;
}

string Data::getAbsence()
{
	return Fresh_Absence->peek();
}
