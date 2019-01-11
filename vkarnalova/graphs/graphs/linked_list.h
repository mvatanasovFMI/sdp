#ifndef GRAPHS_GRAPHS_LINKED_LIST_H_
#define  GRAPHS_GRAPHS_LINKED_LIST_H_

#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
struct ListElement {
	T data;
	ListElement<T>* next;
};

template <typename T>
class LList {
private:
	ListElement<T>* start;
	ListElement<T>* end;
	ListElement<T>* current;
	virtual void deleteList();
	virtual void copyList(const LList<T>&);
public:
	LList();
	LList(const LList<T>&);
	LList& operator=(const LList<T>&);
	virtual ~LList();

	virtual void iterStart(ListElement<T>* elemPtr = NULL);
	virtual ListElement<T>* iter();

	virtual void insertToEnd(T const &);
	void insertAfter(ListElement<T>*, const T&);
	void insertBefore(ListElement<T>*, const T&);

	virtual bool deleteAfter(ListElement<T>*, T&);
	bool deleteBefore(ListElement<T>*, T&);
	bool deleteElem(ListElement<T>*, T&);

	virtual void print();
	virtual int length();

	//overloaded operators
	//all of them have definitions in the header file
	bool operator==(LList<T>&);

	friend istream& operator>><T>(istream&, LList<T>&);
	friend ostream& operator<<<T>(ostream&, LList<T>&);

	friend ifstream& operator>><T>(ifstream&, LList<T>&);
	friend ofstream& operator<<<T>(ofstream&, LList<T>&);

};

template<typename T>
void LList<T>::deleteList()
{
	ListElement<T>* elemPtr;
	while (start) {
		elemPtr = start;
		start = start->next;
		delete elemPtr;
	}
	end = NULL;
}

template<typename T>
void LList<T>::copyList(const LList<T>& rhs_llist)
{
	start = end = NULL;
	if (rhs_llist.start) {
		ListElement<T>* elemPtr = rhs_llist.start;
		while (elemPtr) {
			insertToEnd(elemPtr->data);
			elemPtr = elemPtr->next;
		}
	}
}

template<typename T>
LList<T>::LList()
{
	start = NULL;
	end = NULL;
}

template<typename T>
LList<T>::LList(const LList<T>& rhs_llist)
{
	copyList(rhs_llist);
}

template<typename T>
LList<T>& LList<T>::operator=(const LList<T>& rhs_llist)
{
	if (this != &rhs_llist) {
		deleteList();
		copyList(rhs_llist);
	}

	return *this;
}

template<typename T>
LList<T>::~LList()
{
	deleteList();
}

template<typename T>
void LList<T>::iterStart(ListElement<T>* elemPtr)
{
	if (elemPtr) {
		current = elemPtr;
	}
	else {
		current = start;
	}
}

template<typename T>
ListElement<T>* LList<T>::iter()
{
	ListElement<T>* elemPtr = current;
	if (current) {
		current = current->next;
	}
	return elemPtr;
}

template<typename T>
void LList<T>::insertToEnd(T const & inf)
{
	ListElement<T>* new_elem = new ListElement<T>;
	assert(new_elem != NULL);
	new_elem->data = inf;
	new_elem->next = NULL;
	if (end) {
		end->next = new_elem;
	}
	else {
		start = new_elem;
	}
	end = new_elem;
}

template<typename T>
void LList<T>::insertAfter(ListElement<T>* elemPtr, const T & x)
{
	if (!elemPtr) { cerr << "Error, incorrect position"; } //proverka dali elemPtr !=NULL;
	ListElement<T>* newElemPtr = new ListElement<T>;
	assert(newElemPtr != NULL);
	newElemPtr->data = x;
	newElemPtr->next = elemPtr->next;
	if (elemPtr == end) {
		end = newElemPtr;
	}
	elemPtr->next = newElemPtr;
}

template<typename T>
void LList<T>::insertBefore(ListElement<T>* elemPtr, const T & x)
{
	if (!elemPtr) {
		cerr << "Incorrect position";
	}
	if (elemPtr == start) {
		ListElement<T>* newElem = new ListElement<T>;
		assert(newElem != NULL);
		newElem->data = x;
		newElem->next = start;
		start = newElem;
		return;
	}

	ListElement<T>* prevElemPtr = start;
	while (prevElemPtr->next != elemPtr) {
		prevElemPtr = prevElemPtr->next;
	}
	insertAfter(prevElemPtr, x);
}

template<typename T>
bool LList<T>::deleteAfter(ListElement<T>* elemPtr, T & x)
{
	if (!elemPtr || !elemPtr->next) {
		cerr << "Error, incorrect position";
		return false;
	}
	ListElement<T>* delElemPtr = elemPtr->next;
	x = delElemPtr->data;
	elemPtr->next = delElemPtr->next;
	if (delElemPtr == end) {
		end = elemPtr;
	}
	delete delElemPtr;
	return true;
}

template<typename T>
bool LList<T>::deleteBefore(ListElement<T>* elemPtr, T & x)
{
	if (!elemPtr || elemPtr == start) {
		cerr << "Incorrect position";
		return false;
	}
	ListElement<T>* prevElemPtr = start;
	while (prevElemPtr->next != elemPtr) {
		prevElemPtr = prevElemPtr->next;
	}
	deleteElem(prevElemPtr, x);
	return true;
}

template<typename T>
bool LList<T>::deleteElem(ListElement<T>* elemPtr, T & x)
{
	if (!elemPtr) {
		cerr << "Incorrect positions";
		return false;
	}
	if (elemPtr == start) {
		if (start == end) {
			start = end = NULL;
		}
		else {
			start = start->next;
		}
		delete elemPtr;
	}
	else {
		ListElement<T>* prevElemPtr = start;
		while (prevElemPtr->next != elemPtr) {
			prevElemPtr = prevElemPtr->next;
		}
		deleteAfter(prevElemPtr, x);
	}
	return true;
}

template<typename T>
void LList<T>::print()
{
	ListElement<T>* curElem = start;
	while (curElem) {
		cout << curElem->data << " ";
		curElem = curElem->next;
	}
	cout << endl;
}

template<typename T>
int LList<T>::length()
{
	int len = 0;
	iterStart();
	ListElement<T>* tempElemPtr = iter();
	while (tempElemPtr) {
		len++;
		tempElemPtr = iter();
	}
	return len;
}

template<typename T>
bool LList<T>::operator==(LList<T>& rhs)
{
	return (length() == rhs.length());
}

template<typename T>
istream& operator>>(istream& is, LList<T>& list) {
	T temp;
	is >> temp;
	list.insertToEnd(temp);
	return is;
}

template<typename T>
ostream& operator<<(ostream& os, LList<T>& list) {
	ListElement<T>* curElem = list.start;
	while (curElem) {
		os << curElem->data << " ";
		curElem = curElem->next;
	}
	os << endl;
	return os;
}

template<typename T>
ifstream& operator>>(ifstream& ifs, LList<T>& list) {
	T current_elem;
	while (ifs >> current_elem) {
		list.insertToEnd(current_elem);
	}
	return ifs;
}

template<typename T>
ofstream& operator<<(ofstream& ofs, LList<T>& list) {
	ListElement<T>* curElem = list.start;
	while (curElem) {
		ofs << curElem->data << " ";
		curElem = curElem->next;
	}
	return ofs;
}

#endif