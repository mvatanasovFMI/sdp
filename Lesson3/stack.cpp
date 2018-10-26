#include <iostream>
#include <cassert>
#include <fstream>
#include <chrono>
#include <string>
#include <stack>
using namespace std;

const int NUM = 20;

template <typename T>
class Stack {
private:
	T* arr;
	int size;
	int capacity;
public:
	Stack();
	~Stack();
	Stack(const Stack<T>&);
	Stack<T>& operator=(const Stack<T>&);
	void push(const T&);
	void pop(T&);
	T& top() const;
	bool isEmpty() const;
	void print() const;
};
template <typename T>
Stack<T>::Stack() {
	capacity = 10;
	size = 0;
	arr = new T[capacity];
	assert(arr != NULL);
}
template <typename T>
Stack<T>::~Stack() {
	delete[] arr;
}
template <typename T>
Stack<T>::Stack(const Stack<T>& other) {
	capacity = other.capacity;
	size = other.size;
	arr = new T[capacity];
	assert(arr != NULL);
	for (int i = 0; i < size; i++) arr[i] = other.arr[i];
}
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
	if (this != &other) {
		delete[] arr;
		capacity = other.capacity;
		size = other.size;
		arr = new T[capacity];
		assert(arr != NULL);
		for (int i = 0; i < size; i++) arr[i] = other.arr[i];
	}
	return *this;
}
template <typename T>
void Stack<T>::push(const T& newElement) {
	if (size >= capacity) {
		capacity += NUM;
		T* temp = arr;
		arr = new T[capacity];
		assert(arr != NULL);
		for (int i = 0; i < size; i++) arr[i] = temp[i];
		size++;
		arr[size - 1] = newElement;
		delete[] temp;
	}
	else {
		arr[size] = newElement;
		size++;
	}
}
template <typename T>
void Stack<T>::pop(T& element) {
	if (isEmpty()) {
		cout << "the stack is empty!";
		return;
	}
	element = arr[size - 1];
	size--;
}
template <typename T>
T& Stack<T>::top() const {
	return arr[size - 1];
}
template <typename T>
bool Stack<T>::isEmpty() const {
	return size == 0;
}
template <typename T>
void Stack<T>::print() const {
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl;
}

template <typename T>
Stack<T> sortStack(Stack<T>& stack) {
	Stack<T> tempStack;
	while (!stack.isEmpty()) {
		T temp, x;
		stack.pop(temp);
		while (!tempStack.isEmpty() && tempStack.top() > temp) {
			tempStack.pop(x);
			stack.push(x);
		}
		tempStack.push(temp);
	}

	return tempStack;
}


int main() {

	Stack<string> stackOne;
	ifstream myFile("C:\\mdobrinov\\sdp\\stack\\stackData.txt", ios::in);
	string text;
	while (myFile >> text) {
		stackOne.push(text);
	}
	stackOne.print();
	cout << endl;
	string var;
	auto start = std::chrono::high_resolution_clock::now();
	while (!stackOne.isEmpty()) {
		stackOne.pop(var);
		cout << var << " ";
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<chrono::nanoseconds> (end - start);
	cout << endl;
	cout << "Duration: " << time.count() << endl;
	stack<string> otherStack;
	myFile.clear();
	myFile.seekg(0, ios::beg);
	while (myFile >> text) {
		otherStack.push(text);
	}
	while (!otherStack.empty()) {
		cout << otherStack.top() << " ";
		otherStack.pop();
	}
	system("pause");
	return 0;
}


