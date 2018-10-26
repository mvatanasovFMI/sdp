#include <iostream>
#include <cassert>
using namespace std;

const int MAX = 10000000;

template <typename T>
class Stack {
public:
	Stack(int = MAX);
	~Stack();
	Stack(const Stack<T>&);
	Stack<T>& operator=(const Stack<T>&);
	bool empty() const;
	bool full() const;
	void push(const T&);
	T pop();
	T top() const;
	void print();
	void sort();
private:
	int capacity;
	int topIndex;
	T* arr;
	void copyStack(const Stack<T>&);
	void deleteStack();
	void resize();
	void copyPtr(T const*);

};


template<typename T>
Stack<T>::Stack(int size) : topIndex(-1)
{
	if (size <= 0) { capacity = MAX; }
	else { capacity = size; }
	arr = new T[capacity];
	assert(arr != NULL);

}

template<typename T>
Stack<T>::~Stack()
{
	deleteStack();
}

template<typename T>
Stack<T>::Stack(const Stack<T>& st)
{
	copyStack(st);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& st)
{
	if (this != &st) {
		deleteStack();
		copyStack(st);
	}
	return *this;
}

template<typename T>
bool Stack<T>::empty() const
{
	return topIndex == -1;
}

template<typename T>
bool Stack<T>::full() const
{
	return topIndex == capacity - 1;
}

template<typename T>
void Stack<T>::push(const T& elem)
{
	if (!full()) {
		arr[++topIndex] = elem;
	}
	else { cout << "The stack is full!\n"; exit(1); }
}

template<typename T>
T Stack<T>::pop()
{
	if (!empty()) {
		return arr[topIndex--];
	}
	else { cout << "The stack is empty!\n"; return T(); }
}

template<typename T>
T Stack<T>::top() const
{
	if (!empty()) { return arr[topIndex]; }
	else { cout << "The stack is empty!\n"; return T(); }
}

template<typename T>
void Stack<T>::print()
{
	while (!empty()) {
		cout << pop();
	}
	//cout << endl;
}

template<typename T>
void Stack<T>::copyStack(const Stack<T>& st)
{
	capacity = st.capacity;
	topIndex = st.topIndex;
	arr = new T[capacity];
	assert(arr != NULL);
	copyPtr(st.arr);
}

template<typename T>
void Stack<T>::deleteStack()
{
	delete[] arr;
}

template<typename T>
void Stack<T>::resize()
{
	T* oldStack = arr;
	arr = new T[2 * capacity];
	copyPtr(oldStack);
	capacity *= 2;
	delete[] oldStack;
}

template<typename T>
void Stack<T>::copyPtr(T const * other)
{
	for (int i = 0; i < capacity; i++) {
		arr[i] = other[i];
	}
}

template<typename T>
void Stack<T>::sort()
{
	for (int i = 0; i < capacity - 1; i++)
	{
		for (int j = 0; j < capacity - i - 1; j++)
			if (arr[j] < arr[j + 1]) {

				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

	}
}


