#ifndef DATASTRUCTURES_H_
#define DATASTRUCTURES_H_
#include <iostream>

using namespace std;

const int max_size = 200;

//a structure used in the LinkedQueue and the LinkedStack realisation;
template <typename T>
struct Node
{
	Node* next_;
	T data_;
};


//Basic abstract class which unites all the required data structures;
//this realisation is possible, as all classes use the same function names with different operations in them;
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
	void Print();//doesn't need to be virtual, as it's unified for all data structures;
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


