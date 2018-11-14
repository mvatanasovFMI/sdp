#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "LinkedStructures.h"

template <typename T>
class LinkedQueue : public Linked<T> {
private:
	Element<T>* end;
	void copy(LinkedQueue const&);
public:
	LinkedQueue();
	LinkedQueue(LinkedQueue const&);
	LinkedQueue& operator=(LinkedQueue const&);
	void push(T const&);
	void pop();
	T top() const;
	T back() const;

	template <typename U>
	friend istream& operator>> (istream&, LinkedQueue<U>&);
	template <typename U>
	friend ifstream& operator>> (ifstream&, LinkedQueue<U>&);
	template <typename U>
	friend ostream& operator<< (ostream&, LinkedQueue<U> const&);
	template <typename U>
	friend ofstream& operator<< (ofstream&, LinkedQueue<U> const&);
	template <typename U>
	friend bool operator< (LinkedQueue<U> const&, LinkedQueue<U> const&);
};

template <typename T>
LinkedQueue<T>::LinkedQueue() : Linked<T>() {
	end = NULL;
}
template <typename T>
LinkedQueue<T>::LinkedQueue(LinkedQueue<T> const& r) {
	copy(r);
}
template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator= (LinkedQueue<T> const& r) {
	if (this == &r) return *this;
	copy(r);
	return *this;
}

template <typename T>
void LinkedQueue<T>::copy(LinkedQueue<T> const& r) {
	end = Linked<T>::copy(r);
}

template <typename T>
void LinkedQueue<T>::push(T const& x) {
	Element<T> *new1 = new Element<T>;
	new1->data = x;
	new1->link = NULL;
	if (this->front == NULL) this->front = end = new1;
	else {
		end->link = new1;
		end = new1;
	}
}
template <typename T>
void LinkedQueue<T>::pop() {
	if (this->empty() == 1) {
		cerr << "Popping from empty queue!";
		return;
	}
	Element<T>* old = this->front;
	this->front = this->front->link;
	delete old;
}
template <typename T>
T LinkedQueue<T>::top() const {
	if (this->empty() == 1) {
		cerr << "Getting top element of empty queue!";
		return T();
	}
	return this->front->data;
}
template <typename T>
T LinkedQueue<T>::back() const {
	if (this->empty() == 1) {
		cerr << "Getting back element of empty queue!";
		return T();
	}
	return end->data;
}

template <typename T>
istream& operator>> (istream& in, LinkedQueue<T>& obj) {
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
ifstream& operator>> (ifstream& in, LinkedQueue<T>& obj) {
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
ostream& operator<< (ostream& out, LinkedQueue<T> const& obj) {
	LinkedQueue<T> temp = obj;
	for (;;) {
		if (temp.empty() == 1) break;
		out << temp.top() << " ";
		temp.pop();
	}
	return out;
}
template <typename T>
ofstream& operator<< (ofstream& out, LinkedQueue<T> const& obj) {
	LinkedQueue<T> temp = obj;
	for (;;) {
		if (temp.empty() == 1) break;
		out << temp.top() << " ";
		temp.pop();
	}
	return out;
}
template <typename T>
bool operator< (LinkedQueue<T> const& l1, LinkedQueue<T> const& l2) {
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
