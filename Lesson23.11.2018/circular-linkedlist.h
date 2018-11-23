#ifndef _CIRCULAR_LINKEDLIST_H_
#define _CIRCULAR_LINKEDLIST_H_

#include "iterator.h"


template <typename T>
class CircularLinkedList
{
private:
	Item<T>* m_end;
	size_t m_size;

	void initialize() {
		m_end = nullptr;
		m_size = 0;
	}

	Item<T>* findItemAt(size_t index) const;

	static void deleteElements(Item<T>* pEnd) {
		Item<T>* next = pEnd->m_pNext;
		Item<T>* tempPtr;
		while (next != pEnd) {
			tempPtr = next;
			next = next->m_pNext;
			delete tempPtr;
		}
	}

	static void copy(Item<T>* pEnd, Item<T>*& pClonedEnd) {
		pClonedEnd = nullptr;

		if (pEnd == nullptr) {
			return;
		}

		Item<T>* pClonedEnd = new Item<T>(pEnd->m_data);

		Item<T>* pNextIterationItem = pEnd->m_pNext;
		Item<T>* pCurrentIterationItem = pClonedEnd;

		while (pNextIterationItem != pEnd) {
			pCurrentIterationItem->m_pNext = new Item<T>(pNextIterationItem->m_data);
			pCurrentIterationItem = pCurrentIterationItem->m_pNext;
			pNextIterationItem = pNextIterationItem->m_pNext;
		}
		pCurrentIterationItem->m_pNext = pClonedEnd;
	}


public:
	CircularLinkedList() {
		initialize();
	}

	CircularLinkedList(const CircularLinkedList<T>& other) {
		initialize();
		copy(other);
	}

	CircularLinkedList& operator=(const CircularLinkedList<T>& other) {
		if (&other != this) {
			Delete();
			copy(other);
		}

		return *this;
	}

	CircularLinkedList() {
		Delete();
	}

	bool isEmpty() const {
		return m_size == 0;
	}

	size_t getSize() const {
		return m_size;
	}

	void Delete() {
		deleteElements(m_end);
		initialize();
	}

	bool copy(const CircularLinkedList<T>& other);
	void insertToEnd(const T&);
	void deleteEnd();
	T& getEndData() const;
	T& getIndexElement(const size_t) const;
	void removeElementAdIndex(const size_t) const;
	Iterator<T> getIterator() const {
		return Iterator<T>(m_end);
	}
};

template<typename T>
Item<T>* CircularLinkedList<T>::findItemAt(size_t index) const
{
	
}

template<typename T>
bool CircularLinkedList<T>::copy(const CircularLinkedList<T>& other)
{
	if (other.isEmpty()) {
		return true;
	}

	Item<T>* pNewEnd;

	copy(other.m_end, pNewEnd);

	if (!pNewEnd) {
		return false;
	}
	m_size = other.m_size;
	return true;
}

template<typename T>
void CircularLinkedList<T>::insertToEnd(const T& element)
{
	if (m_end) {
		Item<T>* nextElement = m_end->m_pNext;
		Item<T>* newElement = new Item<T>(element, nextElement);
		m_end->m_pNext = newElement;
	}
	m_end = new Item<T>(element, m_end);
}

template<typename T>
void CircularLinkedList<T>::deleteEnd()
{
	if (!m_end) {
		return;
	}
	Item<T>* previousPointer = m_end;
	Item<T>* nextPoiter = m_end->m_pNext;
	while (previousPointer->m_pNext != m_end) {
		previousPointer = previousPointer->m_pNext;
	}
	if (previousPointer == nextPoiter) {
		delete m_end;
		m_end = nullptr;
	}
	else {
		previousPointer->m_pNext = nextPointer;
		delete m_end;
	}
}

template<typename T>
T & CircularLinkedList<T>::getEndData() const
{
	if (m_end) {
		return m_end->m_data;
	}
}

template<typename T>
T & CircularLinkedList<T>::getIndexElement(const size_t index) const
{
	size_t counter = 0;
	if (m_end) {
		Item<T>* tempPointer = m_end;
		while (counter != index) {
			tempPointer = tempPointer->m_pNext;
			counter++;
		}
		return tempPointer->m_data;
	}
}

template<typename T>
void CircularLinkedList<T>::removeElementAdIndex(const size_t index) const
{
	if (m_end) {
		if (index == 0) {
			deleteEnd();
			return;
		}
		Item<T>* targetPointer = m_end;
		Item<T>* previousPointer = m_end;
		size_t counter = 0;
		while (counter != index) {
			previousPointer = targetPointer;
			targetPointer = targetPointer->m_pNext;
			counter++;
		}
		previousPointer->m_pNext = targetPointer->m_pNext;
		delete targetPointer;
	}
}


#endif // !_CIRCULAR_LINKEDLIST_H_
