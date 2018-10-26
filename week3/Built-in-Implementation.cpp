#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <chrono>
#include <stack>

using namespace std;

int main()
{
	stack<string> defStack;
	ifstream iFile("text.txt", ios::in);
	if (!iFile)
	{
		cerr << "File couldn't be opened!\n";
		exit(1);
	}
	iFile.seekg(0, ios::beg);
	string readString;

	auto start = std::chrono::system_clock::now();
	while (iFile >> readString)
	{
		defStack.push(readString);
	}

	stack<string> defStackInvert;
	while (!defStack.empty())
	{
		readString = defStack.top();
		defStack.pop();
		defStackInvert.push(readString);
	}

	while (!defStackInvert.empty())
	{
		readString = defStackInvert.top();
		cout << readString << endl;
		defStackInvert.pop();
	}
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	cout << elapsed_seconds.count() << endl;

	system("pause>0");
	return 0;
}

