#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "ArrayStructures.h"

template <typename T>
class ArrayStack : public Array<T> {
private:
	void resize();
public:
	void push(T const&);
	void pop();
	T top() const;

	template <typename U>
	friend istream& operator>> (istream&, ArrayStack<U>&);
	template <typename U>
	friend ifstream& operator>> (ifstream&, ArrayStack<U>&);
	template <typename U>
	friend ostream& operator<< (ostream&, ArrayStack<U> const&);
	template <typename U>
	friend ofstream& operator<< (ofstream&, ArrayStack<U> const&);
	template <typename U>
	friend bool operator< (ArrayStack<U> const&, ArrayStack<U> const&);
};

template <typename T>
void ArrayStack<T>::resize() {
	T* old = this->arr;
	this->arr = new T[2 * this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->arr[i] = old[i];
	}
	this->capacity *= 2;
	delete[] old;
}

template <typename T>
void ArrayStack<T>::push(T const& x) {
	if (this->full() == 1) resize();
	this->arr[this->size++] = x;
}
template <typename T>
void ArrayStack<T>::pop() {
	if (this->empty() == 1) {
		cerr << "Popping from empty stack!";
		return;
	}
	this->size--;
}
template <typename T>
T ArrayStack<T>::top() const {
	if (this->empty() == 1) {
		cerr << "Getting top element of empty stack!";
		return T();
	}
	return this->arr[this->size - 1];
}

template <typename T>
istream& operator>> (istream& in, ArrayStack<T>& obj) {
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
ifstream& operator>> (ifstream& in, ArrayStack<T>& obj) {
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
ostream& operator<< (ostream& out, ArrayStack<T> const& obj) {
	ArrayStack<T> temp = obj;
	for (;;) {
		if (temp.empty() == 1) break;
		out << temp.top() << " ";
		temp.pop();
	}
	return out;
}
template <typename T>
ofstream& operator<< (ofstream& out, ArrayStack<T> const& obj) {
	ArrayStack<T> temp = obj;
	for (;;) {
		if (temp.empty() == 1) break;
		out << temp.top() << " ";
		temp.pop();
	}
	return out;
}
template <typename T>
bool operator< (ArrayStack<T> const& l1, ArrayStack<T> const& l2) {
	if (l1.size < l2.size) return true;
	return false;
}
#endif
