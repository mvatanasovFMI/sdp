#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "LinkedStructures.h"

template <typename T>
class LinkedStack : public Linked<T> {
public:
	void push(T const&);
	void pop();
	T top() const;

	template <typename U>
	friend istream& operator>> (istream&, LinkedStack<U>&);
	template <typename U>
	friend ifstream& operator>> (ifstream&, LinkedStack<U>&);
	template <typename U>
	friend ostream& operator<< (ostream&, LinkedStack<U> const&);
	template <typename U>
	friend ofstream& operator<< (ofstream&, LinkedStack<U> const&);
	template <typename U>
	friend bool operator< (LinkedStack<U> const&, LinkedStack<U> const&);
};

template <typename T>
void LinkedStack<T>::push(T const& x) {
	Element<T>* new1 = new Element<T>;
	new1->data = x;
	new1->link = this->front;
	this->front = new1;
}
template <typename T>
void LinkedStack<T>::pop() {
	if (this->empty() == 1) {
		cerr << "Popping from empty stack!";
		return;
	}
	Element<T>* old = this->front;
	this->front = this->front->link;
	delete old;

}
template <typename T>
T LinkedStack<T>::top() const {
	if (this->empty() == 1) {
		cerr << "Getting top element of empty stack!";
		return T();
	}
	return this->front->data;
}

template <typename T>
istream& operator>> (istream& in, LinkedStack<T>& obj) {
	int n, i;
	T val;
	in >> n;
	for (i = 0; i < n; i++) {
		in >> val;
		obj.push(val);
	}
	return in;
}
template <typename T>
ifstream& operator>> (ifstream& in, LinkedStack<T>& obj) {
	int n, i;
	T val;
	in >> n;
	for (i = 0; i < n; i++) {
		in >> val;
		obj.push(val);
	}
	return in;
}
template <typename T>
ostream& operator<< (ostream& out, LinkedStack<T> const& obj) {
	LinkedStack<T> temp = obj;
	for (;;) {
		if (temp.empty() == 1) break;
		out << temp.top() << " ";
		temp.pop();
	}
	return out;
}
template <typename T>
ofstream& operator<< (ofstream& out, LinkedStack<T> const& obj) {
	LinkedStack<T> temp = obj;
	for (;;) {
		if (temp.empty() == 1) break;
		out << temp.top() << " ";
		temp.pop();
	}
	return out;
}
template <typename T>
bool operator< (LinkedStack<T> const& l1, LinkedStack<T> const& l2) {
	Element<T> *curr1, *curr2;
	curr1 = l1.front;
	curr2 = l2.front;
	for (;;) {
		if ((curr1 == NULL) || (curr2 == NULL)) break;
		curr1 = curr1->link;
		curr2 = curr2->link;
	}
	if (curr2 != NULL) return true;
	return false;
}
#endif
