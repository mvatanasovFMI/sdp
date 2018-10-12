#include <iostream>
#include <ctime>
#include <chrono>
#pragma warning(disable: 4996)

using namespace std;
int fibonnaci(int n)
{
	int firstNumber = 0, secondNumber = 1, tempNumber = 0;
	for (int i = 1; i < n; i++)
	{
		tempNumber = firstNumber;
		firstNumber = secondNumber;
		secondNumber += tempNumber;
	}
	return firstNumber;
}
int reccursiveFibonnaci(int n)
{
	if (n == 1)
	{
		return 0;
	}
	else if (n == 2)
	{
		return 1;
	}
	return reccursiveFibonnaci(n - 1) + reccursiveFibonnaci(n - 2);
}
int main()
{
	std::chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::system_clock::now();
	cout<<fibonnaci(7)<<endl;
	end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "finished computation at " << std::ctime(&end_time)
		<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	system("pause");
}