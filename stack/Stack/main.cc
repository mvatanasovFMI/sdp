#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "stack.h"
using namespace std;

int main()
{
	auto start = chrono::system_clock::now();
	fstream fin("C:\\Users\\grade\\Desktop\\ядо\\sdp\\stack\\stackData.txt", ios::in);
	Stack<double> stack;
	double elem;
	while (fin >> elem)
	{
		stack.push(elem);
	}
	stack.sort();
	stack.print();
	auto end = std::chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	cout << elapsed_seconds.count() << " seconds"<< endl;
	return 0;
}