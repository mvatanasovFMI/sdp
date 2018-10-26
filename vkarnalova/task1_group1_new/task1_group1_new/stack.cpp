#include "stack.h"

void Stack::CopyStack(const Stack &)
{

}

Stack::Stack()
{
	top = -1;
}

void Stack::Push(double x)
{
	if (!Full()) {
		top++;
		arr[top] = x;
	}
	else {
		cout << "The stack is full" << endl;
	}
}

void Stack::Pop(double& x)
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

void Stack::SortStack()
{
	Stack temp_stack;
	while (!Empty()) {
		double temp_elem;
		Pop(temp_elem);
		while (!Empty() && temp_stack.Top() > temp_elem) {
			double temp;
			temp_stack.Pop(temp);
			Push(temp);
		}
		temp_stack.Push(temp_elem);
	}
	*this = temp_stack;
}

void Stack::Print()
{
	double x;
	while (!Empty()) {
		Pop(x);
		cout << x << endl;
	}
	cout << endl;
}
