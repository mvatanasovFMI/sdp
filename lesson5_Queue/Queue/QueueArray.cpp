#include "pch.h"
#include <iostream>
#include "QueueArray.h"

using namespace std;

void QueueArray::copyQueue(QueueArray const & queue)
{

}

void QueueArray::deleteQueue()
{

}

QueueArray::QueueArray(int size)
{
	m_array = new int[size];
	m_capacity = size;
	m_front = 0;
	m_rear = 0;
	m_count = 0;
}

QueueArray::QueueArray(QueueArray const & queue)
{
	copyQueue(queue);
}

QueueArray& QueueArray::operator=(QueueArray const & queue)
{
	if (this != &queue)
	{
		deleteQueue();
		copyQueue(queue);
	}
	return *this;
}

QueueArray::~QueueArray()
{
	deleteQueue();
}

void QueueArray::dequeue()
{
	if (isEmpty())
	{
		// TODO some error info
	}

	cout << "Removing " << m_array[m_front] << '\n';

	// TODO remove element
}

void QueueArray::display()
{
	//copy queue and then get all element from the copied queue	
}

void QueueArray::enqueue(int item)
{
	if (isFull())
	{
		cout << "The Queue is full.\n";
		throw;// TODO some error info
	}

	// TODO put element
}

int QueueArray::peek()
{
	if (isEmpty())
	{
		cout << "The Queue is empty.\n";
		throw;
		// TODO some error info
	}
	return m_array[m_front];
	// TODO get element
}

int QueueArray::size()
{
	return m_count;
	// TODO get all elements m_count
}

bool QueueArray::isEmpty()
{
	return m_count == 0;
}

bool QueueArray::isFull()
{
	return m_capacity == m_count;
}
