const unsigned int MAX_QUEUE_SIZE = 1000;
template <typename T>
class Queue {
private:
	T data[MAX_QUEUE_SIZE];
	bool isFull;
	int inPosition;
	int outPosition;
	void copy(const Queue &);
	void copyQueue(const Queue &);
public:
	Queue();
	Queue(const Queue &);
	Queue & operator=(const Queue &);

	bool isEmpty();
	void push(T);
	T pop();
	T top();
};

template <typename T>
void Queue<T>::copy(const Queue & Other)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		*(this->data + i) = *(Other.data + i);
	}
}
template <typename T>
void Queue<T>::push(T dataInput)
{
	if (this->isFull)
	{
		cerr << "The queue is full. Please pop an item first!";
		return;
	}
	*(this->data + this->inPosition) = dataInput;
	this->inPosition = (this->inPosition + 1) % MAX_QUEUE_SIZE;
	this->isFull = (this->inPosition == this->outPosition);
}
template <typename T>
bool Queue<T>::isEmpty()
{
	return (this->inPosition == this->outPosition && !(this->isFull));
}
template <typename T>
T Queue<T>::pop()
{
	if (this->isEmpty())
	{
		cerr << "The queue is empty. Please push an item first!";
		return T();
	}
	T tempValue = (*(this->data + this->outPosition));
	this->outPosition = (this->outPosition + 1) % MAX_QUEUE_SIZE;
	return tempValue;
}
template <typename T>
T Queue<T>::top()
{
	if (this->isEmpty())
	{
		cerr << "The queue is empty. Please push an item first!";
		return T();
	}
	return (*(this->data + outPosition));
}
template <typename T>
void Queue<T>::copyQueue(const Queue & Other)
{
	this->copy(Other);
	this->inPosition = Other.inPosition;
	this->outPosition = Other.outPosition;
	this->isFull = Other.isFull;
}
template <typename T>
Queue<T>::Queue(const Queue & Other)
{
	this->copyQueue(Other);

}
template <typename T>
Queue<T> & Queue<T>::operator=(const Queue & Other)
{
	if (this != &Other)
	{
	this->deleteQueue();
	this->copyQueue(Other);
	}
	return *this;
}
template <typename T>
Queue<T>::Queue()
{
	isFull = false;
	inPosition = 0;
	outPosition = 0;
}

