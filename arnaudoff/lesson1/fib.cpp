#include "stdafx.h"
#include <iostream>
#include <chrono>

using namespace std;

unsigned long long fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	return fib(n - 1) + fib(n - 2);
}

unsigned long long fibonnaciIterative(int n) {
	if (n == 1 || n == 2) return 1;
	else {
		int firstTerm = 1;
		int secondTerm = 1;
		int sum = 0;

		for (int i = 1; i < n - 1; i++) {
			sum = firstTerm + secondTerm;
			firstTerm = secondTerm;
			secondTerm = sum;
		}

		return sum;
	}
}

int main()
{
	const int N = 40;
	cout << "Calculating " << N << "th Fibonacci number" << endl;

	auto recursionStart = std::chrono::high_resolution_clock::now();

	fib(40);

	auto recursionEnd = std::chrono::high_resolution_clock::now();
	auto recursionElapsed = chrono::duration_cast<chrono::nanoseconds>(recursionEnd - recursionStart);

	cout << "Recursion (no memoization) elapsed time: " << recursionElapsed.count() << " ns" << endl ;

	auto iterationStart = std::chrono::high_resolution_clock::now();

	fibonnaciIterative(40);

	auto iterationEnd = std::chrono::high_resolution_clock::now();
	auto iterationElapsed = chrono::duration_cast<chrono::nanoseconds>(iterationEnd - iterationStart);

	cout << "Iteration elapsed time: " << iterationElapsed.count() << " ns" << endl;

    return 0;
}