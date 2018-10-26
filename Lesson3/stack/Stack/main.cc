#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <ctime>
#include <stack>
#include "my-stack.h"
using namespace std;

int main()
{
	fstream fin("C:\\ядо-NedkoNedev\\sdp\\Lesson2\\stack\\someText.txt", ios::in);
	MyStack<string> stack1;
	string elem;
	while (fin >> elem)
	{
		stack1.push(elem);
	}
	auto start = chrono::system_clock::now();
	//stack.sort();
	stack1.print();
	auto end = std::chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	cout << elapsed_seconds.count() << " seconds"<< endl;
	cout << "STL STACK HEREEEEEEE\n";
	stack<string> stackSTL;
	fin.clear();
	fin.seekg(0, ios::beg);
	while (fin >> elem)
	{
		stackSTL.push(elem);
	}
	start = chrono::system_clock::now();
	while (!stackSTL.empty())
	{
		cout << stackSTL.top() << endl;
		stackSTL.pop();
	}
	end = std::chrono::system_clock::now();
	cout << elapsed_seconds.count() << " seconds" << endl;
	fin.close();
	return 0;
}