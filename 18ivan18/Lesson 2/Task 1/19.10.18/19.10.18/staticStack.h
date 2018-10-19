#ifndef STACK
#define STACK
#endif // !STACK

template <typename T>
class staticStack {
private:
	int capacity;
	int top;
	T* data;
	void copy(const staticStack&);
	void del();
	void resize();
public:
	//staticStack();
	staticStack(int = 10);
	staticStack(const staticStack&);
	staticStack& operator=(const staticStack&);
	~staticStack();

	T pop();
	void push(T);
	bool isEmpty();
	bool isFull();
	T peek();

};

template<typename T>
inline void staticStack<T>::copy(const staticStack& other)
{
	capacity = other.capacity;
	top = other.top;
	data = new T[capacity];
	copy(other.data, other.data + top, data);
	
}

template<typename T>
inline void staticStack<T>::del()
{
	delete data;
}

template<typename T>
inline staticStack<T>::staticStack(int capacity):capacity(capacity),top(-1)
{
	data = new T[capacity];
}

template<typename T>
inline staticStack<T>::staticStack(const staticStack<T> & other)
{
	copy(other);
}

template<typename T>
inline staticStack<T> & staticStack<T>::operator=(const staticStack<T>& other)
{
	// TODO: insert return statement here
	if (this!=&other)
	{
		del();
		copy(other);
	}
	return *this;
}

template<typename T>
inline staticStack<T>::~staticStack()
{
	del();
}

template<typename T>
inline void staticStack<T>::resize()
{
	capacity *= 2;
	T* temp = data;
	data = new T[capacity];
	//std::copy(temp, temp + top, data);
	for (int i = 0; i <= top; i++)
	{
		data[i] = temp[i];
	}
	delete temp;
}

template<typename T>
inline T staticStack<T>::pop()
{
	if (isEmpty())
	{
		cout << "Stack is empty!";
		exit(1);
	}
	return data[top--];
}

template<typename T>
inline void staticStack<T>::push(T other)
{
	if (isFull())
	{
		resize();
	}
	data[++top] = other;
}

template<typename T>
inline bool staticStack<T>::isEmpty()
{
	return top == -1;
}

template<typename T>
inline bool staticStack<T>::isFull()
{
	return top + 1 == capacity;
}

template<typename T>
inline T staticStack<T>::peek()
{
	if (isEmpty())
	{
		cout << "Stack is empty!";
		exit(1);
	}
	return data[top];
}
