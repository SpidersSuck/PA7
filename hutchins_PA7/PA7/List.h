#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
using std::fstream;
using std::cout;
using std::cin;


template <class T>
class List
{
public:
	List();
	List(List<T>& copy);
	~List();
	void setFront(Node<T>* pFront);
	void setBack(Node<T>* pBack);
	Node<T>* getFront();
	Node<T>* getBack();
	void insert(T newInput);

private:
	Node<T>* Front;
	Node<T>* Back;

};

template <class T>
List<T>::List()
{
	this->Front = nullptr;
	this->Back = nullptr;
}
template <class T>
List<T>::List(List<T>& copy)
{
	Front = copy.Front;
}
template <class T>
List<T>::~List()
{
	delete this->Front;
}

template<class T>
void List<T>::setFront(Node<T>* pFront)
{
	Front = pFront;
}

template<class T>
Node<T>* List<T>::getFront()
{
	return Front;
}

template<class T>
void List<T>::setBack(Node<T>* pBack)
{
	Back = pBack;
}

template<class T>
Node<T>* List<T>::getBack()
{
	return Back;
}

template <class T>
void List<T>::insert(T newInput)
{
	//if empty
	if (Front == nullptr)
	{
		Node<T>* pNew = new Node<T>();
		pNew->setData(newInput);
		setBack(pNew);
		setFront(pNew);

	}
	//if not empty
	else
	{

		Node<T>* seek = new Node<T>();
		Back->setNext(seek);
		seek->setData(newInput);
		Back = seek;



	}
}


