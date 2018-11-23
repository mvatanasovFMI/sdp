#include "pch.h"
#include <iostream>
#include "QueueLinked.h"

using namespace std;
void QueueLinked::copyQueue(QueueLinked const & queue)
{

}

void QueueLinked::deleteQueue()
{

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
		cout << "Queue is empty!";
	}
	else
	{
		if (m_front == m_rear)
		{
			delete m_front;
			m_front = m_rear = NULL;
		}
		else
		{
			Node*ptr = m_front;
			m_front = m_front->m_next;
			delete ptr;
		}
	}
	
	// TODO remove element
}

void QueueLinked::display()
{
	QueueLinked ql;
	copyQueue(ql);
	if (ql.isEmpty())
	{
		cout << "The queue is empty";
	}
	else
	{

		Node* ptr = ql.m_front;
		while (ptr != NULL)
		{
			cout << ptr->m_next << " ";
			ptr = ptr->m_next;
		}
	}
	//copy queue and then get all element from the copied queue	
}

void QueueLinked::enqueue(int item)
{
	Node* ptr = new Node();
	ptr->m_data = item;
	ptr->m_next = NULL;
	if (m_front == NULL)
	{
		m_front = ptr;
		m_rear = ptr;
	}
	else
	{
		m_rear->m_next = ptr;
		m_rear = ptr;
	}

	// TODO put element
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
	return m_rear != nullptr;
}



