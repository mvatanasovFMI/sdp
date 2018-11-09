#include "pch.h"
#include <iostream>
#include "QueueLinked.h"

using namespace std;

void QueueLinked::copyQueue(QueueLinked const & queue) {
	if (queue.m_front == NULL) {
		m_front = NULL;
		m_rear = NULL;
	} else {
		Node* current = new Node;
		current->m_data = queue.m_front->m_data;
		m_front = current;

		for (Node* otherCurrent = queue.m_front;
			otherCurrent->m_next != NULL;
			otherCurrent = otherCurrent->m_next) {
			Node* node = new Node;
			node->m_data = otherCurrent->m_next->m_data;
			current->m_next = node;

			current = current->m_next;
		}

		current->m_next = NULL;
	}
}

void QueueLinked::deleteQueue() {
	while (m_front != NULL) {
		Node* tmp = m_front;
		m_front = m_front->m_next;
		delete tmp;
	}

	m_rear = NULL;
}

QueueLinked::QueueLinked(QueueLinked const & queue) {
	copyQueue(queue);
}

QueueLinked& QueueLinked::operator=(QueueLinked const & queue) {
	if (this != &queue)
	{
		deleteQueue();
		copyQueue(queue);
	}

	return *this;
}

QueueLinked::~QueueLinked() {
	deleteQueue();
}

void QueueLinked::dequeue() {
	Node* tmp = m_front;

	if (m_front == NULL)
		return;

	if (m_front == m_rear) {
		m_front = NULL;
		m_rear = NULL;
	} else {
		m_front = m_front->m_next;
	}

	delete tmp;
}

void QueueLinked::display() {
	//copy queue and then get all element from the copied queue	
}

void QueueLinked::enqueue(int item) {
	Node* newNode = new Node;
	newNode->m_data = item;
	newNode->m_next = NULL;

	if (isEmpty()) {
		m_front = newNode;
		m_rear = newNode;
		return;
	}

	m_rear->m_next = newNode;
	m_rear = newNode;
}

int QueueLinked::peek() {
	if (isEmpty()) {
		cerr << "The Queue is empty.\n" << endl;
		throw;
	}

	return m_front->m_data;
}

int QueueLinked::size() {
	return m_count;
}

bool QueueLinked::isEmpty() {
	return m_rear == nullptr;
}