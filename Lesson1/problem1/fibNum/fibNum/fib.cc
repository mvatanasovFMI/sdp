#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

typedef unsigned long long ull;

const int SIZE = 45;

ull findFibNumRec(int n, ull* fibNum)
{
	if (fibNum[n] != 0 || n <= 1) return fibNum[n];
	fibNum[n] = findFibNumRec(n - 1, fibNum) + findFibNumRec(n - 2, fibNum);
	return fibNum[n];
}

ull findFibNumIterative(int n)
{
	if (n <= 0) return 0;
	if (n == 1) return 1;
	int a = 0, b = 1, c;
	for (int i = 0; i < n - 1; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int main()
{
	ull fibNum[SIZE] = { 0 };
	
	fibNum[0] = 0;
	fibNum[1] = 1;
	int n;
	cin >> n;
	auto start = chrono::high_resolution_clock::now();
	cout << findFibNumRec(n, fibNum) << endl;
	auto end = chrono::high_resolution_clock::now();
	auto nanosec = chrono::duration_cast<chrono::nanoseconds> (end - start);
	cout << nanosec.count() << endl;
	auto start2 = chrono::high_resolution_clock::now();
	cout << findFibNumIterative(n) << endl;
	auto end2 = chrono::high_resolution_clock::now();
	nanosec = chrono::duration_cast<chrono::nanoseconds> (end2 - start2);
	cout << nanosec.count() << endl;
	system("pause");
	return 0;
}