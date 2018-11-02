#include<iostream>
#include<chrono>
using namespace std;

int fibRecursive(int n){
	if (n == 1){
		return 1;
	}
	if (n == 2){
		return 1;
	}
	return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int fibIterative(int n){
	if (n == 1){
		return 1;
	}
	if (n == 2){
		return 1;
	}
	int first = 1;
	int second = 1;
	int sum = 0;
	for (size_t i = 3; i <= n; i++)
	{
		sum = first + second;
		first = second;
		second = sum;
	}
	return sum;
}


int main(){
	
	auto then = std::chrono::system_clock::now();
	fibRecursive(12);
	auto now = std::chrono::system_clock::now();
	auto duration = now - then;
	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
	cout << millis.count() << endl;


	then = std::chrono::system_clock::now();
	fibIterative(12);
	now = std::chrono::system_clock::now();
	duration = now - then;
	millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
	cout << millis.count() << endl;

	system("pause");
	return 0;
}
