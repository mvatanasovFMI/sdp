#ifndef _QUEUE_H_
#define _QUEUE_H_

template <typename T>
class Queue
{
public:
	virtual void push(const T&) = 0;
	virtual bool pop(T&) = 0;
	virtual T& top() = 0;
	virtual bool isEmpty() const = 0;
	virtual void print() = 0;
};

#endif // !_QUEUE_H_

