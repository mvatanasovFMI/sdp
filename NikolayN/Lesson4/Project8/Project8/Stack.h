#pragma once

const int max = 100;
class Stack
{
private:
	char symbol[max];
	int top;
public:
	Stack();
	void push(char);
	void pop();
	~Stack();
};

