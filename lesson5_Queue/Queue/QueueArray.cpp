#include "pch.h"
#include <iostream>
#include "QueueArray.h"

using namespace std;

void QueueArray::copyQueue(QueueArray const & queue)
{
	m_array = new int[queue.m_capacity];
	m_capacity = queue.m_capacity;
	m_count = queue.m_count;

	for (int i = 0; i < m_count; i++)
	{
		m_array[i] = queue.m_array[i];
	}

	m_front = queue.m_front;
	m_rear = queue.m_rear;
}

void QueueArray::deleteQueue()
{
	delete[] m_array;
	m_front = 0;
	m_rear = 0;
	m_count = 0;
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
		cout << "queue is empty";
	}

	else {
		cout << "Removing " << m_array[m_front] << '\n';

		int* temp = new int[m_count - 1];

		for (int i = 1; i < m_count; i++)
		{
			temp[i - 1] = m_array[i];
		}
		m_count--;
		delete[]m_array;
		m_array = new int[m_capacity];
		for (int i = 0; i < m_count; i++)
		{
			m_array[i] = temp[i];
		}

		m_front = 0;
		m_rear = m_count - 1;
	}
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

	int* temp = new int[m_count + 1];

	for (int i = 0; i < m_count; i++)
	{
		temp[i] = m_array[i];
	}
	temp[m_count] = item;
	m_count++;
	delete[]m_array;
	m_array = new int[m_capacity];
	for (int i = 0; i < m_count; i++)
	{
		m_array[i] = temp[i];
	}

	m_front = 0;
	m_rear = m_count - 1;
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
