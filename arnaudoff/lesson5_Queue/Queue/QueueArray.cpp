#include "pch.h"
#include <iostream>
#include "QueueArray.h"

using namespace std;

void QueueArray::copyQueue(QueueArray const & queue) {
	m_capacity = queue.m_capacity;
	m_front = queue.m_front;
	m_rear = queue.m_rear;
	m_count = queue.m_count;

	m_array = new int[m_capacity];
	for (int i = 0; i < m_capacity; i++) {
		m_array[i] = queue.m_array[i];
	}
}

void QueueArray::deleteQueue() {
	delete m_array;
}

QueueArray::QueueArray(int size) {
	m_array = new int[size];
	m_capacity = size;
	m_front = -1;
	m_rear = -1;
	m_count = 0;
}

QueueArray::QueueArray(QueueArray const & queue) {
	copyQueue(queue);
}

QueueArray& QueueArray::operator=(QueueArray const & queue) {
	if (this != &queue)
	{
		deleteQueue();
		copyQueue(queue);
	}

	return *this;
}

QueueArray::~QueueArray() {
	deleteQueue();
}

void QueueArray::dequeue() {
	if (isEmpty()) {
		cerr << "dequing from an empty queue" << endl;
		return;
	} else if (m_front == m_rear) {
		m_front = -1;
		m_rear = -1;
	} else {
		m_front = (m_front + 1) % m_capacity;
	}

	cout << "Removing " << m_array[m_front] << '\n';
}

void QueueArray::display() {
	QueueArray queue = *this;

	for (int i = 0; i < queue.m_count; i++) {
		cout << m_array[i] << endl;
	}
}

void QueueArray::enqueue(int item) {
	if (isFull()) {
		cerr << "queue is full.." << endl;
		return;
	} else if (isEmpty()) {
		m_front = 0;
		m_rear = 0;
	} else {
		m_rear = (m_rear + 1) % m_capacity;
	}
	
	m_array[m_rear] = item;
	m_count++;
}

int QueueArray::peek() {
	if (isEmpty()) {
		cerr << "The Queue is empty.\n" << endl;
		throw;
	}

	return m_array[m_front];
}

int QueueArray::size() {
	return m_count;
}

bool QueueArray::isEmpty() {
	return m_count == 0;
}

bool QueueArray::isFull() {
	return m_capacity == m_count;
}
