#ifndef _GENERIC_DATA_STRUCTURE_H_
#define _GENERIC_DATA_STRUCTURE_H_

template <typename T>
class GenericDataStructure
{
public:
	virtual void push(const T&) = 0;
	virtual bool pop(T&) = 0;
	virtual T& top() = 0;
	virtual bool isEmpty() const = 0;
	virtual void print() = 0;
};

#endif // !_GENERIC_DATA_STRUCTURE_H_

