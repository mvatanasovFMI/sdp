#include "pch.h"
#include <iostream>
#include "QueueLinked.h"

using namespace std;
void QueueLinked::copyQueue(QueueLinked const & queue)
{
	Node *cur1 = NULL, *cur2 = queue.m_front, *new1;
	m_front = NULL;
	for (;;) {
		if (cur2 == NULL) break;
		new1 = new Node;
		new1->m_data = cur2->m_data;
		new1->m_next = NULL;
		if (cur1 == NULL) m_front = cur1 = new1;
		else {
			cur1->m_next = new1;
			cur1 = new1;
		}
		cur2 = cur2->m_next;
	}
	m_rear = cur1;
}

void QueueLinked::deleteQueue()
{
	Node *t;
	for (;;) {
		if (m_front == NULL) break;
		t = m_front; m_front = m_front->m_next;
		delete t;
	}
	m_front = m_rear = NULL;
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
		// TODO some error info
	}

	
	// TODO remove element
}

void QueueLinked::display()
{
	//copy queue and then get all element from the copied queue	
}

void QueueLinked::enqueue(int item)
{
	

	// TODO put element
}

int QueueLinked::peek()
{
	if (isEmpty())
	{
		cout << "The Queue is empty.\n";
		return 0;
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



