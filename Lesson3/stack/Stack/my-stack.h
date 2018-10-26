#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
using namespace std;

const int RESIZE = 100;

template <typename T>

class MyStack
{
private:
	T* arr;
	int size;
	int capacity;
	void resize();
	void copyStack(const MyStack&);
public:
	MyStack();
	MyStack(const MyStack&);
	MyStack& operator=(const MyStack&);
	~MyStack();

	void push(const T&);
	T& pop();
	T& top();
	void print();
	bool isEmpty() const;
	void sort();
};

template<typename T>
void MyStack<T>::resize()
{
	capacity += RESIZE;
	T* temp = arr;
	arr = new T[capacity];
	for (int i = 0; i < size; i++) { arr[i] = temp[i]; }
	//delete temp;
}

template<typename T>
void MyStack<T>::copyStack(const MyStack& other)
{
	size = other.size;
	capacity = other.capacity;
	arr = new T[capacity];
	for (int i = 0; i < size; i++) { arr[i] = other.arr[i]; }
}

template<typename T>
MyStack<T>::MyStack() : size(0), capacity(1), arr(NULL)
{
}

template<typename T>
MyStack<T>::MyStack(const MyStack& other)
{
	copyStack(other);
}

template<typename T>
MyStack<T>& MyStack<T>::operator=(const MyStack& other)
{
	if (this != &other)
	{
		delete arr;
		copyStack(other);
	}
	return *this;
}

template<typename T>
MyStack<T>::~MyStack()
{
	delete arr;
}

template<typename T>
void MyStack<T>::push(const T & elem)
{
	if (size == capacity - 1) { resize(); }
	arr[size++] = elem;
}

template<typename T>
T & MyStack<T>::pop()
{
	if (size > 0) { size--; return arr[size]; }
}

template<typename T>
T & MyStack<T>::top()
{
	if (size > 0) { return arr[size - 1]; }
}

template<typename T>
void MyStack<T>::print()
{
	while (!isEmpty())
	{
		cout << pop() << endl;
	}
}

template<typename T>
inline bool MyStack<T>::isEmpty() const
{
	return size == 0;
}

template<typename T>
void MyStack<T>::sort()
{
	MyStack<T> tmpStack;
	MyStack<T> input = *this;
	while (!input.isEmpty())
	{
		T tmp = input.top();
		input.pop();

		while (!tmpStack.isEmpty() && tmpStack.top() > tmp)
		{
			input.push(tmpStack.top());
			tmpStack.pop();
		}

		tmpStack.push(tmp);
	}

	*this = tmpStack;
}


#endif // !_STACK_H_