#include <fstream>
#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#include "Stack.h"
#pragma warning(disable: 4996)
const unsigned int MAX_WORD_SIZE = 7000;
using namespace std;
int main()
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	Stack <string>stack;
	ifstream readFile;
	readFile.open("data.txt");
	while (!readFile.eof())
	{
		string word;
		readFile >> word;
		stack.push(word);
		//readFile.get();
	}
	while (!stack.isEmpty())
	{
		cout<<stack.pop()<<endl;
	}
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "finished computation at " << std::ctime(&end_time)
		<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	system("pause");
}