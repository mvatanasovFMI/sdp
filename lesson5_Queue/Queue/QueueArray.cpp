#include "pch.h"
#include <iostream>
#include <cassert>
#include "QueueArray.h"

using namespace std;

void QueueArray::copyQueue(QueueArray const & queue)
{
	
	m_capacity = queue.m_capacity;
	m_array = new int[m_capacity];
	assert(m_array != NULL);
	for (int i = 0; i < m_capacity; i++) {
		m_array[i] = queue.m_array[i];
	}
	m_count = queue.m_count;
	m_rear = queue.m_rear;
	m_front = queue.m_front;
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
		cerr << "The queue is empty!\n";
	}
	else {
	cout << "Removing " << m_array[m_front] << '\n';
	m_count--;
	m_front++;
	m_front = m_front % m_capacity;
	// TODO remove element
	}
}

void QueueArray::display()
{
	//copy queue and then get all element from the copied queue	
	QueueArray temp = *this;
	while (!temp.isEmpty()) {
		cout << temp.peek() << endl;
		temp.dequeue();
	}
}

void QueueArray::enqueue(int item)
{
	if (isFull())
	{
		cout << "The Queue is full.\n";
		throw;// TODO some error info
	}
	m_array[m_rear] = item;
	m_count++;
	m_rear++;
	m_rear = m_rear % m_capacity;
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
