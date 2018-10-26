#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <ctime>
#include "stack.h"
using namespace std;

int main()
{
	fstream fin("C:\\ядо-NedkoNedev\\sdp\\Lesson2\\stack\\someText.txt", ios::in);
	Stack<string> stack;
	string elem;
	while (fin >> elem)
	{
		stack.push(elem);
	}
	auto start = chrono::system_clock::now();
	//stack.sort();
	stack.print();
	auto end = std::chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	cout << elapsed_seconds.count() << " seconds"<< endl;
	return 0;
}