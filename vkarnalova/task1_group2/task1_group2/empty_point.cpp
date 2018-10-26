#include <iostream>
#include <fstream>
#include <chrono>
#include "stack.h"
using namespace std;
using namespace std::chrono;

int main() {
	auto start = system_clock::now();

	fstream myFile("C:\\Users\\Velina\\source\\repos\\task1_group2\\stack_data.txt");
	if (!myFile) {
		cout << "Error";
		return 1;
	}
	double a;
	Stack data_num;
	while (myFile >> a) {
		data_num.Push(a);
	}
	data_num.SortStack();
	data_num.Print();

	auto end = system_clock::now();
	auto duration = duration_cast<nanoseconds>(end - start);
	cout << duration.count();

	return 0;
}