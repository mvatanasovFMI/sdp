#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "ArrayStructures.h"

template <typename T>
class ArrayQueue : public Array<T> {
private:
	int beg, end;
	void copy(ArrayQueue const&);
	void resize();
public:
	ArrayQueue();
	void push(T const&);
	void pop();
	T top() const;
	T back() const;

	template <typename U>
	friend istream& operator>> (istream&, ArrayQueue<U>&);
	template <typename U>
	friend ifstream& operator>> (ifstream&, ArrayQueue<U>&);
	template <typename U>
	friend ostream& operator<< (ostream&, ArrayQueue<U> const&);
	template <typename U>
	friend ofstream& operator<< (ofstream&, ArrayQueue<U> const&);
	template <typename U>
	friend bool operator< (ArrayQueue<U> const&, ArrayQueue<U> const&);
};

template <typename T>
ArrayQueue<T>::ArrayQueue() {
	beg = end = 0;
}

template <typename T>
void ArrayQueue<T>::copy(ArrayQueue<T> const& r) {
	beg = r.beg; end = r.end;
	Array<T>::copy(r);
}
template <typename T>
void ArrayQueue<T>::resize() {
	T* old = this->arr;
	int i;
	this->arr = new T[2 * this->capacity];
	for (i = beg; i < this->capacity; i++) {
		this->arr[i - beg] = old[i];
	}
	for (i = 0; i < beg; i++) {
		this->arr[i + beg] = old[i];
	}
	this->capacity *= 2;
	beg = 0; end = this->size;
	delete[] old;
}

template <typename T>
void ArrayQueue<T>::push(T const& x) {
	if (this->full() == 1) resize();
	this->arr[end] = x;
	end++; end %= this->capacity;
	this->size++;
}
template <typename T>
void ArrayQueue<T>::pop() {
	if (this->empty() == 1) {
		cerr << "Popping from empty queue!";
		return;
	}
	beg++; beg %= this->capacity;
	this->size--;
}
template <typename T>
T ArrayQueue<T>::top() const {
	if (this->empty() == 1) {
		cerr << "Getting top element of empty queue!";
		return T();
	}
	return this->arr[beg];
}
template <typename T>
T ArrayQueue<T>::back() const {
	if (this->empty() == 1) {
		cerr << "Getting back element of empty queue!";
		return T();
	}
	return arr[end - 1];
}

template <typename T>
istream& operator>> (istream& in, ArrayQueue<T>& obj) {
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
ifstream& operator>> (ifstream& in, ArrayQueue<T>& obj) {
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
ostream& operator<< (ostream& out, ArrayQueue<T> const& obj) {
	ArrayQueue<T> temp = obj;
	for (;;) {
		if (temp.empty() == 1) break;
		out << temp.top() << " ";
		temp.pop();
	}
	return out;
}
template <typename T>
ofstream& operator<< (ofstream& out, ArrayQueue<T> const& obj) {
	ArrayQueue<T> temp = obj;
	for (;;) {
		if (temp.empty() == 1) break;
		out << temp.top() << " ";
		temp.pop();
	}
	return out;
}
template <typename T>
bool operator< (ArrayQueue<T> const& l1, ArrayQueue<T> const& l2) {
	if (l1.size < l2.size) return true;
	return false;
}
#endif
