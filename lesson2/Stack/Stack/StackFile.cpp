#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include "Stack.h"

int main()
{
	std::ifstream fileRead;
	fileRead.open("C:\\AtanasGruev\\stack\\stackData.txt", std::ios::in);
	
	//Directly prints sorted stack

	Stack<double> myStack;
	double num;
	while (fileRead >> num)
	{
		myStack.push(num);
	}
	Stack<double> copyStack = myStack;
	myStack.print();
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << std::endl;
	copyStack.sort().print();
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed_seconds = std::chrono::duration_cast <std::chrono::nanoseconds>(end - start);
	std::cout << std::endl;
	std::cout << elapsed_seconds.count() << '\n';
	
	
	system("pause>0");
	return 0;
}