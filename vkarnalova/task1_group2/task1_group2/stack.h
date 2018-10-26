#include <iostream>
#include <cassert>
using namespace std;

struct Elem {
	double inf;
	Elem* link;
};

class Stack {
private:
	Elem* start;
	void CopyStack(const Stack&);
	void DelStack();
public:
	Stack();
	Stack(const Stack&);
	Stack& operator=(const Stack&);
	~Stack();

	void Push(const double&);
	void Pop(double&);
	double Top();
	bool Empty();
	void SortStack();
	void Print();
};

