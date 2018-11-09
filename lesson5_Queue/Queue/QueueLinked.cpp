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



