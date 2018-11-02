// ТОДО add includes here  if needed

constexpr auto SIZE = 100;

class QueueArr
{
	int *arr;
	int capacity;
	int head;
	int tail;
	int count;

public:
	QueueArr(int size = SIZE);

	void dequeue();
	void enqueue(int x);
	int peek();
	int size();
	bool isEmpty();
	bool isFull();
};

QueueArr::QueueArr(int size)
{
	arr = new int[size];
	capacity = size;
	head = 0;
	tail = -1;
	count = 0;
}

void QueueArr::dequeue()
{
	if (isEmpty())
	{
		// TODO some error info
	}

	cout << "Removing " << arr[head] << '\n';

	// TODO get and remove element
}

void QueueArr::enqueue(int item)
{
	if (isFull())
	{
		// TODO some error info
	}

	cout << "enqueue " << item << '\n';

	// TODO put element
}

int QueueArr::peek()
{
	if (isEmpty())
	{
		// TODO some error info
	}
	// TODO get element
}

int QueueArr::size()
{
	// TODO get all elements count
}

bool QueueArr::isEmpty()
{
	// TODO get element
}

bool QueueArr::isFull()
{
	// TODO check if queue is full
}
