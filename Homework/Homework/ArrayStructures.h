#ifndef ARRAYSTRUCTURES_H
#define ARRAYSTRUCTURES_H

#include <iostream>
using namespace std;

template <typename T>
class Array {
protected:
	T * arr;
	int capacity, size;

	void copy(Array const&);
	void erase();
	bool full() const;
	virtual void resize() = 0;
public:
	Array();
	Array(Array const&);
	Array& operator=(Array const&);
	~Array();

	bool empty() const;
	virtual void push(T const&) = 0;
	virtual void pop() = 0;
	virtual T top() const = 0;
};

template <typename T>
Array<T>::Array() {
	arr = new T[8];
	capacity = 8;
	size = 0;
}
template <typename T>
Array<T>::Array(Array<T> const& r) {
	copy(r);
}
template <typename T>
Array<T>& Array<T>::operator= (Array<T> const& r) {
	if (this == &r) return *this;
	erase(); copy(r);
	return *this;
}
template <typename T>
Array<T>::~Array() {
}

template <typename T>
void Array<T>::copy(Array<T> const& r) {
	capacity = r.capacity;
	size = r.size;
	arr = new T[capacity];
	for (int i = 0; i < capacity; i++) {
		arr[i] = r.arr[i];
	}
}
template <typename T>
void Array<T>::erase() {
	delete[] arr;
}
template <typename T>
bool Array<T>::full() const {
	if (size == capacity) return true;
	return false;
}

template <typename T>
bool Array<T>::empty() const {
	if (size == 0) return true;
	return false;
}
#endif