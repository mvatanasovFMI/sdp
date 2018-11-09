#pragma once
struct Node {
	int m_data;
	Node *m_next;
};

class QueueLinked {
public:
	QueueLinked() 
	{ 
		m_front = m_rear = nullptr; 
		m_count = 0;
	}
	QueueLinked(QueueLinked const &);
	QueueLinked& operator=(QueueLinked const & queue);
	~QueueLinked();
	
	void dequeue();
	void enqueue(int x);
	int peek();
	int size();
	void display();
	bool isEmpty();
private:
	int m_count = 0;
	Node *m_front;
	Node *m_rear;
private:
	void deleteQueue();
	void copyQueue(QueueLinked const & queue);

};

