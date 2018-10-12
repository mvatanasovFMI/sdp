#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;


long long fib(long long n) {
	if (n == 1 || n == 2) return 1;
	return fib(n - 1) + fib(n - 2);
}

long long fib2(long long n) {
	long long previous1 = 1, previous2 = 1;
	long long number;
	for (int i = 0; i < n - 2; i++) {
		number = previous1 + previous2;
		previous1 = previous2;
		previous2 = number;
	}
	return number;
}


int main() {
	auto start = std::chrono::high_resolution_clock::now();
	cout << fib(25) << endl;
	auto end = std::chrono::high_resolution_clock::now();
	auto timeFirst = std::chrono::duration_cast<chrono::nanoseconds> (end - start);
	start = std::chrono::high_resolution_clock::now();
	cout << "Duration First: " << timeFirst.count() << endl;
	cout << fib2(25) << endl;
	end = std::chrono::high_resolution_clock::now();
	auto timeSecond = std::chrono::duration_cast<chrono::nanoseconds> (end - start);
	cout << "Duration Second: " << timeSecond.count() << endl;
	system("pause");
	return 0;
}