#ifndef _STACK_H_
#define _STACK_H_

template <typename T>
class Stack
{
public:
	virtual bool isEmpty() const = 0;
	virtual T& top() = 0;
	virtual void push(const T &) = 0;
	virtual bool pop(T&) = 0;
	virtual void print() = 0;
};

#endif // !_STACK_H_

