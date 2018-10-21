#include <cassert>
#include <iostream>
const int MAX_STACK_LENGTH = 4000;
class Stack {
private:
	int length;
	double data[MAX_STACK_LENGTH];
public:
	Stack();
	void push(double);
	double top();
	bool isFull();
	bool isEmpty();
	void sortStack();
};