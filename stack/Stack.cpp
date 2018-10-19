#include<iostream>
#include "Stack.h"
#include "chrono"
#include <ctime>
#include <fstream>
using namespace std;

stack::stack() {
	n = -1;
}
void stack::push(const double& x) {
	if (!full()) {
		n++;
		arr[n] = x;
	}
	else {
		cout << "Stack is full!";
		exit(1);
	}
}
void stack::pop(double& x) {
	if (!empty()) {
		x = arr[n];
		n--;
	}
	else {
		cout << "Stack is empty";
		exit(1);
	}
}
bool stack::empty() const {
	return n == -1;
}
bool stack::full() const {
	return NUM == n - 1;
}
void stack::print() {
	double x;
	while (!empty()) {
		pop(x);
		cout << x << " ";
	}
	cout << endl;
}

void swap(double* a, double* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(double low, double high)
{
	double pivot = arr[high];    // pivot
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

void stack::quickSort(double low, double high)
{
	if (low < high)
	{
		double pi = partition(arr, low, high);
		quickSort(low, pi - 1);
		quickSort(pi + 1, high);
	}
}

int main() {
	auto start = chrono::system_clock::now();
	fstream io("C:\\Users\\grade\\Desktop\\sdp-repo\\sdp\\stack", ios::in);
	stack stack;
	double elem;
	while (io >> elem)
	{
		stack.push(elem);
	}
	stack.quickSort();
	stack.print();
	auto end = std::chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	cout << elapsed_seconds.count() << " seconds" << endl;
	return 0;
}