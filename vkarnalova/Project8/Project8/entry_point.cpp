#include <iostream>
#include <fstream>
#include <chrono>
#include "stack.h"
using namespace std;
using namespace std::chrono;

int main() {

	auto start = system_clock::now();
	
	fstream file("C:\\Users\\grade\\source\\repos\\Project8\\test_stack.txt"); 
	if (!file) {
		cerr << "Error: file couldn't be open!";
		return 1;
	}

	Stack text_stack;
	char ch;
	while (file.get(ch)) {
		text_stack.Push(ch);
	}
	file.close();
	text_stack.Print();

	auto end = system_clock::now();
	auto duration = duration_cast<nanoseconds>(end - start);
	cout << duration.count();

	return 0;
}