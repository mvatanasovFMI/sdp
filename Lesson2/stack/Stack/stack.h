#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
using namespace std;

const int RESIZE = 100;

template <typename T>

class Stack
{
private:
	T* arr;
	int size;
	int capacity;
	void resize();
	void copyStack(const Stack&);
public:
	Stack();
	Stack(const Stack&);
	Stack& operator=(const Stack&);
	~Stack();

	void push(const T&);
	T& pop();
	T& top();
	void print();
	bool isEmpty() const;
	void sort();
};

template<typename T>
void Stack<T>::resize()
{
	capacity += RESIZE;
	T* temp = arr;
	arr = new T[capacity];
	for (int i = 0; i < size; i++) { arr[i] = temp[i]; }
	//delete temp;
}

template<typename T>
void Stack<T>::copyStack(const Stack& other)
{
	size = other.size;
	capacity = other.capacity;
	arr = new T[capacity];
	for (int i = 0; i < size; i++) { arr[i] = other.arr[i]; }
}

template<typename T>
Stack<T>::Stack() : size(0), capacity(1), arr(NULL)
{
}

template<typename T>
Stack<T>::Stack(const Stack& other)
{
	copyStack(other);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
	if (this != &other)
	{
		delete arr;
		copyStack(other);
	}
	return *this;
}

template<typename T>
Stack<T>::~Stack()
{
	delete arr;
}

template<typename T>
void Stack<T>::push(const T & elem)
{
	if (size == capacity - 1) { resize(); }
	arr[size++] = elem;
}

template<typename T>
T & Stack<T>::pop()
{
	if (size > 0) { size--; return arr[size]; }
}

template<typename T>
T & Stack<T>::top()
{
	if (size > 0) { return arr[size - 1]; }
}

template<typename T>
void Stack<T>::print()
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << "  ";
	cout << endl;
}

template<typename T>
inline bool Stack<T>::isEmpty() const
{
	return size == 0;
}

template<typename T>
void Stack<T>::sort()
{
	Stack<T> tmpStack;
	Stack<T> input = *this;
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