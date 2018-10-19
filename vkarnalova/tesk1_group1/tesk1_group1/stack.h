#include <iostream>
const int SIZE = 50;

using namespace std;

class Stack {
private:
	double arr[SIZE];
	int top;
public:
	Stack();
	void push(double);
	void pop(double&);
	bool empty() const;
	bool full() const;
	void sortStack();
	void print();
};

