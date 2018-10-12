#include <iostream>
#include <chrono> 
using namespace std;


int fibonacci(int n) {
	if (n == 0 || n == 1) { return 1; }
	else { return fibonacci(n - 1) + fibonacci(n - 2); }
}

long long int fibIter(int n) {

	if (n == 0 || n == 1) { return 1; }
	else {
		long long int first=1;
		long long int second=1;
		long long int sum=0;
		for (int i = 1; i <= n - 1; i++) {
			sum = first + second;
			first = second;
			second = sum;
		}
		return sum;
	}
}

int main() {

	int n = -1;
	while (n < 0) {
		cin >> n;
	}
	auto start = std::chrono::high_resolution_clock::now();
	cout << "Recrusive: " << fibonacci(n) << endl;
	auto finish = std::chrono::high_resolution_clock::now();
	std::cout << "Elapsed time: " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << " s\n";

	start = std::chrono::high_resolution_clock::now();
	cout << "Iterative: " << fibIter(n) << endl;
	finish = std::chrono::high_resolution_clock::now();
	std::cout << "Elapsed time: " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << " s\n";
	

		
	system("pause");
	return 0;

}


	


