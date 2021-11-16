#pragma once
#include "Data.h"
#include <iostream>
#include <fstream>

template <class T>
class Node
{
public:
	//c.contructor, contructor, deconstructor
	Node();
	Node(Node<T>& copy);
	~Node();

	//setters & get
	void setData(T newInput);
	void setNext(Node<T>* pNext);
	T* getData();
	Node<T>* getNext();

private:
	T AllData;//Holds all data
	Node<T>* newNext;
};
template<class T>
Node<T>::Node()
{
	this->newNext = nullptr;
}
template<class T>
Node<T>::Node(Node<T>& copy)
{
	AllData = copy.AllData;
	newNext = copy.newNext;
}
template<class T>
Node<T>::~Node()
{
	delete this->AllData;
	delete this->newNext;
}
template <class T>
void Node<T>::setData(T newInput)
{
	AllData = newInput;
}
template <class T>
void Node<T>::setNext(Node<T>* pNext)
{
	newNext = pNext;
}
template <class T>
T* Node<T>::getData()
{
	return &AllData;
}
template <class T>
Node<T>* Node<T>::getNext()
{
	return this->newNext;
}