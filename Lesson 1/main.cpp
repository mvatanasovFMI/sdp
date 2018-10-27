#include "stdafx.h"
#include <iostream>
#include <chrono>

int fibonacciSequenceRecursive(int n)
{
	if (n < 3) return 1;
	else return fibonacciSequenceRecursive(n - 1) + fibonacciSequenceRecursive(n - 2);
}

void recursiveTime(int n)
{
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << fibonacciSequenceRecursive(n) << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed_seconds = std::chrono::duration_cast <std::chrono::nanoseconds>(end - start);
	std::cout << elapsed_seconds.count() << '\n';
}

int fibonacciSequenceAdvanced(int n)
{
	int fibonacci[1000] = { 0, 1, 0};
	for (int i = 1; i < n; i++)
	{
		fibonacci[i+1] = fibonacci[i] + fibonacci[i - 1];
	}
	return fibonacci[n];
}

void advancedTime(int n)
{
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << fibonacciSequenceAdvanced(n) << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	std::cout << elapsed_seconds.count() << '\n';
}

int fibonacciSequenceIterative(int n)
{
	int fib1 = 0;
	int fib2 = 1;
	int fibResult = 0;

	for (int i = 1; i < n; i++)
	{
		fibResult = fib1 + fib2;
		fib1 = fib2;
		fib2 = fibResult;
	}

	return fibResult;
}

void iterativeTime(int n)
{
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << fibonacciSequenceIterative(n) << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed_seconds = std::chrono::duration_cast <std::chrono::nanoseconds>(end - start);
	std::cout << elapsed_seconds.count() << '\n';
}

int main()
{
	int n; std::cin >> n;

	iterativeTime(n);
	recursiveTime(n);
	advancedTime(n);
	
	system("pause>0");
    return 0;
}

