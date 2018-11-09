#include <iostream>
#include <chrono>
#include <ctime>
#include "array-stack.h"
#include "linked-stack.h"
#include "linked-queue.h"
#include "array_queue.h"

using namespace std;

const int TEST = 100000;

void ArrayStackTest()
{
	cout << "ArrayStack : \n";
	auto start = chrono::system_clock::now();
	
	ArrayStack<int> ast;
	for (int i = 1; i <= TEST; i++)
	{
		ast.push(i);
	}
	int a;
	ArrayStack<int> testAST = ast;
	for (int i = 1; i <= TEST - 20; i++)
	{
		testAST.pop(a);
	}
	testAST.print();
	auto end = std::chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	cout << elapsed_seconds.count() << " seconds" << endl;
}

void LinkedStackTest()
{
	cout << "LinkedStack : \n";
	auto start = chrono::system_clock::now();

	LinkedStack<int> lst;
	for (int i = 1; i <= TEST; i++)
	{
		lst.push(i);
	}
	int a;
	LinkedStack<int> testLST = lst;
	for (int i = 1; i <= TEST - 20; i++)
	{
		testLST.pop(a);
	}
	testLST.print();
	auto end = std::chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	cout << elapsed_seconds.count() << " seconds" << endl;
}


void ArrayQueueTest()
{
	cout << "ArrayQueue : \n";
	auto start = chrono::system_clock::now();

	ArrayQueue<int> aq;
	for (int i = 1; i <= TEST; i++)
	{
		aq.push(i);
	}
	int a;
	ArrayQueue<int> testAQ = aq;
	for (int i = 1; i <= TEST - 20; i++)
	{
		testAQ.pop(a);
	}
	testAQ.print();
	auto end = std::chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	cout << elapsed_seconds.count() << " seconds" << endl;
}

void LinkedQueueTest()
{
	cout << "LinkedQueue : \n";
	auto start = chrono::system_clock::now();

	LinkedQueue<int> q;
	for (int i = 1; i <= TEST; i++)
	{
		q.push(i);
	}
	int a;
	LinkedQueue<int> testLQ = q;
	for (int i = 1; i <= TEST - 20; i++)
	{
		testLQ.pop(a);
	}
	testLQ.print();
	auto end = std::chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	cout << elapsed_seconds.count() << " seconds" << endl;
}

int main()
{
	cout << "We pushed " << TEST << " number of elements and popped all but the last 20. Here are the results : \n";
	ArrayStackTest();
	LinkedStackTest();
	ArrayQueueTest();
	LinkedQueueTest();
	return 0;
}