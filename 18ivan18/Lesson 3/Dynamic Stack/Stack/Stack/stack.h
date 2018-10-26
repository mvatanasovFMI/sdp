#ifndef STACK_STACK_STACK_H_
#define STACK_STACK_STACK_H_
#include <iostream>
using namespace std;

template <typename T>
struct elem {
	T value;
	elem* next;
};


template <typename T>
class Stack {
private:
	elem<T>* top;
	void deleteStack();
	void copy(const Stack&);
public:
	Stack();
	Stack(T);
	~Stack();
	Stack& operator=(const Stack&);
	Stack(const Stack&);

	T pop();
	void push(const T&);
	T peek() const;
	bool empty() const;
	void sort();
	bool isEmpty();
	//void print();
	void print();
	//friend ostream& operator<<(ostream&, Stack<T>);
};
#endif // !STACK_STACK_STACK_H_

template<typename T>
inline void Stack<T>::deleteStack()
{
	elem<T>* temp;
	while (top)
	{
		temp = top;	
		top = temp->next;
		delete temp;
	}
}

template<typename T>
inline void Stack<T>::copy(const Stack<T>& other)
{
	if (other.top)
	{
		elem<T> *p = other.top, *q = nullptr, *s = nullptr;
		top = new elem<T>;
		top->value = p->value;
		top->next = q;
		q = top;
		p = p->next;
		while (p) {
			s = new elem<T>;
			s->value = p->value;
			q->next = s;
			q = s;
			p = p->next;
		}
		q->next = nullptr;
	}
	else top = nullptr;
}

template<typename T>
inline Stack<T>::Stack()
{
	top = nullptr;
}

template<typename T>
inline Stack<T>::~Stack()
{
	deleteStack();
}

template<typename T>
inline Stack<T> & Stack<T>::operator=(const Stack & other)
{
	// TODO: insert return statement here
	if (this != &other)
	{
		deleteStack();
		copy(other);
	}
	return *this;
}

template<typename T>
inline Stack<T>::Stack(const Stack& other)
{
	copy(other);
}

template<typename T>
inline T Stack<T>::pop()
{
	if (top)
	{
		T temp = top->value;
		elem<T>* p = top;
		top = top->next;
		delete p;
		return temp;
	}
	else {
		cerr << "The stack is empty!!1!";
	}
}

template<typename T>
inline void Stack<T>::push(const T& other)
{
	elem<T>* temp = top;
	top = new elem<T>;
	top->value = other;
	top->next = temp;
}

template<typename T>
inline T Stack<T>::peek() const
{
	return top->value;
}

template<typename T>
inline bool Stack<T>::empty() const
{
	return top == nullptr;
}

template<typename T>
inline void Stack<T>::sort()
{
	Stack<T> temp;
	T t;
	while (top) {
		t = pop();
		while (top && temp.peek()>t) {
			push(temp.pop());
		}
		temp.push(t);
	}
	*this = temp;
}

template<typename T>
inline bool Stack<T>::isEmpty()
{
	if (top != nullptr)
	{
		return true;
	}
	return false;
}

template<typename T>
inline void Stack<T>::print()
{
	elem<T>* temp = top;
	do
	{
		cout << temp->value;
		temp = temp->next;
	} while (temp);
}

