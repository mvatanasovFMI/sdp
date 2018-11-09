#include "pch.h"
#include <iostream>
#include <cassert>
#include "QueueLinked.h"

using namespace std;
void QueueLinked::copyQueue(QueueLinked const & queue)
{
	m_front = m_rear = NULL;
	Node* p = queue.m_front;
	while (p) {
		enqueue(p->m_data);
		p = p->m_next;
	}
}

void QueueLinked::deleteQueue()
{
	while (!isEmpty()) { dequeue(); }
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
		cerr << "The queue is empty!\n";
		// TODO some error info
	}
	Node* p = m_front;
	//cout << "Removing " << p->m_data << endl;
	if (p == m_rear) {
		m_rear = NULL;
		m_front = NULL;
	}
	else m_front = p->m_next;
	delete p;
	
	// TODO remove element
}

void QueueLinked::display()
{
	//copy queue and then get all element from the copied queue	
	QueueLinked temp = *this;
	while (!temp.isEmpty()) {
		cout << temp.peek() << endl;
		temp.dequeue();
	}
}

void QueueLinked::enqueue(int item)
{
	
	Node* p = new Node;
	assert(p != NULL);
	p->m_data = item;
	p->m_next = NULL;
	if (m_rear) m_rear->m_next = p;
	else m_front = p;
	m_rear = p;
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
	return m_rear == nullptr;
}



