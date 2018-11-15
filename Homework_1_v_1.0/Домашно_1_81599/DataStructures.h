#ifndef DATASTRUCTURES_H_
#define DATASTRUCTURES_H_
#include <iostream>

using namespace std;

const int max_size = 200;

//структура, която използваме в реализацията на свързана опашка и свързан списък;
template <typename T>
struct Node
{
	Node* next_;
	T data_;
};


//базов абстрактен клас, който обединява всички изисквани класове; тази реализация е възможна, защото имат
//еднакви функции с различни операции;
template <typename T>
class DataStructure
{
public:
	virtual void Push(T) = 0;
	virtual T Pop() = 0;
	virtual T Top() = 0;
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
	virtual int Length() = 0;
	void Print();//няма необходимост да бъде виртуална, тъй като реализацията и при всички структури от задачата е еднаква;
};

template<typename T>
inline void DataStructure<T>::Print()
{
	while (!IsEmpty())
	{
		cout << Pop() << ' ';
	}
	cout << endl;
}

#endif


