#include<iostream>
#include<chrono>
#include <ctime>
using namespace std;
const int kSize = 50;
long long fibonacci_rec(int number_of_member)
{
	if (number_of_member == 0) return 0;
	if (number_of_member == 1) return 1;
	return fibonacci_rec(number_of_member - 1) + fibonacci_rec(number_of_member - 2);
}

long long fibonacci_it(int number_of_member)
{
	long long fibonacci_seq[50];
	fibonacci_seq[0] = 0;
	fibonacci_seq[1] = 1;
	for (int i = 2; i <= number_of_member; i++)
	{
		fibonacci_seq[i] = fibonacci_seq[i - 1] + fibonacci_seq[i-2];
	}
	return fibonacci_seq[number_of_member];
}

int main()
{
	auto start = chrono::system_clock::now();
	cout << fibonacci_rec(40) << endl;
	auto finish = chrono::system_clock::now();

	chrono::duration<double> diff = finish - start;
	cout << "time: " << diff.count() << endl;
	auto start2 = chrono::system_clock::now();
	cout << fibonacci_it(40) << endl;
	auto finish2 = chrono::system_clock::now();
	chrono::duration<double> diff2 = finish2 - start2;
	cout << "time: " << diff2.count() << endl;
	system("pause");
	return 0;
}