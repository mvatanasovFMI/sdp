#include <iostream>
#include <fstream>
#include <time.h>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

const int MAX = 100;

class Stack {
private:
	float a[MAX];
	int topIndex;
	bool full() const;
public:
	Stack();
	
	bool empty() const;
	void push(float const& x);
	void sortStack();
	void printStack();
	float pop();
	int top() const;
};

Stack::Stack() : topIndex(-1) {}

bool Stack::empty() const {
	return topIndex == -1;
}

bool Stack::full() const {
	return topIndex == MAX - 1;
}

void Stack::push(float const& x) {
	if (full()) {
		cout << "Stack is full!" << endl;
	} else {
		a[++topIndex] = x;
	}
}

void Stack::sortStack() {
	int count = topIndex;
	int temp;
	for (int j = 0; j < count; j++)
		for (int i = 0; i < count; i++) {
			if (a[i] > a[i + 1]) {
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
}

void Stack::printStack() {
	while(!empty()) {
		printf("%f\n", pop());
	}
}

float Stack::pop() {
	if (empty()) {
		cout << "Stack is empty!" << endl;
		return -1;
	} else {
		return a[topIndex--];
	}
}

int Stack::top() const {
	if (empty()) {
		cout << "Stack is empty!" << endl;
		return -1;
	} else {
		return a[topIndex];
	}
}

int main() {
	clock_t tStart = clock();

	Stack st1;

	ifstream StackData;
	StackData.open("../../stackData.txt");

	float n;

	while (StackData >> n) {
		st1.push(n);
	}

 	st1.sortStack();

 	st1.printStack();

 	printf("\nTime taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
