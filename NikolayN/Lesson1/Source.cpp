#include<iostream>
#include <chrono>
#include<ctime>
using namespace std;
int fibb(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibb(n - 1) + fibb(n - 2);
}
int main()	
{
	int n;
	cin >> n;
	/*int a = 0;
	int b = 1;	
	for (size_t i = 0; i < n; i++)
	{
		if (i % 2 == 0) { a = a + b; }
		else if (i % 2 == 1) { b = a + b; }
	}
	std::cout << a << "!";*/
	auto start = std::chrono::system_clock::now();
	cout << fibb(n) << endl;
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = end - start;
	cout << "time :" << diff.count();
	system("pause");
}

