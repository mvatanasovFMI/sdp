#pragma once
constexpr auto SIZE = 100;

class QueueArray
{
private:
	int *m_array;
	int m_capacity;
	int m_front;
	int m_rear;
	int m_count;
private:
	void deleteQueue();
	void copyQueue(QueueArray const & queue);
public:
	QueueArray(int size = SIZE);
	QueueArray(QueueArray const &);
	QueueArray& operator=(QueueArray const & queue);
	~QueueArray();
	void dequeue();
	void enqueue(int x);
	int peek();
	int size();
	void display();
	bool isEmpty();
	bool isFull();
};
