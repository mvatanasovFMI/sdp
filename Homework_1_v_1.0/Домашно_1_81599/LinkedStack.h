#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_
#include <iostream>
#include <cassert>
#include "DataStructures.h"

using namespace std;

template <typename T>
class LinkedStack : public DataStructure<T>
{
private:
	Node<T>* start_;
	void CopyStack(const LinkedStack<T>&);
	void DeleteStack();
public:
	LinkedStack();
	LinkedStack(const LinkedStack<T>&);
	LinkedStack<T>& operator=(const LinkedStack<T>&);
	~LinkedStack();

	void Push(T);
	T Pop();
	T Top();

	bool IsEmpty() const;
	bool IsFull() const;//A fictitious function; it sipmly defines the respective virtual function from the basic class;
			    //clearly a linked stack cannot be full, so it returns 0 by default;

	int Length();

	bool operator==(LinkedStack<T>&);

};

template<typename T>
inline void LinkedStack<T>::CopyStack(const LinkedStack<T>& rhs)
{
	if (rhs.start_)
	{
		Node<T>* rhs_pointer = rhs.start_;
		Node<T>* helper = nullptr;
		Node<T>* new_elem = nullptr;
		start_ = new Node<T>;
		assert(start_ != nullptr);
		start_->data_ = rhs_pointer->data_;
		start_->next_ = helper;
		helper = start_;
		rhs_pointer = rhs_pointer->next_;
		while (rhs_pointer)
		{
			new_elem = new Node<T>;
			assert(new_elem != nullptr);
			new_elem->data_ = rhs_pointer->data_;
			helper->next_ = new_elem;
			helper = new_elem;
			rhs_pointer = rhs_pointer->next_;
		}
		helper->next_ = nullptr;
	}
	else start_ = nullptr;

}

template<typename T>
inline void LinkedStack<T>::DeleteStack()
{
	while (!IsEmpty())
	{
		Node<T>* temp = start_;
		start_ = start_->next_;
		delete temp;
	}
}

template<typename T>
inline LinkedStack<T>::LinkedStack()
{
	start_ = nullptr;
}

template<typename T>
inline LinkedStack<T>::LinkedStack(const LinkedStack<T>& rhs)
{
	CopyStack(rhs);
}

template<typename T>
inline LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& rhs)
{
	if (this != &rhs)
	{
		DeleteStack();
		CopyStack(rhs);
	}
	return *this;
}

template<typename T>
inline LinkedStack<T>::~LinkedStack()
{
	DeleteStack();
}

template<typename T>
inline void LinkedStack<T>::Push(T  pushed_element)
{
	Node<T>* temp = start_;
	start_ = new Node<T>;
	assert(start_ != nullptr);
	start_->next_ = temp; 
	start_->data_ = pushed_element;
}

template<typename T>
inline T LinkedStack<T>::Pop()
{
	if (start_ != nullptr)
	{
		Node<T>* temp = start_;
		start_ = start_->next_;
		T popped_elem = temp->data_;
		delete temp; 
		return popped_elem;
	}
	else
	{
		cerr << "The stack is empty! \n";
		return -1;
	}
}

template<typename T>
inline T LinkedStack<T>::Top()
{
	if (start_)
	{
	return start_->data_;
	}
	else
	{
		cerr << "The stack is empty! \n";
		exit(1);
	}
	
}

template<typename T>
inline bool LinkedStack<T>::IsEmpty() const
{
	return start_ == nullptr;
}

template<typename T>
inline bool LinkedStack<T>::IsFull() const
{
	return false;
}

template<typename T>
inline int LinkedStack<T>::Length()
{
	int length = 0;
	while (!IsEmpty())
	{
		Pop();
		length++;
	}
	return length;
}

template<typename T>
inline bool LinkedStack<T>::operator==(LinkedStack<T>& rhs)
{
	if (Length() == rhs.Length()) return 1;
	return 0;
}

template <typename T>
istream & operator>>(istream & is, LinkedStack<T>& st)
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
ostream & operator<<(ostream & os, LinkedStack<T>& st)
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
ifstream& operator>>(ifstream &ifs, LinkedStack<T>& st)
{
	T elem;
	while (ifs >> elem)
	{
		st.Push(elem);
	}
	return ifs;
}

template<typename T>
ofstream& operator<<(ofstream & ofs, LinkedStack<T>& st)
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
