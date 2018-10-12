#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int fib(int n)
{
	if (n < 0) return -1;
	if (n == 1||n==2) return 1;
	else return fib(n - 1) + fib(n - 2);
}



long long int fib_iterat(int n)
{
	long long int first, second, sum;
	first = 1;
	second = 1;
	sum = 0;
	for (int i = 1; i < n-1; i++)
	{
		sum = first + second;
		first = second;
		second = sum;
	}
	return sum;
}

int main()
{
	int num;
	cout << "Enter number of fibonacci element: ";
	cin >> num;
	auto start = high_resolution_clock::now();
	fib_iterat(num);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(end - start);
	cout << "Time taken by function: "
		<< duration.count() << " nanoseconds" << endl;
	/*cout << fib_iterat(6);
	cout << fib(6) << endl;
	cout << fib_iterat(8);
	cout << fib(8) << endl;*/
	/*auto start = high_resolution_clock::now();
	fib_iterat(num);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(end - start);
	cout << "Time taken by function: "
		<< duration.count() << " nanoseconds" << endl;*/
	system("pause");
	return 0;
}