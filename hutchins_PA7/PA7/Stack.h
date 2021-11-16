#pragma once
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::find;

//The Stack class must support push (), pop (), peek (), and isEmpty () operations
class Stack
{
public:
	//c.contructor, contructor, deconstructor
	Stack();
	Stack(Stack& copy);
	~Stack();

	void push(string newDate);
	void pop();
	string peek();
	bool isEmpty();
	int size();//list the abscent student
	void FindTime(string date);
private:
	/*student absence date*/
	vector<string>* AbsenceD;

};
