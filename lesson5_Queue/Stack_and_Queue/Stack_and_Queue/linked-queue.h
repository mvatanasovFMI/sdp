#ifndef _LINKED_QUEUE_H_
#define _LINKED_QUEUE_H_

#include <iostream>
#include <fstream>
#include "queue.h"

using namespace std;

template <typename T>
struct QueueNode
{
	T data;
	QueueNode* next;
};

template <typename T>
class LinkedQueue : public Queue<T>
{
private:
	QueueNode<T>* front;
	QueueNode<T>* back;

	void copyQueue(const LinkedQueue&);
	void deleteQueue();

public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue&);
	LinkedQueue<T>& operator=(const LinkedQueue&);
	~LinkedQueue();

	void push(const T&);
	bool pop(T&);
	T& top();
	bool isEmpty() const;
	void print();

	bool operator==(const LinkedQueue<T> &);

	friend istream& operator>><T>(istream &, LinkedQueue<T> &);
	friend ostream& operator<<<T>(ostream &, LinkedQueue<T> &);

	friend ifstream& operator>><T>(ifstream &, LinkedQueue<T> &);
	friend ofstream& operator<<<T>(ofstream &, LinkedQueue<T> &);
};

template<typename T>
bool LinkedQueue<T>::isEmpty() const
{
	return back == nullptr;
}

template<typename T>
void LinkedQueue<T>::copyQueue(const LinkedQueue & other)
{
	front = back = nullptr;
	if (!other.isEmpty())
	{
		front = back = new QueueNode<T>();
		back->data = other.front->data;
		QueueNode<T>* otherCurr = other.front->next;
		QueueNode<T>* temp;
		while (otherCurr != nullptr)
		{
			temp = new QueueNode<T>();
			temp->data = otherCurr->data;
			back->next = temp;
			otherCurr = otherCurr->next;
			back = back->next;
		}
	}
}

template<typename T>
void LinkedQueue<T>::deleteQueue()
{
	QueueNode<T> *temp;
	while (front)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
	back = nullptr;
}

template<typename T>
LinkedQueue<T>::LinkedQueue() : front(nullptr), back(nullptr)
{
}

template<typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue & other)
{
	copyQueue(other);
}


template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue & other)
{
	if (this != &other)
	{
		deleteQueue();
		copyQueue(other);
	}
	return *this;
}

template<typename T>
LinkedQueue<T>::~LinkedQueue()
{
	deleteQueue();
}

template<typename T>
void LinkedQueue<T>::push(const T & newElem)
{
	QueueNode<T>* temp = new QueueNode<T>();
	temp->data = newElem;
	temp->next = nullptr;
	if (isEmpty())
	{
		front = back = temp;
	}
	else
	{
		back->next = temp;
		back = temp;
	}
}

template<typename T>
bool LinkedQueue<T>::pop(T & value)
{
	if (!isEmpty())
	{
		QueueNode<T>* temp = front;
		value = temp->data;
		front = front->next;
		delete temp;
		return true;
	}
	return false;
}

template<typename T>
T & LinkedQueue<T>::top()
{
	if (!isEmpty())
	{
		return front->data;
	}
	//	return T();
}

template<typename T>
void LinkedQueue<T>::print()
{
	QueueNode<T> *temp = front;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<typename T>
bool LinkedQueue<T>::operator==(const LinkedQueue<T>& other)
{
	QueueNode<T>* first = front;
	QueueNode<T>* second = other.front;
	while (first && second)
	{
		if (first->data != second->data)
		{
			return false;
		}
		first = first->next;
		second = second->next;
	}
	return (!first && !second);
}

template <typename T>
istream& operator>>(istream & is, LinkedQueue<T> & q)
{
	int numberElements;
	is >> numberElements;
	T elem;
	for (int i = 0; i < numberElements; i++)
	{
		is >> elem;
		q.push(elem);
	}
	return is;
}

template <typename T>
ostream& operator<<(ostream & os, LinkedQueue<T> & q)
{
	QueueNode<T>* ptr = q.front;
	while (ptr)
	{
		os << ptr->data << " ";
		ptr = ptr->next;
	}
	os << endl;
	return os;
}

template <typename T>
ifstream& operator>>(ifstream & ifs, LinkedQueue<T> & q)
{
	T elem;
	while (ifs >> elem)
	{
		q.push(elem);
	}
	return ifs;
}

template <typename T>
ofstream& operator<<(ofstream & ofs, LinkedQueue<T> & q)
{
	QueueNode<T>* ptr = q.front;
	while (ptr)
	{
		ofs << ptr->data << " ";
		ptr = ptr->next;
	}
	ofs << endl;
	return ofs;
}


#endif // !_LINKED_QUEUE_H_

