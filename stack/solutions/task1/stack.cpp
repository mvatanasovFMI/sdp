#include <iostream>
#include <fstream>
#include <time.h>


using namespace std;

const int MAX = 100;

class Stack {
private:
	float a[MAX];
	int topIndex;
	bool full() const;
public:
	Stack();
	
	bool isEmpty() const;
	void push(float const& x);
	void print();
	float pop();
	int top() const;
	void sortStack();
};

Stack::Stack() : topIndex(-1) {}

bool Stack::isEmpty() const {
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

void Stack::print() {
	while(!isEmpty()) {
		printf("%f\n", pop());
	}
}

float Stack::pop() {
	if (isEmpty()) {
		cout << "Stack is empty!" << endl;
		return -1;
	} else {
		return a[topIndex--];
	}
}

int Stack::top() const {
	if (isEmpty()) {
		cout << "Stack is empty!" << endl;
		return -1;
	} else {
		return a[topIndex];
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

int main() {

    clock_t tStart = clock();

	Stack st;

	ifstream StackData;
	StackData.open("../../stackData.txt");

	float n;

	while (StackData >> n) {
		st.push(n);
	}

 	st.sortStack();

 	st.print();

 	printf("\nTime taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}


