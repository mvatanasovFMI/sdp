#ifndef _ARRAY_QUEUE_H_
#define _ARRAY_QUEUE_H_

#include <iostream>
#include <fstream>
#include "queue.h"

using namespace std;

const int MAX_SIZE = 100001;

template <typename T>
class ArrayQueue : public Queue<T>
{
private:
	T arr[MAX_SIZE];
	int front, back;
	int num;
public:
	ArrayQueue();

	void push(const T&);
	bool pop(T&);
	T& top();
	bool isEmpty() const;
	bool isFull() const;
	void print();

	bool operator==(const ArrayQueue<T> &);

	friend istream& operator>>(istream &, ArrayQueue<T> &);
	friend ostream& operator<<(ostream &, ArrayQueue<T> &);

	friend ifstream operator>>(ifstream &, ArrayQueue<T> &);
	friend ofstream operator<<(ofstream &, ArrayQueue<T> &);

};

template<typename T>
ArrayQueue<T>::ArrayQueue() : front(0), back(-1), num(0)
{
}

template<typename T>
void ArrayQueue<T>::push(const T & newElem)
{
	if (!isFull())
	{
		back++;
		back %= MAX_SIZE;
		arr[back] = newElem;
		num++;
	}
}

template<typename T>
bool ArrayQueue<T>::pop(T& poppedVal)
{
	if (isEmpty())
	{
		return false;
	}
	poppedVal = arr[front++];
	num--;
	front %= MAX_SIZE;
	return true;
}

template<typename T>
T & ArrayQueue<T>::top()
{
	if (!isEmpty())
	{
		return arr[front];
	}
//	return T();
}

template<typename T>
bool ArrayQueue<T>::isEmpty() const
{
	return num == 0;
}

template<typename T>
inline bool ArrayQueue<T>::isFull() const
{
	return num == MAX_SIZE;
}

template<typename T>
void ArrayQueue<T>::print()
{
	int tempFront = front;
	int tempNum = num;
	while (!isEmpty())
	{
		T current;
		pop(current);
		cout << current << " ";
	}
	cout << endl;
	front = tempFront;
	num = tempNum;
}

template<typename T>
bool ArrayQueue<T>::operator==(const ArrayQueue<T> & other)
{
	if (num != other.num) return false;
	for (int i = front; i != back; i++)
	{
		if (arr[i] != other.arr[i])
		{
			return false;
		}
		i %= MAX_SIZE;
	}
	return true;
}

template<typename T>
istream& operator>>(istream & is, ArrayQueue<T> & q)
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

template<typename T>
ostream & operator<<(ostream & os, ArrayQueue<T> & q)
{
	T elem;
	ArrayQueue<T> temp = q;
	while (!temp.isEmpty())
	{
		q.pop(elem);
		os << elem << " ";
	}
	os << endl;
	return os;
}

template<typename T>
ifstream operator>>(ifstream &ifs, ArrayQueue<T>& q)
{
	T elem;
	while (ifs >> elem)
	{
		q.push(elem);
	}
	return ifs;
}

template<typename T>
ofstream operator<<(ofstream & ofs, ArrayQueue<T>& q)
{
	ArrayQueue<T> temp = q;
	T elem;
	while (!temp.isEmpty())
	{
		q.pop(elem);
		ofs << elem << " ";
	}
	ofs << endl;
}

#endif // !_ARRAY_QUEUE_H_

