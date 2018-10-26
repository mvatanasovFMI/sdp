#include <iostream>

template <typename T>
struct elem
{
	T inf; //data
	elem<T>* ptr;
};

template <typename T>
class Stack
{
private:
	elem<T>* start;
	void copyStack(const Stack<T>&);
	void delStack();
public:
	Stack();
	Stack(const Stack<T>&);
	Stack<T>& operator=(const Stack<T>&);
	~Stack();
	void push(const T&);
	void pop(T&);
	T top() const;
	bool empty() const;
	void print();
	Stack<T> sort();
};