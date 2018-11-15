#ifndef DATASTRUCTURES_H_
#define DATASTRUCTURES_H_
#include <iostream>

using namespace std;

const int max_size = 200;

//���������, ����� ���������� � ������������ �� �������� ������ � ������� ������;
template <typename T>
struct Node
{
	Node* next_;
	T data_;
};


//����� ���������� ����, ����� ��������� ������ ��������� �������; ���� ���������� � ��������, ������ ����
//������� ������� � �������� ��������;
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
	void Print();//���� ������������ �� ���� ���������, ��� ���� ������������ � ��� ������ ��������� �� �������� � �������;
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


