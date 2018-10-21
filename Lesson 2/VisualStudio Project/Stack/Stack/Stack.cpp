#include "Stack.h"
Stack::Stack() {
	length = 0;
}
void Stack::push(double itemToPush)
{
	//assert(!this->isFull());
	if (length <= MAX_STACK_LENGTH - 1) {
		data[length] = itemToPush;
		length++;
		return;
	}
	std::cout << "Stack is already full";
}
double Stack::top()
{
	//assert(!this->isEmpty());
	double result = data[length - 1];
	length--;
	return result;
}
bool Stack::isFull()
{
	return (length == MAX_STACK_LENGTH);
}
bool Stack::isEmpty()
{
	return (length == 0);
}
void Stack::sortStack()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length; j++)
		{
			if (*(data + j) > *(data + i))
			{
				std::swap(*(data + j), *(data + i));
			}
		}
	}
}