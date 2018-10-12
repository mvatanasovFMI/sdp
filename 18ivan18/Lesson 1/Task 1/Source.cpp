#include <iostream>
#include <chrono>

const int SIZE = 50;
using namespace std;

int fib(unsigned long long* fibNum,int n) {
	if (n<=1 || fibNum[n] != 0)
	{
		return fibNum[n];
	}
	else fibNum[n] = fib(fibNum, n - 1) + fib(fibNum, n - 2);
	return fibNum[n];
}

unsigned long long fibIterativ(int n) {
	int first = 1, second =1 ;
	unsigned long long fib;
	if (n<=0)
	{
		return 0;
	}
	else if (n==1 || n==2)
	{
		return 1;
	}
	else {
		for (int i = 2; i < n; i++)
		{
			fib = first + second;
			first = second;
			second = fib;
		}
	}
	return fib;
}

int main() {
	unsigned long long fibNum[SIZE] = { 0 };
	fibNum[1] = 1;
	auto start = std::chrono::high_resolution_clock::now();
	cout << fib(fibNum, 40) << endl;
	auto end = chrono::high_resolution_clock::now();
	auto elapsed = chrono::duration_cast<chrono::nanoseconds>( end - start);
	cout << "Recursion Time Elapsed is " << elapsed.count() << endl;


	start = std::chrono::high_resolution_clock::now();
	cout << fibIterativ(40) << endl;
	end = chrono::high_resolution_clock::now();
	elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout << "Iterative Time Elapsed is " << elapsed.count() << endl;
	return 0;

}