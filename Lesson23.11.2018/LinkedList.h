#pragma once

#include <assert.h>
#include "Iterator.h"

template <class T>
class LinkedList {
private:
	//Item<T> *m_pStart;
	Item<T> *m_pEnd;
	size_t m_size;
	    
private:
	void Initialize();
	Item<T>* FindItemAt(size_t Index) const;
	
	static void Delete(Item<T>* pStart)
	{
		Item<T>* pCurrent = pStart;
		Item<T>* pItemToBeDeleted = pStart;

		while (pCurrent)
		{
			pItemToBeDeleted = pCurrent;
			pCurrent = pCurrent->m_pNext;
			delete pItemToBeDeleted;
		}
	}

	static void Copy(Item<T>* pEnd,Item<T>*& pCloneEnd)
	{
		pEnd = nullptr;
		pCloneEnd = nullptr;

		if (pEnd == nullptr)
			return;

		Item<T>* pNewEnd = nullptr;

		try
		{
			pNewEnd = new Item<T>(pEnd->m_data);

			Item<T>* pNextIterationItem = pEnd->m_pNext;

			Item<T>* pCurrentIterationItem = pNewEnd;
			int counter = 0;
			while (counter!=m_size)
			{
				pCurrentIterationItem->m_pNext = new Item<T>(pNextIterationItem->m_data);
				pCurrentIterationItem = pCurrentIterationItem->m_pNext;
				pNextIterationItem = pNextIterationItem->m_pNext;
				counter++;
			}

			pCloneEnd = pNewEnd;
		}
		catch (std::bad_alloc&)
		{
			Delete(pNewStart);
		}
	}

public:
	LinkedList()
	{
		Initialize();
	}

	LinkedList(LinkedList const & Other)
	{
		Initialize();
		Copy(Other);
	}

	LinkedList& operator= (const LinkedList & Other)
	{
		if (this != &Other)
		{
			Delete();
			Copy(Other);
		}

		return *this;
	}

	~LinkedList()
	{
		Delete();
	}

	bool IsEmpty() const
	{
		return m_size == 0;
	}

	size_t GetSize() const
	{
		return m_size;
	}

	void Delete()
	{
		Delete(m_pEnd);
		Initialize();
	}

	bool Copy(LinkedList<T> const & Other);
	void PushFront(const T & Value);
	void PushBack(T const & Value);
	void PopFront();
	void PopBack();
	T& GetStartData();
	const T& GetStartData() const;
	T& GetEndData();
	const T& GetEndData() const;
	T & At(size_t Index);
	const T & At(size_t Index) const;
	void RemoveAt(size_t Index);
	
	Iterator<T> GetIterator() const
	{
		return Iterator<T>(m_pEnd);
	}
};

template <class T>
void LinkedList<T>::Initialize()
{
	m_pEnd = nullptr;
	m_size = 0;
}

template <class T>
Item<T> * LinkedList<T>::FindItemAt(size_t Index) const
{
	if (Index < 0 || Index >= this->m_size)
		return nullptr;

	Item<T> *p = m_pEnd;

	for (int i = -1; i < Index; ++i)
		p = p->m_pNext;

	return p;
}

template <class T>
bool LinkedList<T>::Copy(LinkedList<T> const & Other)
{
	if (Other.IsEmpty())
		return true;

	Item<T>  *pNewEnd;
	Copy(Other.m_pEnd, pNewEnd);

	if (!pNewEnd)
		return false;

	if (m_size == 0)
		m_pEnd = pNewEnd;
	else
		m_pEnd->m_pNext = pNewEnd;

	m_pEnd = pNewEnd;

	m_size += Other.m_size;

	return pNewEnd != m_pEnd;
}

template <class T>
void LinkedList<T>::PushFront(const T & Value)
{
	Item<T> *pNewItem = new Item<T>(Value, m_pEnd->m_pNext);

	if (IsEmpty())
		m_pEnd = pNewItem;

	m_pEnd->m_pNext = pNewItem;
	++m_size;
}

template <class T>
void LinkedList<T>::PushBack(T const & Value)
{
	Item<T> *pNewItem = new Item<T>(Value);

	if (IsEmpty())
	{
		m_pEnd = pNewItem;
	}
	else
	{
		this->m_pEnd->m_pNext = pNewItem;
		this->m_pEnd = pNewItem;
	}

	++m_size;
}

template <class T>
void LinkedList<T>::PopFront()
{
	if (IsEmpty())
		return;

	Item<T> *pStartItemToBeDeleted = m_pEnd->m_pNext;

	m_pEnd->m_pNext = m_pEnd->m_pNext->m_pNext;

	if (m_pEnd->m_pNext == nullptr)
		m_pEnd = nullptr;

	--m_size;

	delete pStartItemToBeDeleted;
}

template <class T>
void LinkedList<T>::PopBack()
{
	if (!IsEmpty())
		RemoveAt(m_size - 1);
}

template <class T>
T& LinkedList<T>::GetStartData()
{
	if (m_size == 0)
		throw std::exception();

	return m_pEnd->m_pNext->m_data;
}

template <class T>
const T& LinkedList<T>::GetStartData() const
{
	return const_cast<LinkedList<T>*>(this)->GetStartData();
}

template <class T>
T& LinkedList<T>::GetEndData()
{
	if (m_size == 0)
		throw std::exception();

	return m_pEnd->m_data;
}

template <class T>
const T& LinkedList<T>::GetEndData() const
{
	return const_cast<LinkedList<T>*>(this)->GetEndData();
}

template <class T>
T & LinkedList<T>::At(size_t Index)
{
	if (Index >= m_size)
		throw std::out_of_range("Index exceeded the size");

	return FindItemAt(Index)->m_data;
}

template <class T>
const T & LinkedList<T>::At(size_t Index) const
{
	if (Index >= m_size)
		throw std::out_of_range("Index exceeded the size");

	return FindItemAt(Index)->m_data;
}

template <class T>
void LinkedList<T>::RemoveAt(size_t Index)
{
	if (Index >= m_size)
		throw std::out_of_range("Index exceeded the size");

	if (Index == 0)
	{
		PopFront();
	}
	else
	{
		assert(this->GetSize() >= 2);

		Item<T> *pItemBeforeIndex = FindItemAt(Index - 1);

		assert(pItemBeforeIndex != nullptr);

		Item<T> *pItemToBeDeletedAtIndex = pItemBeforeIndex->m_pNext;

		if (Index == m_size - 1)
			m_pEnd = pItemBeforeIndex;

		pItemBeforeIndex->m_pNext = pItemToBeDeletedAtIndex->m_pNext;

		delete pItemToBeDeletedAtIndex;

		--m_size;
	}
}
