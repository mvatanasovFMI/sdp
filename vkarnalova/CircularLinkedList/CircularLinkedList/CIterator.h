#pragma once
#include "CItem.h"

template <class T>
class Iterator {
private:
	Item<T> *m_pStart;
	Item<T> *m_pCurrent;

public:
	Iterator(Item<T> *m_pStart) : m_pStart(m_pStart), m_pCurrent(m_pStart)
	{
	}

	T const & GetCurrent() const
	{
		return m_pCurrent->m_data;
	}

	void SetCurrent(T const & Value)
	{
		m_pCurrent->m_data = Value;
	}

	void MoveNext()
	{
		if (m_pCurrent)
			m_pCurrent = m_pCurrent->m_pNext;
	}

	void Rewind()
	{
		m_pCurrent = m_pStart;
	}

	bool EndReached() const
	{
		return m_pCurrent == nullptr;
	}
};
