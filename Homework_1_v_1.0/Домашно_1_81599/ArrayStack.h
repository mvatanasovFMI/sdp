#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_
#include <iostream>
#include <fstream>
#include "DataStructures.h"

using namespace std;

template <typename T>
class ArrayStack : public DataStructure<T>
{
private:
	T body_[max_size];
	int top_index_;
public:
	ArrayStack();

	bool IsEmpty() const;
	bool IsFull() const;

	T Top();

	void Push(T);
	T Pop();

	int Length();

	bool operator==(ArrayStack<T>&);

	
};

template<typename T>
ArrayStack<T>::ArrayStack()
{
	top_index_ = -1;
}

template<typename T>
bool ArrayStack<T>::IsEmpty() const
{
	return top_index_ == -1;
}

template<typename T>
bool ArrayStack<T>::IsFull() const
{
	return top_index_ == max_size - 1;
}

template<typename T>
T ArrayStack<T>::Top()
{
	return body_[top_index_];
}

template<typename T>
void ArrayStack<T>::Push(T pushed_element)
{	
	if (!IsFull())
	{
		body_[++top_index_] = pushed_element;
		return;
	}
	else
	{
		cerr << "The stack is full! \n";
		return;
	}

}

template<typename T>
T ArrayStack<T>::Pop()
{
	if (!IsEmpty())
	{
		return body_[top_index_--];
	}
	else
	{
		cerr << "The stack is empty! \n";
		return -1;
	}
}


template<typename T>
inline int ArrayStack<T>::Length()
{
	return top_index_ + 1;
}

template<typename T>
inline bool ArrayStack<T>::operator==(ArrayStack<T>& rhs)
{
	cout << Length() << rhs.Length();
	if (Length() == rhs.Length()) return 1;
	return 0;
}


template <typename T>
istream & operator>>(istream & is, ArrayStack<T>& st)
{
	int numberElements;
	is >> numberElements;
	T elem;
	for (int i = 0; i < numberElements; i++)
	{
		is >> elem;
		st.Push(elem);
	}
	return is;
}

template <typename T>
ostream & operator<<(ostream & os, ArrayStack<T>& st)
{
	T elem;
	while (!st.IsEmpty())
	{
		elem = st.Pop();
		os << elem << " ";
	}
	os << endl;
	return os;
}

template<typename T>
ifstream& operator>>(ifstream &ifs, ArrayStack<T>& st)
{
	T elem;
	while (ifs >> elem)
	{
		st.Push(elem);
	}
	return ifs;
}

template<typename T>
ofstream& operator<<(ofstream & ofs, ArrayStack<T>& st)
{
	T elem;
	while (!st.IsEmpty())
	{
		elem = st.Pop();
		ofs << elem << " ";
	}
	ofs << endl;
	return ofs;
}

#endif