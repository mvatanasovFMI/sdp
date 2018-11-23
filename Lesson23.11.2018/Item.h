#pragma once
template <class T>
class Item {
public:
	T m_data;
	Item* m_pNext;

public:
	Item(const T & m_data, Item *m_pNext = nullptr)
		: m_data(m_data), m_pNext(m_pNext)
	{
	}

	bool HasSuccessor() const
	{
		return m_pNext != nullptr;
	}
};
