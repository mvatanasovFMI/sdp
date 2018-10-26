#include "stdafx.h"
#include <fstream>
#include <cassert>
#include <string>
#include <chrono>
#include "Stack.h"

using namespace std;

template <typename T>
T Stack<T>::top() const
{
	return start->inf;
}

template <typename T>
void Stack<T>::copyStack(const Stack<T>& other)
{
	if (other.start)
	{
		elem<T>* p = other.start, *q = NULL, *s = NULL;
		start = new elem<T>;
		assert(start);
		start->inf = p->inf;
		start->ptr = q;
		q = start;
		p = p->ptr;
		while (p) {
			s = new elem<T>;
			assert(s != NULL);
			s->inf = p->inf;
			q->ptr = s;
			q = s;
			p = p->ptr;
		}
		q->ptr = NULL;
	}
	else start = NULL;
}

template <typename T>
void Stack<T>::delStack()
{
	elem<T>* p;
	while (start)
	{
		p = start;
		start = start->ptr;
		delete p;
	}
}

template <typename T>
Stack<T>::Stack()
{
	start = NULL;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
{
	copyStack(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this != &other)
	{
		delStack();
		copyStack(other);
	}
	return *this;
}

template <typename T>
Stack<T>::~Stack()
{
	delStack();
}

template <typename T>
void Stack<T>::push(const T& element)
{
	elem<T>* p = start;
	start = new elem<T>;
	assert(start);
	start->inf = element;
	start->ptr = p;
}

template <typename T>
void Stack<T>::pop(T& element)
{
	if (start)
	{
		element = start->inf;
		elem<T>* p = start;
		start = start->ptr;
		delete p;
	}
	else
	{
		std::cout << "Stack is empty!\n";
		exit(1);
	}
}

template <typename T>
bool Stack<T>::empty() const
{
	return start == NULL;
}

template <typename T>
void Stack<T>::print()
{
	T x;
	while (!empty())
	{
		pop(x);
		std::cout << x << std::endl;
	}
}

template <typename T>
Stack<T> Stack<T>::sort()
{
	Stack<T> tmpStack;
	T getNumber;

	while (!empty())
	{
		T tmp = top();
		pop(getNumber);

		while (!tmpStack.empty() && tmpStack.top() > tmp)
		{
			push(tmpStack.top());
			tmpStack.pop(getNumber);
		}

		tmpStack.push(tmp);
	}

	//tmpStack.print();
	return tmpStack;
}


int main()
{
	Stack<string> stWords;
	ifstream iFile("text.txt", ios::in);
	if (!iFile)
	{
		cerr << "File couldn't be opened!\n";
		exit(1);
	}
	iFile.seekg(0, ios::beg);
	string readString;

	auto start = std::chrono::system_clock::now();
	while (iFile >> readString)
	{
		stWords.push(readString);
	}

	Stack<string> stInvert;
	while (!stWords.empty())
	{
		stWords.pop(readString);
		stInvert.push(readString);
	}

	stInvert.print();	
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	cout << elapsed_seconds.count() << endl;

	system("pause>0");
    return 0;
}

