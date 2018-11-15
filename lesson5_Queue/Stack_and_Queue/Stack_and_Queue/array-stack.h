#ifndef _ARRAY_STACK_H_
#define _ARRAY_STACK_H_

#include <iostream>
#include "stack.h"
#include <fstream>

using namespace std;

const int CAPACITY = 100;

template <typename T>
class ArrayStack : public Stack<T>
{
private:
	T* arr;
	int size;
	int capacity;
	void resize();
	void copyArrayStack(const ArrayStack &);
	void deleteArrayStack();
public:
	ArrayStack(int = CAPACITY);
	ArrayStack(const ArrayStack &);
	ArrayStack<T>& operator=(const ArrayStack &);
	~ArrayStack();

	bool isEmpty() const;
	bool isFull() const;
	void push(const T &);
	bool pop(T&);
	T& top();
	void print();

	bool operator==(const ArrayStack &);

	friend istream& operator>><T>(istream &, ArrayStack<T> &);
	friend ostream& operator<<<T>(ostream &, ArrayStack<T> &);

	friend ifstream& operator>><T>(ifstream &, ArrayStack<T> &);
	friend ofstream& operator<<<T>(ofstream &, ArrayStack<T> &);
	
};

template<typename T>
void ArrayStack<T>::resize()
{
	T* tempArr = arr;
	capacity += CAPACITY;
	arr = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		arr[i] = tempArr[i];
	}
	delete tempArr;
}

template<typename T>
void ArrayStack<T>::copyArrayStack(const ArrayStack & other)
{
	size = other.size;
	capacity = other.capacity;
	arr = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}

template<typename T>
void ArrayStack<T>::deleteArrayStack()
{
	delete[] arr;
	size = capacity = 0;
}

template<typename T>
ArrayStack<T>::ArrayStack(int cap) : size(0), capacity(cap)
{
	arr = new T[capacity];
}

template<typename T>
ArrayStack<T>::ArrayStack(const ArrayStack & other)
{
	copyArrayStack(other);
}

template<typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack & other)
{
	if (&other != this)
	{
		deleteArrayStack();
		copyArrayStack(other);
	}
	return *this;
}

template<typename T>
ArrayStack<T>::~ArrayStack()
{
	deleteArrayStack();
}

template<typename T>
bool ArrayStack<T>::isEmpty() const
{
	return size == 0;
}

template<typename T>
bool ArrayStack<T>::isFull() const
{
	return size == capacity - 1;
}

template<typename T>
void ArrayStack<T>::push(const T & elem)
{
	if (isFull()) 
	{
		resize();
	}
	arr[size++] = elem;
}

template<typename T>
bool ArrayStack<T>::pop(T & elem)
{
	if (isEmpty())
	{
		return false;
	}
	elem = arr[--size];
	return true;
}

template<typename T>
 T & ArrayStack<T>::top()
{
	 if (!isEmpty())
	 {
		 return arr[size - 1];
	 }
	 //return T();
}

template<typename T>
void ArrayStack<T>::print()
{
	T currentData;
	while (!isEmpty())
	{
		pop(currentData);
		cout << currentData << " ";
	}
	cout << endl;
}

template<typename T>
bool ArrayStack<T>::operator==(const ArrayStack & other)
{
	ArrayStack<T> first = *this;
	ArrayStack<T> second = other;
	T elemFirst, elemSecond;
	while (!first.isEmpty() && !second.isEmpty())
	{
		first.pop(elemFirst);
		second.pop(elemSecond);
		if (elemFirst != elemSecond)
		{
			return false;
		}
	}
	return first.isEmpty() && second.isEmpty();
}

template<typename T>
istream& operator>>(istream & is, ArrayStack<T> & st)
{
	int numberElements;
	is >> numberElements;
	T elem;
	for (int i = 0; i < numberElements; i++)
	{
		is >> elem;
		st.push(elem);
	}
	return is;
}

template<typename T>
ostream& operator<<(ostream & os, ArrayStack<T> & st)
{
	T elem;
	ArrayStack<T> temp = st;
	while (!temp.isEmpty())
	{
		temp.pop(elem);
		os << elem << " ";
	}
	os << endl;
	return os;
}

template<typename T>
ifstream& operator>>(ifstream &ifs, ArrayStack<T>& st)
{
	T elem;
	while (ifs >> elem)
	{
		st.push(elem);
	}
	return ifs;
}

template<typename T>
ofstream& operator<<(ofstream & ofs, ArrayStack<T>& st)
{
	ArrayStack<T> temp = st;
	T elem;
	while (!temp.isEmpty())
	{
		temp.pop(elem);
		ofs << elem << " ";
	}
	ofs << endl;
}

#endif // !_ARRAY_STACK_H_