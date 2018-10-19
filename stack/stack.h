#include <iostream>
using namespace std;

const int max = 100;
class Stack {
private:
	int n;
	float arr[max];
public:
	Stack();
	void push(float);
	void pop();
	void print();
	float top() const;
	bool empty() const;
	bool full() const;
	void sort();
};