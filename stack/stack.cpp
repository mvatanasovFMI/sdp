#include "stack.h"

Stack::Stack()
{
	n = 0;
	arr[n] = 0;
}

void Stack::push(float x)
{
	if (!full()) {
		n++;
		arr[n] = x;
	}
	else {cout <<"Stack is full!";}
}

void Stack::pop()
{
	if (!empty()) {
		
			n--;
		
	}
	else { cout << "Stack is empty!"; }
	
}

void Stack::print()
{
	while (!empty()) {
		cout <<  top() << " ";
		pop();

	}
}

float Stack::top() const
{
	return arr[n];
}

bool Stack::empty() const
{
	return n==0;
}

bool Stack::full() const
{
	return n == max-1;
}

void Stack::sort()
{
	
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
				if (arr[j] < arr[j + 1]) {
					
					float temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}

		}

}
