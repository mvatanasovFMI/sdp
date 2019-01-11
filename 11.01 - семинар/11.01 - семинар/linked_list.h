#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
struct Elem
{
	T data;
	Elem* next;
};

template <typename T>
class LList
{
private:
	Elem<T>* start;
	Elem<T>* end;
	Elem<T>* curr;
protected:
	void CopyStructure(LList<T> const&);
	void DeleteStructure();
public:
	LList();
	LList(LList<T>& const);
	LList<T>& operator=(LList<T>& const);
	~LList();

	void IterStart(Elem<T>* ptr = nullptr);
	Elem<T>* Iter();

	void InsertToEnd(T);
	void InsertBefore(Elem<T>* ptr, T const);
	void InsertAfter(Elem<T>* ptr, T const);

	bool DeleteAfter(Elem<T>*, T&);
	bool DeleteBefore(Elem<T>*, T&);
	void DeleteElem(Elem<T>*, T&);

	void Print();
	int Length();

	void SetEnd(Elem<T>*);

	friend istream& operator>>(istream& is, LList<T>& l)
	{
		T a;
		int number;
		cin >> number;
		int cnt = 0;
		while (cnt < number)
		{
			is >> a;
			l.InsertToEnd(a);
			cnt++;
		}
		return is;
	};
	friend ostream& operator<<(ostream& os, LList<T>& l)
	{
		Elem<T>* curElemPtr = l.start;
		while (curElemPtr) {
			os << curElemPtr->data << " ";
			curElemPtr = curElemPtr->next;
		}
		os << endl;
		return os;
	};

	bool operator==(LList<T> rhs)
	{
		LList<T> temp = *this;
		return temp.Length() == rhs.Length();
	}

	friend ifstream& operator>>(ifstream& ifs, LList<T>& l)
	{
		T elem;
		while (ifs >> elem)
		{
			l.InsertToEnd(elem);
		}
		return ifs;
	};
	friend ofstream& operator<<(ofstream & ofs, LList<T>& l)
	{
		Elem<T>* curElemPtr = l.start;
		while (curElemPtr) {
			ofs << curElemPtr->data << " ";
			curElemPtr = curElemPtr->next;
		}
		ofs << endl;
		return ofs;
	};
};


template<typename T>
inline void LList<T>::CopyStructure(LList<T> const & rhs)
{
	start = end = nullptr;
	if (rhs.start) {
		Elem<T> *elemPtr = rhs.start;
		while (elemPtr) {
			InsertToEnd(elemPtr->data);
			elemPtr = elemPtr->next;
		}
	}
}

template<typename T>
inline void LList<T>::DeleteStructure()
{
	Elem<T> *elemPtr;
	while (start) {
		elemPtr = start;
		start = start->next;
		delete elemPtr;
	}
	end = nullptr;
}

template<typename T>
inline LList<T>::LList()
{
	start = end = nullptr;
}

template<typename T>
inline LList<T>::LList(LList<T>& const rhs)
{
	CopyStructure(rhs);
}

template<typename T>
inline LList<T>& LList<T>::operator=(LList<T>& const rhs)
{
	if (this != &rhs)
	{
		DeleteStructure();
		CopyStructure(rhs);
	}
	return *this;
}

template<typename T>
inline LList<T>::~LList()
{
	DeleteStructure();
}

template<typename T>
inline void LList<T>::IterStart(Elem<T>* ptr)
{
	if (!ptr)
	{
		curr = start;
	}
	else
	{
		curr = ptr;
	}
}

template<typename T>
inline Elem<T>* LList<T>::Iter()
{
	Elem<T>* ptr = curr;
	if (curr)
	{
		curr = curr->next;
	}
	return ptr;
}

template<typename T>
inline void LList<T>::InsertToEnd(T  x)
{
	Elem<T> * newElemPtr = new Elem<T>;
	newElemPtr->data = x;
	newElemPtr->next = nullptr;
	if (end) {
		end->next = newElemPtr;
	}
	else {
		start = newElemPtr;
	}
	end = newElemPtr;
}

template<typename T>
inline void LList<T>::InsertBefore(Elem<T>* elemPtr, T  const x)
{
	if (!elemPtr) {
		cerr << "Невалиден указател";
		return;
	}
	Elem<T> *newElemPtr = new Elem<T>;
	*newElemPtr = *elemPtr;
	if (elemPtr == end) end = newElemPtr;
	elemPtr->data = x;
	elemPtr->next = newElemPtr;
}

template<typename T>
inline void LList<T>::InsertAfter(Elem<T>* elemPtr, T const x)
{
	if (!elemPtr) {
		cerr << "Невалиден указател";
		return;
	}
	Elem<T>* newElemPtr = new Elem<T>;
	newElemPtr->data = x;
	newElemPtr->next = elemPtr->next;
	if (elemPtr == end) {
		end = newElemPtr;
	}
	elemPtr->next = newElemPtr;
}

template<typename T>
inline bool LList<T>::DeleteAfter(Elem<T>* elemPtr, T & x)
{
	if (!elemPtr || !elemPtr->next) {
		cerr << "Невалиден указател";
		return false;
	}
	Elem<T>* delElemPtr = elemPtr->next;
	x = delElemPtr->data;
	elemPtr->next = delElemPtr->next;
	if (delElemPtr == end) {
		end = elemPtr;
	}
	delete delElemPtr;
	return true;
}

template<typename T>
inline bool LList<T>::DeleteBefore(Elem<T>* elemPtr, T & x)
{
	if (!elemPtr || elemPtr == start) {
		cerr << "Невалиден указател";
		return false;
	}
	Elem<T>* prevElemPtr = start;
	while (prevElemPtr->next != elemPtr) {
		prevElemPtr = prevElemPtr->next;
	}
	DeleteElem(prevElemPtr, x);
	return true;
}

template<typename T>
inline void LList<T>::DeleteElem(Elem<T>* delElemPtr, T & x)
{
	if (!delElemPtr) {
		cerr << "Невалиден указател";
		return;
	}
	if (delElemPtr == start) {
		x = delElemPtr->data;
		if (start == end) {
			start = end = NULL;
		}
		else {
			start = start->next;
		}
		delete delElemPtr;
	}
	else {
		Elem<T>* prevElemPtr = start;
		while (prevElemPtr->next != delElemPtr) {
			prevElemPtr = prevElemPtr->next;
		}
		DeleteAfter(prevElemPtr, x);
	}
	return;
}

template<typename T>
inline void LList<T>::Print()
{
	Elem<T>* curElemPtr = start;
	while (curElemPtr) {
		cout << curElemPtr->data << " ";
		curElemPtr = curElemPtr->next;
	}
	cout << endl;
}

template<typename T>
inline int LList<T>::Length()
{
	int n = 0;
	Elem<T>* curElemPtr = start;
	while (curElemPtr) {
		n++;
		curElemPtr = curElemPtr->next;
	}
	return n;
}

template<typename T>
inline void LList<T>::SetEnd(Elem<T>* ptr)
{
	end = ptr;
}




#endif
