#include "pch.h"
#include <iostream>
#include "QueueLinked.h"

using namespace std;
void QueueLinked::copyQueue(QueueLinked const & queue)
{
	Node* temp = queue.m_front;
	while (temp != queue.m_rear)
	{
		enqueue(temp->m_data);
		temp = temp->m_next;
	}
	enqueue(temp->m_data);
}

void QueueLinked::deleteQueue()
{
	Node* temp = m_front;
	while (m_front != NULL)
	{
		m_front = m_front->m_next;
		delete temp;
		temp = m_front;
	}
	m_rear = NULL;
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
		cout << "queue is empty";
	}
	else 
	{
		Node* temp;
		temp = m_front;
		m_front=m_front->m_next;
		delete temp;
		m_count--;
		if (m_count == 0) 
		{
			m_front = m_rear = nullptr;
		}
	}
}

void QueueLinked::display()
{
	Node* temp;
	if (!isEmpty())
	{
		for (temp = m_front; temp != m_rear; temp = temp->m_next)
		{
			cout << temp->m_data << " ";
		}
		cout << m_rear->m_data;
	}
	else cout << "queue is empty";
	}

void QueueLinked::enqueue(int item)
{
	Node* elem = new Node;
	elem->m_data = item;
	m_count++;
	if (isEmpty())
	{
		m_front = m_rear = elem;
	}
	else 
	{
		m_rear->m_next = elem;
		m_rear = elem;
	}
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
	return m_rear = nullptr;
}



