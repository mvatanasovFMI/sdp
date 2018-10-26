#include <iostream>
#include "Stack.h"
#include "chrono"
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

template <typename T>
stack<T>::stack<T>() {
	n = -1;
}

template <typename T>
void stack<T>::push(T& x) {
	if (!full()) {
		n++;
		arr[n] = x;
	}
	else {
		cout << "Stack is full!";
		exit(1);
	}
}

template <typename T>
void stack<T>::pop(T& x) {
	if (!empty()) {
		x = arr[n];
		n--;
	}
	else {
		cout << "Stack is empty";
		exit(1);
	}
}

template <typename T>
bool stack<T>::empty() const {
	return n == -1;
}

template <typename T>
bool stack<T>::full() const {
	return NUM == n - 1;
}

template <typename T>
void stack<T>::print() {
	T x;
	while (!empty()) {
		pop(x);
		cout << x << " ";
	}
	cout << endl;
}

template <typename T>
void swap(T* a, T* b)
{
	T t = *a;
	*a = *b;
	*b = t;
}

template <typename T>
ostream& operator<<(ostream& os, stack<T>& stack) {
	T x;
	while (!stack.empty()) {
	 stack.pop(x);
	 os << x;
	}
	return os;
}

template <typename T>
istream& operator>>(istream& is, stack<T>& stack) {
	string x;
	while (is>>x) {
		stack.push(x.c_str());
	}
	return is;
}

template <typename T>
T stack::partition(int low, int high)
{
	T pivot = arr[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;   
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

template <typename T>
void stack<T>::quickSort(int low, int high)
{
	if (low < high)
	{
		T pi = partition(arr, low, high);
		quickSort(low, pi - 1);
		quickSort(pi + 1, high);
	}
}


int main() {
	/*
	//Uprajnenie 3
	auto start = chrono::system_clock::now();
	fstream io("C:\\Users\\grade\\Desktop\\sdp-repo\\sdp\\stack", ios::in);
	stack<char> stack;
	double elem;
	while (io >> elem)
	{
		stack.push(elem);
	}
	stack.print();
	auto end = std::chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	cout << elapsed_seconds.count() << " seconds" << endl;
	return 0;*/

	//Uprajnenie 4

	fstream fileOutput("C:\\Users\\grade\\Desktop\\sdp-repo\\sdp\\stack\\write.txt", ios::out);
	fstream fileInput("C:\\Users\\grade\\Desktop\\sdp-repo\\sdp\\stack\\read.txt", ios::in);
	stack<char> stack;
	operator>>(fileOutput, stack);
	operator<<(fileInput, stack);
	return 0;
}