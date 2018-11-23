#pragma once
#include "Iterator.h"
#include <assert.h>


template <class T>
class CyclicList {
private:
	Item<T> *m_pStart;
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
		m_pStart = NULL;
	}

	static void Copy(Item<T>* pStart,Item<T>*& pCloneStart)
	{
		pCloneStart = nullptr;
		//pCloneEnd = nullptr;

		if (pStart == nullptr)
			return;

		Item<T>* pNewStart = nullptr;

		try
		{
			pNewStart = new Item<T>(pStart->m_data);

			Item<T>* pNextIterationItem = pStart->m_pNext;

			Item<T>* pCurrentIterationItem = pNewStart;

			while (pNextIterationItem!=pStart)
			{
				pCurrentIterationItem->m_pNext = new Item<T>(pNextIterationItem->m_data);
				pCurrentIterationItem = pCurrentIterationItem->m_pNext;
				pNextIterationItem = pNextIterationItem->m_pNext;
			}
			pCurrentIterationItem = pNewStart;
			pCloneStart = pNewStart;
			//pCloneEnd = pCurrentIterationItem;
		}
		catch (std::bad_alloc&)
		{
			Delete(pNewStart);
		}
	}

public:
	CyclicList()
	{
		Initialize();
	}

	CyclicList(CyclicList const & Other)
	{
		Initialize();
		Copy(Other);
	}

	CyclicList& operator= (const CyclicList & Other)
	{
		if (this != &Other)
		{
			Delete();
			Copy(Other);
		}

		return *this;
	}

	~CyclicList()
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
		Delete(m_pStart);
		Initialize();
	}

	bool Copy(CyclicList<T> const & Other);
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
		return Iterator<T>(m_pStart);
	}
};

template <class T>
void CyclicList<T>::Initialize()
{
	m_pStart = nullptr;
	m_size = 0;
}

template <class T>
Item<T> * CyclicList<T>::FindItemAt(size_t Index) const
{
	if (Index < 0 || Index >= this->m_size)
		return nullptr;

	Item<T> *p = m_pStart;

	for (int i = 0; i < Index; ++i)
		p = p->m_pNext;

	return p;
}

template <class T>
bool CyclicList<T>::Copy(CyclicList<T> const & Other)
{
	if (Other.IsEmpty())
		return true;

	Item<T> *pNewStart, ;
	Copy(Other.m_pStart, pNewStart);

	if (!pNewStart)
		return false;

	if (m_size == 0)
		m_pStart = pNewStart;
	//else
		//m_pEnd->m_pNext = pNewStart;

	//m_pEnd = pNewEnd;

	m_size += Other.m_size;

	return pNewStart != nullptr;
}

template <class T>
void CyclicList<T>::PushFront(const T & Value)
{
	Item<T> *pNewItem = new Item<T>(Value, m_pStart);

	//if (IsEmpty())
	
		//m_pEnd = pNewItem;

	m_pStart = pNewItem;
	++m_size;
}

template <class T>
void CyclicList<T>::PushBack(T const & Value)
{
	Item<T> *pNewItem = new Item<T>(Value,m_pStart);

	if (IsEmpty())
	{
		m_pStart = pNewItem;

	}
	else
	{
		Item<T> *pCurrent = m_pStart;
		while (pCurrent->m_pNext != m_pStart) {
			pCurrent = pCurrent->m_pNext;
		}
		pCurrent->m_pNext = pNewItem;
		
	}

	++m_size;
}

template <class T>
void CyclicList<T>::PopFront()
{
	if (IsEmpty())
		return;

	Item<T> *pStartItemToBeDeleted = m_pStart;
	Item<T> *pCurrent = m_pStart;
	while (pCurrent->m_pNext != m_pStart) {
		pCurrent = pCurrent->m_pNext;
	}
	m_pStart = m_pStart->m_pNext;
	
	pCurrent->next = m_pStart;
	
	
	--m_size;

	delete pStartItemToBeDeleted;
}

template <class T>
void CyclicList<T>::PopBack()
{
	if (!IsEmpty())
		RemoveAt(m_size - 1);
}

template <class T>
T& CyclicList<T>::GetStartData()
{
	if (m_size == 0)
		throw std::exception();

	return m_pStart->m_data;
}

template <class T>
const T& CyclicList<T>::GetStartData() const
{
	return const_cast<CyclicList<T>*>(this)->GetStartData();
}

template <class T>
T& CyclicList<T>::GetEndData()
{
	if (m_size == 0)
		throw std::exception();

	return m_pEnd->m_data;
}

template <class T>
const T& CyclicList<T>::GetEndData() const
{
	return const_cast<CyclicList<T>*>(this)->GetEndData();
}

template <class T>
T & CyclicList<T>::At(size_t Index)
{
	if (Index >= m_size)
		throw std::out_of_range("Index exceeded the size");

	return FindItemAt(Index)->m_data;
}

template <class T>
const T & CyclicList<T>::At(size_t Index) const
{
	if (Index >= m_size)
		throw std::out_of_range("Index exceeded the size");

	return FindItemAt(Index)->m_data;
}

template <class T>
void CyclicList<T>::RemoveAt(size_t Index)
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

