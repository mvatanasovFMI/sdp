// queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "QueueArray.h"
#include "QueueLinked.h"
using namespace std;

void TestQueueArray() 
{
	QueueArray queue(1000);

	queue.enqueue(231);
	queue.enqueue(431);

	cout << "First element: " << queue.peek() << endl;
	queue.dequeue();
	queue.enqueue(111);
	queue.enqueue(999);

	cout << "queue size is " << queue.size() << endl;

	queue.dequeue();
	queue.dequeue();

	if (queue.isEmpty())
		cout << "queue Is Empty\n";
	else
		cout << "queue Is Not Empty\n";
}

void TestQueueLinked() {
	QueueLinked Queue;
	Queue.display();

	Queue.enqueue(45);
	cout << "First element: " << Queue.peek() << endl;

	Queue.enqueue(28);
	Queue.enqueue(21);

	Queue.display();

	Queue.dequeue();
	Queue.dequeue();

	Queue.display();
}

int main()
{
	TestQueueArray();
	TestQueueLinked();

	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
