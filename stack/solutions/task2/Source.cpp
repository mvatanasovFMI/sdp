#include <iostream>
#include <fstream>
#include <time.h>
#include <string>



using namespace std;

const int MAX = 100000;

template<typename T>

class Stack {
private:
	T a[MAX];
	int topIndex;
	bool full() const;
public:
	Stack();

	bool isEmpty() const;
	void push(float const& x);
	void print();
	T pop();
	T top() const;
	void sortStack();
};

template<typename T>
Stack<T>::Stack() : topIndex(-1) {}

template<typename T>
bool Stack<T>::isEmpty() const {
	return topIndex == -1;
}

template<typename T>
bool Stack<T>::full() const {
	return topIndex == MAX - 1;
}


template<typename T>
void Stack<T>::push(float const& x) {
	if (full()) {
		cout << "Stack is full!" << endl;
	}
	else {
		a[++topIndex] = x;
	}
}


template<typename T>
void Stack<T>::print() {
	while (!isEmpty()) {
		printf("%c", pop());
	}
}


template<typename T>
T Stack<T>::pop() {
	if (isEmpty()) {
		cout << "Stack is empty!" << endl;
		return -1;
	}
	else {
		return a[topIndex--];
	}
}


template<typename T>
T Stack<T>::top() const {
	if (isEmpty()) {
		cout << "Stack is empty!" << endl;
		return -1;
	}
	else {
		return a[topIndex];
	}
}


template<typename T>
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

int main() {

	//clock_t tStart = clock();

	Stack<char> st;

	ifstream StackData;
	StackData.open("lipsum.txt");

	char n;

	while (StackData.get(n)) {
		st.push(n);
	}

	//st.sortStack();

	st.print();

	//printf("\nTime taken: %.6fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	return 0;
}

