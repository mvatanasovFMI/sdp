#include "stack.h"

Stack::Stack()
{
	top = -1;
}

void Stack::push(double x)
{
	if (!full()) {
		top++;
		arr[top] = x;
	}
	else {
		cout << "The stack is full" << endl;
	}
}

void Stack::pop(double& x)
{
	if (!empty()) {
		x = arr[top];
		top--;
	}
	else {
		cout << "The stack is empty" << endl;
	}
}

bool Stack::empty() const
{
	return (top == -1);
}

bool Stack::full() const
{
	return (top == SIZE - 1);
}

void Stack::sortStack()
{

	for (int i = 0; i < top - 1; i++) {
		for (int j = 0; j < top - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void Stack::print()
{
	double x;
	while (!empty()) {
		pop(x);
		cout << "x: " << x << endl;
	}
	cout << endl;
}


