#include "Stack.h"

Stack::Stack()
{
	AbsenceD = new vector<string>();
}

Stack::Stack(Stack& copy)
{
}

Stack::~Stack()
{
}

void Stack::push(string newDate)
{
	AbsenceD->push_back(newDate);
}

void Stack::pop()
{

	AbsenceD->pop_back();
}

string Stack::peek()
{
	if (!AbsenceD->empty())
	{
		return AbsenceD->back();
	}
	else
	{
		return " ";
	}

}

bool Stack::isEmpty()
{
	if (AbsenceD->empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Stack::size()
{
	return AbsenceD->size();
}

void Stack::FindTime(string date)
{
	if (find(AbsenceD->begin(), AbsenceD->end(), date) != AbsenceD->end())
	{
		AbsenceD->pop_back();
	}
}

