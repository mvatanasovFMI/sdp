#ifndef _LINKED_STACK_H_
#define _LINKED_STACK_H_

#include "stack.h"
#include <iostream>

using namespace std;

template <typename T>
struct StackNode
{
	T data;
	StackNode<T>* next;
};

template <typename T>
class LinkedStack : public Stack<T>
{
private:
	StackNode<T> *front;
	void copyLinkedStack(const LinkedStack&);
	void deleteLinkedStack();
public:
	LinkedStack();
	LinkedStack(const LinkedStack&);
	LinkedStack<T>& operator=(const LinkedStack&);
	~LinkedStack();

	bool isEmpty() const;
	T& top();
	void push(const T &);
	bool pop(T&);
	void print();

	bool operator==(const LinkedStack &);

	friend istream& operator>>(istream &, LinkedStack<T> &);
	friend ostream& operator<<(ostream &, LinkedStack<T> &);

	friend ifstream operator>>(ifstream &, LinkedStack<T> &);
	friend ofstream operator<<(ofstream &, LinkedStack<T> &);
};


template<typename T>
void LinkedStack<T>::copyLinkedStack(const LinkedStack & other)
{
	if (&other != nullptr)
	{
		front = new StackNode<T>;
		front->data = other.front->data;
		front->next = nullptr;
		StackNode<T>* currOther = other.front->next;
		StackNode<T>* curr = front;
		while (currOther)
		{
			front->next = new StackNode<T>;
			front->next->data = currOther->data;
			front->next->next = nullptr;
			front = front->next;
			currOther = currOther->next;
		}
		front = curr;
		return;
	}
	front = nullptr;
}

template<typename T>
void LinkedStack<T>::deleteLinkedStack()
{
	StackNode<T>* ptr;
	while (front)
	{
		ptr = front;
		front = front->next;
		delete ptr;
	}
}

template<typename T>
LinkedStack<T>::LinkedStack() : front(nullptr)
{
}

template<typename T>
LinkedStack<T>::LinkedStack(const LinkedStack & other)
{
	copyLinkedStack(other);
}

template<typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack & other)
{
	if (&other != this)
	{
		deleteLinkedStack();
		copyLinkedStack(other);
	}
}

template<typename T>
LinkedStack<T>::~LinkedStack()
{
	deleteLinkedStack();
}

template<typename T>
bool LinkedStack<T>::isEmpty() const
{
	return front == nullptr;
}

template<typename T>
T & LinkedStack<T>::top()
{
	if (!isEmpty())
	{
		return front->data;
	}
	//return T();
}

template<typename T>
void LinkedStack<T>::push(const T & elem)
{
	StackNode<T>* newPtr = new StackNode<T>;
	newPtr->data = elem;
	newPtr->next = nullptr;
	if (!front)
	{
		front = newPtr;
		return;
	}
	newPtr->next = front;
	front = newPtr;
}

template<typename T>
bool LinkedStack<T>::pop(T & elem)
{
	if (isEmpty())
	{
		return false;
	}
	StackNode<T>* temp = front;
	elem = temp->data;
	front = front->next;
	delete temp;
	return true;
}

template<typename T>
void LinkedStack<T>::print()
{
	StackNode<T>* ptr = front;
	while (ptr)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

template<typename T>
bool LinkedStack<T>::operator==(const LinkedStack & other)
{
	StackNode<T>* first = front;
	StackNode<T>* second = other.front;
	while (first && second)
	{
		if (first->data != second->data)
		{
			return false;
		}
		first = first->next;
		second = second->next;
	}
	return (!first && !second);
}

template <typename T>
istream& operator>>(istream & is, LinkedStack<T> & st)
{
	int numberElements;
	is >> numberElements;
	T elem;
	for (int i = 0; i < numberElements; i++)
	{
		is >> elem;
		st.push(elem);
	}
	return is;
}

template <typename T>
ostream& operator<<(ostream & os, LinkedStack<T> & st)
{
	StackNode<T>* ptr = st.front;
	while (ptr)
	{
		os << ptr->data << " ";
		ptr = ptr->next;
	}
	os << endl;
	return os;
}

template <typename T>
ifstream operator>>(ifstream & ifs, LinkedStack<T> & st)
{
	T elem;
	while (ifs >> elem)
	{
		st.push(elem);
	}
	return ifs;
}

template <typename T>
ofstream operator<<(ofstream & ofs, LinkedStack<T> & st)
{
	StackNode<T>* ptr = st.front;
	while (ptr)
	{
		ofs << ptr->data << " ";
		ptr = ptr->next;
	}
	ofs << endl;
	return ofs;
}

#endif // !_LINKED_STACK_H_