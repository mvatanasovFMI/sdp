#include <iostream>
#include <fstream>
using namespace std;
const MAX = 100;
template <typename T>

class Stack {
private:
	T a[MAX];
	int topIndex;
	void full();

public:
	Stack();

	bool empty() const;
	void push(&T const);
	T pop();
	T top()const;
	T print() const;
};

template <typename T>
Stack <T>::Stack() : topIndex(-1) {}

template <typename T>
bool Stack <T>::empty() const {
	return topIndex == -1;
}

template <typename T>
bool Stack<T>::full() const {
	return topIndex == MAX - 1;
}

template <typename T>
void Stack<T>::push(&T const el){
	if (full()) {
		cerr << "Error" << endl;
	}
	else {
		a[++topIndex] = el;
	}
}

template <typename T>
T Stack<T>::pop() {
	if (empty()) {
		cerr << "Error" << endl;
		return T();
	}
	return a[topIndex--];
}

template <typename T>
T Stack<T>::top() const {
	if (empty()) {
		cerr << "Error" << endl;
		return T();
	}
	return a[topIndex];
}

template <typename T>
T Stack<T>::print() const {
	if (empty()) {
		cerr << "Nqma elementi" << endl;
	}
	for (int i = 0; i < MAX; ++i) {
		cout << a[i] << endl;
	}

}

int main()
{
fstream file("C:\Users\grade\Downloads\aslivarov\Neshto.txt);
	if (!file)
		cerr << "Error" << endl;
return 1;
	Stack test;
	char ch;
	while (file.get(ch)) {
		test.push(ch);
	}
	file.close();
	test.print();
	return 0;
}
















}