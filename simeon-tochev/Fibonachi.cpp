#include "stdafx.h"
#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;


long int fibRec(int n) {
	if (n == 2 || n == 1) {
		return 1;
	}
	else {
		return fibRec(n - 1) + fibRec(n - 2);
	}
}

long int fibIt(int n) {
	int n1 = 1;
	int n2 = 1;
	for (int i = 0; i < n - 2; i++) {
		int sw = n2;
		n2 = n2 + n1;
		n1 = sw;
	}
	return n2;
}

int main() {
	auto t1 = high_resolution_clock::now();
	fibIt(40);
	auto t2 = high_resolution_clock::now();

	auto t3 = high_resolution_clock::now();
	fibRec(40);
	auto t4 = high_resolution_clock::now();

	auto durationItMicro = duration_cast<microseconds>(t2 - t1).count();
	auto durationItNano = duration_cast<nanoseconds>(t2 - t1).count();

	auto durationRecMicro = duration_cast<microseconds>(t4 - t3).count();
	auto durationRecNano = duration_cast<nanoseconds>(t4 - t3).count();

	cout << "Time, Iterative, microseconds: " << durationItMicro << endl;
	cout << "Time, Iterative, nanoseconds: " << durationItNano << endl;
	cout << "Time, Recursive, microseconds: " << durationRecMicro << endl;
	cout << "Time, Recursive, nanoseconds: " << durationRecNano << endl;
	int x;
	cin >> x;
}


/// REC: 3.094
/// IT: 0.172
