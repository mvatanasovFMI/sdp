#include "Stack.h"
#include<iostream>
using namespace std;


Stack::Stack()
{
	symbol[0] = '\0';
	top = -1;
}

void Stack::push(char a)
{
	symbol[top + 1] = a;
	top++;
}

void Stack::pop()
{
	while (top >= 0)
	{
		top--;
		cout << symbol[top + 1];
	}

}

Stack::~Stack()
{
}
