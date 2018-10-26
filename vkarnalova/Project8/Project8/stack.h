#include <iostream>
const int SIZE = 4000;

using namespace std;

class Stack {
private:
	char arr[SIZE];
	int top;
	void CopyStack(const Stack&);
public:
	Stack();
	void Push(char);
	void Pop(char&);
	bool Empty() const;
	bool Full() const;
	double Top();
	void Print();
};


