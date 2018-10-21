#include "Stack.h"
#include <fstream>
#include <ctime>
#include <chrono>
#pragma warning(disable: 4996)
using namespace std;
int main()
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	Stack stack;
	ifstream readFile;
	readFile.open("data.txt", ios::in);
	double tempNumber;
	while (readFile >> tempNumber)
	{
		stack.push(tempNumber);
	}
	stack.sortStack();
	readFile.close();
	ofstream writeFile("data.txt", ios::out);
	while (!stack.isEmpty())
	{
		writeFile << stack.top() << endl;
	}
	writeFile.close();
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "finished computation at " << std::ctime(&end_time)
		<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	system("pause");
}