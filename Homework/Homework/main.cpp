#include<iostream>
#include<time.h>
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#define N 1e7
using namespace std;
int main() {
	ArrayStack<int> as;
	ArrayQueue<int> aq;
	LinkedStack<int> ls;
	LinkedQueue<int> lq;
	double beg_time, end_time;
	int i;
	beg_time = clock();
	for (i = 0; i < N; i++) {
		as.push(i);
		}
	end_time = clock();
	cout << "ArrayStack push method for " << N << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";
	beg_time = clock();
	for (i = 0; i < N; i++) {
		as.pop();
		}
	end_time = clock();
	cout << "ArrayStack pop method for " << N << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";
	
	beg_time = clock();
	for (i = 0; i < N; i++) {
		aq.push(i);
		}
	end_time = clock();
	cout << "ArrayQueue push method for " << N << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";
	beg_time = clock();
	for (i = 0; i < N; i++) {
		aq.pop();
		}
	end_time = clock();
	cout << "ArrayQueue pop method for " << N << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";

	beg_time = clock();
	for (i = 0; i < N; i++) {
		ls.push(i);
		}
	end_time = clock();
	cout << "LinkedStack push method for " << N << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";
	beg_time = clock();
	for (i = 0; i < N; i++) {
		ls.pop();
		}
	end_time = clock();
	cout << "LinkedStack pop method for " << N << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";

	beg_time = clock();
	for (i = 0; i < N; i++) {
		lq.push(i);
		}
	end_time = clock();
	cout << "LinkedQueue push method for " << N << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";
	beg_time = clock();
	for (i = 0; i < N; i++) {
		lq.pop();
		}
	end_time = clock();
	cout << "LinkedQueue pop method for " << N << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";
	system ("PAUSE");
	return 0;
}