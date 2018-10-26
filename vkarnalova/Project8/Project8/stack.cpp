#include "stack.h"

void Stack::CopyStack(const Stack &)
{

}

Stack::Stack()
{
	top = -1;
}

void Stack::Push(char x)
{
	if (!Full()) {
		top++;
		arr[top] = x;
	}
	else {
		cout << "The stack is full" << endl;
	}
}

void Stack::Pop(char& x)
{
	if (!Empty()) {
		x = arr[top];
		top--;
	}
	else {
		cout << "The stack is empty" << endl;
	}
}

bool Stack::Empty() const
{
	return (top == -1);
}

bool Stack::Full() const
{
	return (top == SIZE - 1);
}

double Stack::Top()
{

	return arr[top];

}
void Stack::Print()
{
	char x;
	while (!Empty()) {
		Pop(x);
		cout << x;
	}
	cout << endl;
}
