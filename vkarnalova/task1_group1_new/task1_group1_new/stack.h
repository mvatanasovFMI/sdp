#include <iostream>
const int SIZE = 50;

using namespace std;

class Stack {
private:
	double arr[SIZE];
	int top;
	void CopyStack(const Stack&);
public:
	Stack();
	void Push(double);
	void Pop(double&);
	bool Empty() const;
	bool Full() const;
	double Top();
	void SortStack();
	void Print();
};

