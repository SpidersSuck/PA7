#include "Menu.h"

//c.contructor, contructor, deconstructor
Menu::Menu()
{
	masterList = new List<Data>();
}
Menu::Menu(Menu& copy)
{
}
Menu::~Menu()
{
}

/*----------------------------------------------------------------------------run menu-------------------------------------------------------------------------------------------*/
void Menu::runMenu()
{
	int choice = 0;
	int subChoice = 0;

	while (choice != 7)
	{
		cout << ":::1. Import Course List\n ";
		cout << "::2. Load Master List\n ";
		cout << "::3. Store Master List\n ";
		cout << "::4. Print List To Console\n ";
		cout << "::5. Edit Absences(~bonus~)\n ";
		cout << "::6. Generate Report\n ";
		cout << "::7. Exit Program ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			importList();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			loadList();
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			storeList();
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			printList();
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			editAbsence();
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			cout << "1. Generate report for all students\n ";
			cout << "2. Generate report for matched input (e.g 1) ";
			cin >> subChoice;
			if (subChoice == 1)
			{
				system("cls");
				reportAll();
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				reportMarked();
				system("pause");
				system("cls");
				break;
			}
		}
	}
	cout << "Exiting Program..." << endl;
	system("pause");

}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------print list--------------------------------------------------------------------------------------------*/
void Menu::printList()
{
	Node<Data>* seek = masterList->getFront();

	while (seek != nullptr)
	{
		//stack overflow refrence
		cout << seek->getData()->getRecord() << "," << seek->getData()->getId() << "," << seek->getData()->getName() << "," << seek->getData()->getEmail() << "," <<
			seek->getData()->getUnits() << "," << seek->getData()->getMajor() << "," << seek->getData()->getLevel() << "[" << seek->getData()->getTotalAbs() << "," <<
			seek->getData()->getAbsence() << "]" << endl;	seek = seek->getNext();
	}
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------import List-----------------stack overflow refrence-----------------------------------------------------------------------------*/

void Menu::importList()
{
	string attendance = "";
	fstream infile;
	Data* temp;
	int j = 0;
	string line;
	string Com;
	string etc;
	string git = ", ";
	infile.open("classList.csv");
	int token = 0;

	if (infile.is_open() == true)
	{
		getline(infile, etc);
		while (!infile.eof())
		{
			/*                                               */
			temp = new Data();
			getline(infile, line, ',');
			temp->setRecord(stoi(line));
			getline(infile, line, ',');
			temp->setId(stoi(line));
			getline(infile, line, ',');
			getline(infile, Com, ',');
			line.append(git);
			line.append(Com);
			temp->setName(line);
			getline(infile, line, ',');
			temp->setEmail(line);
			getline(infile, line, ',');
			temp->setUnits(line);
			getline(infile, line, ',');
			temp->setMajor(line);
			getline(infile, line, '\n');
			temp->setLevel(line);
			attendance = markAbs(temp->getName());
			if (attendance != "Present")
			{
				temp->setAbsence(attendance);
				temp->setTotalAbs();
			}
			temp->setTotalAbs();
			masterList->insert(*temp);
		}
	}
	cout << "List Imported" << endl;
	infile.close();
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------Load List------------------------------------------------------------------------------------------------*/
void Menu::loadList()
{
	string attendance = "";
	fstream infile;
	string etc;
	Data* temp;
	int j = 0;
	string line;
	string Com;
	string git = ", ";
	infile.open("MasterList.txt");
	int token = 0;

	if (infile.is_open() == true)
	{
		while (!infile.eof())
		{
			getline(infile, line, ',');
			if (line.size() != 0)
			{
				temp = new Data();
				temp->setRecord(stoi(line));
				getline(infile, line, ',');
				temp->setId(stoi(line));
				getline(infile, line, ',');
				getline(infile, Com, ',');
				line.append(git);
				line.append(Com);
				temp->setName(line);
				getline(infile, line, ',');
				temp->setEmail(line);
				getline(infile, line, ',');
				temp->setUnits(line);
				getline(infile, line, ',');
				temp->setMajor(line);
				getline(infile, line, '[');
				temp->setLevel(line);
				getline(infile, line, ',');
				temp->setTotalAbs(stoi(line));
				getline(infile, line, ']');
				temp->setAbsence(line);
				getline(infile, line, '\n');
				masterList->insert(*temp);

			}


		}
	}
	cout << "List Loaded" << endl;
	infile.close();
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------Store List-------------------------------------------------------------------------------------------------*/
void Menu::storeList()
{
	Node<Data>* seek = masterList->getFront();
	fstream outfile;
	outfile.open("MasterList.txt", std::ofstream::out | std::ofstream::trunc);

	if (outfile.is_open())
	{
		while (seek != nullptr)
		{
			outfile << seek->getData()->getRecord() << "," <<
				seek->getData()->getId() << "," <<
				seek->getData()->getName() << "," <<
				seek->getData()->getEmail() << "," <<
				seek->getData()->getUnits() << "," <<
				seek->getData()->getMajor() << "," <<
				seek->getData()->getLevel() << "[" <<
				seek->getData()->getTotalAbs() << "," <<
				seek->getData()->getAbsence() << "]" << endl;
			seek = seek->getNext();
		}
	}
	cout << "List Stored" << endl;

	outfile.close();



}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------input absence----------------------------------------------------------------------------------------------------*/
string Menu::markAbs(string name)
{
	string choice = "";
	string Com = "-";
	string year = "";
	string day = "";
	string ed = "";
	string PresentTime = "";

	cout << "so was " << name << " absent today? yes or no (Y/N)" << endl;
	cin >> choice;
	// get time  help of overflow
	time_t t = time(0);
	struct tm* now = localtime(&t);
	year = to_string(now->tm_year + 1900);
	day = to_string(now->tm_mday);
	ed = to_string(now->tm_mon + 1);
	PresentTime.append(ed);
	PresentTime.append(Com);
	PresentTime.append(day);
	PresentTime.append(Com);
	PresentTime.append(year);
	if (choice == "y" || choice == "Y")
	{
		cout << name << " Marked absence for: " << PresentTime << endl;
		return PresentTime;
	}
	else
	{
		return "Present";
	}

}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------reportAll-------------------------------------------------------------------------------------------*/
void Menu::reportAll()
{
	Node<Data>* seek = masterList->getFront();
	fstream outfile;
	outfile.open("reportAll.txt", std::ofstream::out | std::ofstream::trunc);
	if (outfile.is_open())
	{
		while (seek != nullptr)
		{
			outfile << "Absence Report for: " << seek->getData()->getName() << endl;
			outfile << "Days Absent: " << seek->getData()->getTotalAbs() << endl << "Date of Absense: " << seek->getData()->getAbsence() << endl;
			outfile << "-------------------------------------------" << endl;
			seek = seek->getNext();
		}
	}
	outfile.close();

}

void Menu::reportMarked()
{
	int choice = 0;
	Node<Data>* seek = masterList->getFront();
	fstream outfile;
	outfile.open("reportMarked.txt", std::ofstream::out | std::ofstream::trunc);

	cout << "Total days absent: ";
	cin >> choice;

	if (outfile.is_open())
	{
		while (seek != nullptr)
		{
			if (seek->getData()->getTotalAbs() >= choice)
			{
				outfile << "Absence Report for: " << seek->getData()->getName() << endl;
				outfile << "Total Days Absent: " << seek->getData()->getTotalAbs() << endl << "Date of Absense: " << seek->getData()->getAbsence() << endl;
				outfile << "-------------------------------------------" << endl;
			}
			seek = seek->getNext();
		}
	}

	outfile.close();

}

void Menu::editAbsence()
{
	Node<Data>* seek = masterList->getFront();
	int id = 0;
	string date;
	cout << "Use Student Id to Search for Absense: ";
	cin >> id;


	while (seek != nullptr)
	{
		/*BONUS: Edit absences - The user of the program should be able to access each studentfs record and edit absences.
		A search (linear time) through the master list based on student ID or name must be supported. If a student was
		initially marked absent for a date, but later was determined to be present, then the absence should be removed from
		the record. This includes updating the number of absences field. Be sure to add an Edit option to your menu!  */
		if (seek->getData()->getId() == id);
		{
			cout << "Student: " << seek->getData()->getName() << endl;
			cout << "Enter exact date to edit: ";
			cin >> date;
			seek->getData()->findAbs(date);
			seek->getData()->setTotalAbs();
			cout << seek->getData()->getName() << " Is no longer marked Absent for" << date << endl;
			cout << "Total Days Absent: " << seek->getData()->getTotalAbs() << endl << "Date of Absence: " 
				 << seek->getData()->getAbsence() << endl;
			cout << "-------------------------------------------" << endl;
			break;
		}
		seek = seek->getNext();
	}
}