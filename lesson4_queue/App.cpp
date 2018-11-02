// ТОДО add includes here if needed
#include "QueueArrayImpl.cpp"
#include "QueueLinkedImpl.cpp"
using namespace std;

int RunQueueArr() {
	queueArr Queue(1000);

	Queue.enqueue(231);
	Queue.enqueue(431);

	cout << "First element: " << Queue.peek() << endl;
	Queue.dequeue();
	Queue.enqueue(111);
	Queue.enqueue(999);

	cout << "Queue size is " << Queue.size() << endl;

	Queue.dequeue();
	Queue.dequeue();

	if (Queue.isEmpty())
		cout << "Queue Is Empty\n";
	else
		cout << "Queue Is Not Empty\n";
}

int RunQueueLinked() {
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
	RunQueueArr();
	RunQueueLinked();

	return 0;
}
