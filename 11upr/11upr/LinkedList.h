#pragma once
#include <iostream>
using namespace std;


template <typename T>
struct LinkedNode {
	T data;
	LinkedNode<T>* next;
};

template <typename T>
class LinkedList {
private:
	LinkedNode<T>* start;
	LinkedNode<T>* end;
	LinkedNode<T>* current;

	void copyList(LinkedList<T> const &);
	void deleteList();
public:
	LinkedList();
	LinkedList(LinkedList<T> const &);
	LinkedList<T>& operator=(LinkedList<T> const &);
	bool operator==(LinkedList<T>&);
	~LinkedList();

	T getData();

	void iterStart(LinkedNode<T>* = NULL);
	LinkedNode<T>* iter();

	void insertToEnd(T const &);
	void insertAfter(LinkedNode<T>*, T const &);
	void insertBefore(LinkedNode<T>*, T const &);

	bool deleteElem(LinkedNode<T>*, T &);
	bool deleteBefore(LinkedNode<T>*, T&);
	bool deleteAfter(LinkedNode<T>*, T&);

	bool empty() const;
	void print() const;
	int length() const;
	int lengthIter();


};

template<typename T>
void LinkedList<T>::copyList(LinkedList<T> const & list)
{
	start = end = NULL;
	if (list.start) {
		LinkedNode<T>* elemPtr = list.start;
		while (elemPtr) {
			insertToEnd(elemPtr->data);
			elemPtr = elemPtr->next;
		}
	}
}

template<typename T>
void LinkedList<T>::deleteList()
{
	LinkedNode<T>* delElemPtr;
	while (start) {
		delElemPtr = start;
		start = start->next;
		delete delElemPtr;
	}
	end = NULL;
}

template <typename T>
LinkedList<T>::LinkedList() { start = NULL; end = NULL; }

template<typename T>
LinkedList<T>::LinkedList(LinkedList<T> const & list)
{
	copyList(list);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> const & list)
{
	if (this != &list) {
		deleteList();
		copyList(list);
	}return *this;
}

template<typename T>
bool LinkedList<T>::operator==(LinkedList<T>& list)
{
	return  length() == list.length();
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	deleteList();
}

template<typename T>
T LinkedList<T>::getData()
{
	return data;
}

template<typename T>
void LinkedList<T>::iterStart(LinkedNode<T>* elemPtr)
{
	if (elemPtr) {
		current = elemPtr;
	}
	else { current = start; }
}

template<typename T>
LinkedNode<T>* LinkedList<T>::iter()
{
	LinkedNode<T>* temp = current;
	if (current) {
		current = current->next;
	}
	return temp;
}

template<typename T>
void LinkedList<T>::insertToEnd(T const & elem)
{
	LinkedNode<T>* newElemPtr = new LinkedNode<T>;
	newElemPtr->data = elem;
	newElemPtr->next = NULL;
	if (end) { end->next = newElemPtr; }
	else { start = newElemPtr; }
	end = newElemPtr;
}

template<typename T>
void LinkedList<T>::insertAfter(LinkedNode<T>* elemPtr, T const & elem)
{
	if (!elemPtr) { cerr << "Invalid pointer\n"; return; }
	LinkedNode<T>* newElemPtr = new LinkedNode<T>;
	newElemPtr->data = elem;
	newElemPtr->next = elemPtr->next;
	if (end == elemPtr) { end = newElemPtr; }
	elemPtr->next = newElemPtr;

}

template<typename T>
void LinkedList<T>::insertBefore(LinkedNode<T>* elemPtr, T const & elem)
{
	if (!elemPtr) { cerr << "Invalid pointer!\n"; }

	if (elemPtr == start) {
		LinkedNode<T>* newElemPtr = new LinkedNode<T>;
		newElemPtr->data = elem;
		newElemPtr->next = elemPtr;;
		start = newElemPtr;
		return;
	}
	LinkedNode<T>* prevElemPtr = start;
	while (prevElemPtr->next != elemPtr) {
		prevElemPtr = prevElemPtr->next;
	}
	insertAfter(prevElemPtr, elem);
}

template<typename T>
bool LinkedList<T>::deleteElem(LinkedNode<T>* delElemPtr, T & elem)
{
	if (!delElemPtr || !delElemPtr->next) {
		cerr << "Invalid pointer!\n"; return false;
	}
	if (delElemPtr == start) {
		elem = delElemPtr->data;
		if (start == end) {
			start = end = NULL;
		}
		else { start = start->next; }
		delete delElemPtr;
	}

	else {
		LinkedNode<T>* prevElemPtr = start;
		while (prevElemPtr->next != delElemPtr) {
			prevElemPtr = prevElemPtr->next;
		}
		deleteAfter(prevElemPtr, elem);

	}
	return true;
}

template<typename T>
bool LinkedList<T>::deleteBefore(LinkedNode<T>* elemPtr, T & elem)
{
	if (!elemPtr || elemPtr == start) {
		cerr << "Invalid pointer!\n"; return false;
	}
	LinkedNode<T>* prevElemPtr = start;
	while (prevElemPtr->next != elemPtr) {
		prevElemPtr = prevElemPtr->next;
	}
	deleteElem(prevElemPtr, elem);

	return true;
}

template<typename T>
bool LinkedList<T>::deleteAfter(LinkedNode<T>* elemPtr, T & elem)
{
	if (!elemPtr || !elemPtr->next) { cerr << "Invalid pointer!\n"; return false; }
	LinkedNode<T>* delElemPtr = elemPtr->next;
	elem = delElemPtr->data;
	elemPtr->next = delElemPtr->next;
	if (delElemPtr == end) { end = elemPtr; }
	delete delElemPtr;
	return true;
}

template<typename T>
bool LinkedList<T>::empty() const
{
	return start == NULL;
}

template<typename T>
void LinkedList<T>::print() const
{
	LinkedNode<T>* elemPtr = start;
	while (elemPtr) {
		cout << elemPtr->data << " ";
		elemPtr = elemPtr->next;
	}
	cout << endl;
}

template<typename T>
int LinkedList<T>::length() const
{
	LinkedNode<T>* elemPtr = start;
	int n = 0;
	while (elemPtr) {
		n++;
		elemPtr = elemPtr->next;
	}
	return n;
}

template<typename T>
int LinkedList<T>::lengthIter()
{
	iterStart();
	LinkedNode<T>* elemPtr = iter();
	int n = 0;
	while (elemPtr) {
		n++;
		elemPtr = iter();
	}
	return n;
}
