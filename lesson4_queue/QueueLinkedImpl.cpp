// ТОДО add includes here 

struct Node {
	int data;
	Node *next;
};

class QueueLinked {
public:
	Node *head, *tail;
	QueueLinked() { head = tail = NULL; }

	void enqueue(int n);
	void dequeue();
	void display();
	int peek();
	~QueueLinked();
};

void QueueLinked::dequeue()
{
	// check for queue underflow
	if (isEmpty())
	{
		// TODO some error info
	}

	cout << "Removing " << arr[head] << '\n';

	// TODO get and move head elemet
}

void QueueLinked::enqueue(int item)
{
	// check for queue overflow
	if (isFull())
	{
		// TODO some error info
	}

	cout << "enqueue " << item << '\n';

	// TODO put element
}

int QueueLinked::peek()
{
	if (isEmpty())
	{
		// TODO some error info
	}
	// TODO get element
}

int QueueLinked::size()
{
	// TODO get all elements count
}

bool QueueLinked::isEmpty()
{
	// TODO get element
}

bool QueueLinked::isFull()
{
	// TODO check if queue is full
}
