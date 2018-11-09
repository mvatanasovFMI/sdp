#include "Queue_Element.h"
template <typename T>
class Queue {
private:
	QueueElement<T> * head;
	QueueElement<T> * tail;
	void copyQueue(const Queue &);
	void deleteQueue();
public:
	Queue();
	Queue(const Queue &);
	Queue & operator=(const Queue &);
	~Queue();

	void push(T);
	T pop();
	T top() const;
	bool isEmpty() const;
};

template <typename T>
void Queue<T>::copyQueue(const Queue & Other)
{
	QueueElement<T> * tempPointer = Other.head;
	while (tempPointer != Other.tail)
	{
		this->push(tempPointer->data);
		tempPointer = tempPointer->next;
	}
	this->push((Other.tail)->data);
}
template <typename T>
void Queue<T>::deleteQueue()
{
	while (this->head != this->tail)
		{
			QueueElement<T> * tempPointer = this->head;
			this->head = (this->head)->next;
			delete tempPointer;
		}
	delete this->tail;
}
template <typename T>
void Queue<T>::push(T dataInput)
{
	QueueElement<T> * tempPointer = new QueueElement<T>();
	tempPointer->data = dataInput;
	tempPointer->next = nullptr;
	if (!this->isEmpty())
	{
		(this->tail)->next = tempPointer;
		this->tail = tempPointer;
		return;
	}
	this->tail = tempPointer;
	this->head = tempPointer;
}
template <typename T>
T Queue<T>::pop()
{
	if (this->isEmpty())
	{
		cerr << "The queue is empty. Please push an item first!";
		return T();
	}
	if (this->head == this->tail)
	{
		T tempValue = (this->tail)->data;
		delete this->tail;
		this->tail = nullptr;
		this->head = nullptr;
		return tempValue;
	}
	QueueElement<T> * tempPointer = (this->head)->next;
	T tempValue = (this->head)->data;
	delete this->head;
	this->head = tempPointer;
	return tempValue;
}
template <typename T>
T Queue<T>::top() const
{
	if (this->isEmpty())
	{
		cerr << "The queue is empty. Please push an item first!";
		return T();
	}
	return (this->tail)->data;
}
template <typename T>
bool Queue<T>::isEmpty() const
{
	return (this->head == nullptr);
}
template <typename T>
Queue<T>::Queue()
{
	this->head = nullptr;
	this->tail = nullptr;
}
template <typename T>
Queue<T>::Queue(const Queue & Other)
{
	if (!Other.isEmpty())
	this->copyQueue(Other);
}
template <typename T>
Queue<T> & Queue<T>::operator=(const Queue & Other)
{
	if (this != &Other && !Other.isEmpty())
	{
		this->deleteQueue();
		this->copyQueue(Other);
	}
	return *this;
}
template <typename T>
Queue<T>::~Queue()
{
	if (!this->isEmpty())
	this->deleteQueue();
}
