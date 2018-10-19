#include "Stack.h"

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