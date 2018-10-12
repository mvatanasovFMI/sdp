#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int fib_rec(int num) {
	if (num < 0) return -1;
	else if (num == 1 || num == 2) return 1;
	else if (num > 2) return fib_rec(num - 1) + fib_rec(num - 2);
}

int fib(int num) {
	if (num == 1) return 1;
	else if (num == 2) return 1;
	else if (num > 2) {
		int total = 0;
		int num_a = 1;
		int num_b = 1;
		for (int i = 1; i < num-1; i++) {
			total = num_a + num_b;
			num_a = num_b;
			num_b = total;
		}
		return total;
	}
}

int main() {
	int num;
	cin>>num;
	auto start= system_clock::now();
	cout << fib_rec(num);
	auto end = system_clock::now();
	auto duration=duration_cast<nanoseconds>(end - start);
	cout << duration.count();
	return 0;
}