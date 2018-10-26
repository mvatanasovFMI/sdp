#include <fstream>
#include <string>
#include "stdafx.h"

using namespace std;

template<class T>
class StaticStack {
private:
	int capacity_;
	T* data_;
	int top_;

public:
	StaticStack(int capacity = 2);
	StaticStack(const StaticStack<T>&);
	StaticStack<T>& operator=(const StaticStack<T>&);
	~StaticStack();

	void push(T elem);
	T pop();
	T peek();
	bool empty() const;
};

template<typename T>
StaticStack<T>::StaticStack(int capacity) {
	data_ = new T[capacity];
	capacity_ = capacity;
	top_ = -1;
}

template<typename T>
StaticStack<T>::StaticStack(const StaticStack<T>& other) {
	capacity_ = other.capacity_;
	top_ = other.top_;
	data_ = new T[other.capacity_];

	for (int i = 0; i < other.top_; i++) {
		data_[i] = other.data_[i];
	}
}

template<typename T>
StaticStack<T>& StaticStack<T>::operator=(const StaticStack<T>& other) {
	if (this != &other) {
		capacity_ = other.capacity_;
		top_ = other.top_;

		delete[] data_;

		data_ = new T[capacity_];
		for (int i = 0; i < other.top_; i++) {
			data_[i] = other.data_[i];
		}
	}

	return *this;
}

template<typename T>
void StaticStack<T>::push(T elem) {
	if (top_ == capacity_ - 1) {
		T* temp_data = data_;

		data_ = new T[capacity_ * 2];
		for (int i = 0; i < capacity_; i++) {
			data_[i] = temp_data[i];
		}

		delete temp_data;

		capacity_ = capacity_ * 2;
	}

	data_[++top_] = elem;
}

template<typename T>
T StaticStack<T>::pop() {
	return data_[top_--];
}

template<typename T>
T StaticStack<T>::peek() {
	return data_[top_];
}

template<typename T>
bool StaticStack<T>::empty() const {
	return top_ == -1;
}

template<typename T>
StaticStack<T>::~StaticStack() {
	delete[] data_;
}
