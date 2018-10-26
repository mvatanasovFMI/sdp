// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

const int MAX_SIZE = 5000;

using namespace std;
using namespace std::chrono;

template <typename T>
class Stack {
private:
	T arr[MAX_SIZE];
	int topIndex;
public:
	Stack();

	bool is_empty() const;
	bool is_full() const;
	void push(T);
	T pop();
	T top_element() const;
};

int main()
{
	auto start = system_clock::now();

	Stack<string> s;
	fstream file;
	file.open("C:\\Users\\grade\\source\\repos\\UP\\stack_and_files\\ConsoleApplication3\\test_string.txt", ios::in);
	string a;
	while (file >> a)
	{
		s.push(a);
	}
	file.close();
	while (!s.is_empty())
	{
		cout << s.pop();
	}

	auto end = system_clock::now();
	auto duration = duration_cast<nanoseconds>(end - start);
	cout << duration.count();
	system("pause");
    return 0;
}

template<typename T>
bool Stack<T>::is_empty() const
{
	return topIndex==-1;
}

template<typename T>
Stack<T>::Stack()
{
	topIndex = -1;
}

template<typename T>
bool Stack<T>::is_full() const
{
	return topIndex==MAX_SIZE-1;
}

template<typename T>
void Stack<T>::push(T x)
{
	if(!is_full())
{
	arr[++topIndex] = x;
}
	else cerr << "The stack is full! \n";
}

template<typename T>
T Stack<T>::pop()
{
	if (!is_empty())
	{
	return arr[topIndex--];
	}
	else
	{
		cerr << "The stack is empty! \n";
	}
}

template<typename T>
T Stack<T>::top_element() const
{
	return arr[topIndex];
}
