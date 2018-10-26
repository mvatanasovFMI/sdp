#include <iostream>
#include <fstream>
#include <time.h>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

const int MAX = 100;

template <typename T>
class Stack {
private:
	T a[MAX];
	int topIndex;
	bool full() const;
public:
	Stack();
	
	bool empty() const;
	void push(T const& x);
	void sortStack();
	void printStack();
	T pop();
	T top() const;
};

template <typename T>
Stack<T>::Stack() : topIndex(-1) {}

template <typename T>
bool Stack<T>::empty() const {
	return topIndex == -1;
}

template <typename T>
bool Stack<T>::full() const {
	return topIndex == MAX - 1;
}

template <typename T>
void Stack<T>::push(T const& x) {
	if (full()) {
		cout << "Stack is full!" << endl;
	} else {
		a[++topIndex] = x;
	}
}

template <typename T>
void Stack<T>::sortStack() {
	int count = topIndex;
	T temp;
	for (int j = 0; j < count; j++)
		for (int i = 0; i < count; i++) {
			if (a[i] > a[i + 1]) {
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
}

template <typename T>
void Stack<T>::printStack() {
	while(!empty()) {
		printf("%f\n", pop()); //TODO: no pop!!
	}
}

template <typename T>
T Stack<T>::pop() {
	if (empty()) {
		cout << "Stack is empty!" << endl;
		return -1;
	} else {
		return a[topIndex--];
	}
}

template <typename T>
T Stack<T>::top() const {
	if (empty()) {
		cout << "Stack is empty!" << endl;
		return -1;
	} else {
		return a[topIndex];
	}
}

int main() {
	clock_t tStart = clock();

	Stack<float> st1;

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
