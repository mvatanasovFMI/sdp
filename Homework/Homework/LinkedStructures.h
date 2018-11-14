#ifndef LINKEDSTRUCTURES_H
#define LINKEDSTRUCTURES_H

#include <iostream>
using namespace std;

template <typename T>
struct Element {
	T data;
	Element* link;
};

template <typename T>
class Linked {
protected:
	Element<T> * front;

	Element<T>* copy(Linked const&);
	void erase();
public:
	Linked();
	Linked(Linked const&);
	Linked& operator=(Linked const&);
	~Linked();

	bool empty() const;
	virtual void push(T const&) = 0;
	virtual void pop() = 0;
	virtual T top() const = 0;
};

template <typename T>
Linked<T>::Linked() {
	front = NULL;
}
template <typename T>
Linked<T>::Linked(Linked<T> const& r) {
	copy(r);
}
template <typename T>
Linked<T>& Linked<T>::operator= (Linked<T> const& r) {
	if (this == &r) return *this;
	erase(); copy(r);
	return *this;
}
template <typename T>
Linked<T>::~Linked() {
	erase();
}

template <typename T>
Element<T>* Linked<T>::copy(Linked<T> const& r) {
	Element<T> *new1, *curr1=NULL, *curr2;
	curr2 = r.front;
	front = NULL;
	for (;;) {
		if (curr2 == NULL) break;
		new1 = new Element<T>;
		new1->data = curr2->data;
		new1->link = NULL;
		if (curr1 == NULL) front = new1;
		else curr1->link = new1;
		curr1 = new1;
		curr2 = curr2->link;
	}
	return curr1;
}
template <typename T>
void Linked<T>::erase() {
	Element<T> *old;
	for (;;) {
		if (front == NULL) break;
		old = front;
		front = front->link;
		delete old;
	}
}

template <typename T>
bool Linked<T>::empty() const {
	if (front == NULL) return true;
	return false;
}
#endif