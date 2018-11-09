#include "pch.h"
#include <iostream>
#include "QueueArray.h"

using namespace std;

void QueueArray::copyQueue(QueueArray const & queue)
{
	if (m_capacity < queue.m_capacity) {
		deleteQueue();
		m_array = new int[queue.m_capacity];
	}
	m_capacity = queue.m_capacity;
	m_front = queue.m_front;
	m_rear = queue.m_rear;
	m_count = queue.m_count;
	for (int i = 0; i < m_capacity; i++) {
		m_array[i] = queue.m_array[i];
	}
}

void QueueArray::deleteQueue()
{
	delete[] m_array;
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
		// TODO some error info
		return 0;
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
