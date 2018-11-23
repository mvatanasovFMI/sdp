#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_
#include <iostream>
#include <cassert>
#include "DataStructures.h"

using namespace std;

const int kMaxSize = 16;

template <typename T>
class ArrayQueue : public DataStructure<T>
{
private:
	T* body_;
	int queue_size_,
		queue_length_,
		front_,
		rear_;
	void CopyQueue(const ArrayQueue<T>&);
	void DeleteQueue();
public:
	ArrayQueue(int = kMaxSize);
	ArrayQueue(const ArrayQueue<T>&);
	ArrayQueue<T>& operator=(const ArrayQueue<T>&);
	~ArrayQueue();

	void Push(T);
	T Pop();
	T Top();

	bool IsEmpty() const;
	bool IsFull() const;

	int Length();

	bool operator==(ArrayQueue<T>&);
};


template<typename T>
inline void ArrayQueue<T>::CopyQueue(const ArrayQueue<T>& rhs)
{
	queue_size_ = rhs.queue_size_;
	queue_length_ = rhs.queue_length_;
	body_ = new T[queue_size_];
	assert(body_ != nullptr);
	for (int i = 0; i < queue_size_; i++)
	{
		body_[i] = rhs.body_[i];
	}
	front_ = rhs.front_;
	rear_ = rhs.rear_;
}

template<typename T>
inline void ArrayQueue<T>::DeleteQueue()
{
	delete[] body_;
}

template<typename T>
inline ArrayQueue<T>::ArrayQueue(int size)
{
	if (size <= 0) queue_size_ = kMaxSize;
	else
	{
		queue_size_ = size;
	}

	body_ = new T[queue_size_];
	assert(body_ != nullptr);
	queue_length_ = 0;
	front_ = 0;
	rear_ = 0;
}

template<typename T>
inline ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& rhs)
{
	CopyQueue(rhs);
}

template<typename T>
inline ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rhs)
{
	if (this != &rhs)
	{
		DeleteQueue();
		CopyQueue(rhs);
	}
	return *this;
}

template<typename T>
inline ArrayQueue<T>::~ArrayQueue()
{
	DeleteQueue();
}

template<typename T>
inline void ArrayQueue<T>::Push(T  pushed_element)
{
	if (!IsFull())
	{
		body_[rear_] = pushed_element;
		rear_++;
		queue_length_++;
		rear_ = rear_ % queue_size_;
	}
	else
	{
		cerr << "The queue is full! \n";
	}
}

template<typename T>
inline T ArrayQueue<T>::Pop()
{
	if (!IsEmpty())
	{
		T popped_element = body_[front_];
		queue_length_--;
		front_++;
		front_ = front_ % queue_size_;
		return popped_element;
	}
	else
	{
		cerr << "The queue is empty! \n";
		return -1;
	}
}

template<typename T>
inline T ArrayQueue<T>::Top() 
{
	if (!IsEmpty())
	{
		return body_[front_];
	}
	else
	{
		cerr << "The queue is empty! \n";
		return -1;
	}
}

template<typename T>
inline bool ArrayQueue<T>::IsEmpty() const
{
	return queue_length_ == 0;
}

template<typename T>
inline bool ArrayQueue<T>::IsFull() const
{
	return queue_length_ == queue_size_;
}


template<typename T>
inline int ArrayQueue<T>::Length()
{
	return queue_length_;
}

template<typename T>
inline bool ArrayQueue<T>::operator==(ArrayQueue<T>& rhs)
{
	if (Length() == rhs.Length()) return 1;
	return 0;
}

template <typename T>
istream & operator>>(istream & is, ArrayQueue<T>& st)
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
ostream & operator<<(ostream & os, ArrayQueue<T>& st)
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
ifstream& operator>>(ifstream &ifs, ArrayQueue<T>& st)
{
	T elem;
	while (ifs >> elem)
	{
		st.Push(elem);
	}
	return ifs;
}

template<typename T>
ofstream& operator<<(ofstream & ofs, ArrayQueue<T>& st)
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