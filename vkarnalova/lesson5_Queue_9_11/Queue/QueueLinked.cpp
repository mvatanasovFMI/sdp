#include "pch.h"
#include <iostream>
#include <cassert>
#include "QueueLinked.h"

using namespace std;
void QueueLinked::copyQueue(QueueLinked const & queue)
{
	m_front = m_rear = nullptr;
	Node* temp_ptr = queue.m_front;
	while (temp_ptr) {
		enqueue(temp_ptr->m_data);
		temp_ptr = temp_ptr->m_next;
	}
}

void QueueLinked::deleteQueue()
{
	while (!isEmpty()) {
		dequeue();
	}
}

QueueLinked::QueueLinked(QueueLinked const & queue)
{
	copyQueue(queue);
}

QueueLinked& QueueLinked::operator=(QueueLinked const & queue)
{
	if (this != &queue)
	{
		deleteQueue();
		copyQueue(queue);
	}
	return *this;
}

QueueLinked::~QueueLinked()
{
	deleteQueue();
}

void QueueLinked::dequeue()
{
	if (isEmpty())
	{
		cerr << "Empty stack!";
	}
	else {
		Node* temp_ptr = m_front;
		int temp_inf = temp_ptr->m_data;
		if (temp_ptr == m_rear) {
			m_front = m_rear = NULL;
			m_count--;
		}
		else {
			m_front = m_front->m_next;
		    delete temp_ptr;
			m_count--;
		}
	}
}

void QueueLinked::display()
{
	//copy queue and then get all element from the copied queue	
	QueueLinked copy_queue = *this;
	while (!copy_queue.isEmpty()) {
		cout << copy_queue.peek() << endl;
		copy_queue.dequeue();
	}
}

void QueueLinked::enqueue(int item)
{
	// TODO put element
	Node* temp_elem = new Node;
	if (temp_elem)
	temp_elem->m_data = item;
	temp_elem->m_next = NULL;
	if (m_rear) {
		m_rear->m_next = temp_elem;
	}
	else {
		m_front = temp_elem;
	}
	m_rear = temp_elem;
}

int QueueLinked::peek()
{
	if (isEmpty())
	{
		cout << "The Queue is empty.\n";
		throw;
		// TODO some error info
	}
	return m_front->m_data;
	// TODO get element
}

int QueueLinked::size()
{
	return m_count;
	// TODO get all elements m_count
}

bool QueueLinked::isEmpty()
{
	return m_rear == nullptr;
}



