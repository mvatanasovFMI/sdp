#ifndef LINKEDQUEUE_H_
#define LINKEDQUEUE_H_
#include <iostream>
#include <cassert>
#include "DataStructures.h"

using namespace std;

template<typename T>
class LinkedQueue : public DataStructure<T>
{
private:
	Node<T>* front_;
	Node<T>* rear_;
	void CopyQueue(const LinkedQueue<T>&);
	void DeleteQueue();
public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue<T>&);
	LinkedQueue<T> operator=(const LinkedQueue<T>&);
	~LinkedQueue();

	void Push(T);
	T Pop();
	T Top();
	bool IsEmpty() const;
	bool IsFull() const;//фиктивна функция, колкото да дефинира виртуалната функция от базовия си клас;
						//ясно е, че този вид стек по дефиниция не може да бъде пълен, затова тази функция винаги връща 0;

	int Length();

	bool operator==(LinkedQueue<T>&);
};

template<typename T>
inline void LinkedQueue<T>::CopyQueue(const LinkedQueue<T>& rhs)
{
	front_ = rear_ = nullptr;
	Node<T>* temp = rhs.front_;
	while (temp)
	{
		Push(temp->data_);
		temp = temp->next_;
	}
}

template<typename T>
inline void LinkedQueue<T>::DeleteQueue()
{
	while (!IsEmpty())
	{
		Pop();
	}
}

template<typename T>
inline LinkedQueue<T>::LinkedQueue()
{
	front_ = rear_ = nullptr;
}

template<typename T>
inline LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& rhs)
{
	CopyQueue(rhs);
}

template<typename T>
inline LinkedQueue<T> LinkedQueue<T>::operator=(const LinkedQueue<T>& rhs)
{
	if (this != &rhs)
	{
		DeleteQueue();
		CopyQueue(rhs);
	}
	return *this;
}

template<typename T>
inline LinkedQueue<T>::~LinkedQueue()
{
	DeleteQueue();
}

template<typename T>
inline void LinkedQueue<T>::Push(T elem)
{
	Node<T>* newElem = new Node<T>;
	assert(newElem != nullptr);
	newElem->data_ = elem;
	if (rear_ == nullptr)
	{
		front_ = newElem;
	}
	else
	{
		rear_->next_ = newElem;
	}
	rear_ = newElem;
}

template<typename T>
inline T LinkedQueue<T>::Pop()
{
	if (IsEmpty())
	{
		cerr << "The queue is empty! \n" << endl;
		return -1;
	}
	else
	{
		Node<T>* temp = front_;
		T elem = temp->data_;
		if (rear_ == front_)
		{
			rear_ = front_ = nullptr;
		}
		else
		{
			front_ = front_->next_;
		}
		delete temp;
		return elem;
	}
}

template<typename T>
inline T LinkedQueue<T>::Top()
{
	if (IsEmpty())
	{
		cerr << "The queue is empty! \n" << endl;
		return -1;
	}
	else
	{
		T elem = front_->data_;
		return elem;
	}
}

template<typename T>
inline bool LinkedQueue<T>::IsEmpty() const
{
	return rear_ == nullptr;
}

template<typename T>
inline bool LinkedQueue<T>::IsFull() const
{
	return false;
}



template<typename T>
inline int LinkedQueue<T>::Length()
{
	int n = 0;
	T x;
	while (!IsEmpty())
	{
		Pop();
		n++;
	}
	return n;
}

template<typename T>
inline bool LinkedQueue<T>::operator==(LinkedQueue<T>&rhs)
{
	if (Length() == rhs.Length()) return 1;
	return 0;
}


template <typename T>
istream & operator>>(istream & is, LinkedQueue<T>& st)
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
ostream & operator<<(ostream & os, LinkedQueue<T>& st)
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
ifstream& operator>>(ifstream &ifs, LinkedQueue<T>& st)
{
	T elem;
	while (ifs >> elem)
	{
		st.Push(elem);
	}
	return ifs;
}

template<typename T>
ofstream& operator<<(ofstream & ofs, LinkedQueue<T>& st)
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