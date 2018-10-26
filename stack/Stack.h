#ifndef STACK_H
#define STACK_H

const int NUM = 300;
template<typename T>
class stack
{
public:
	stack(); 				// конструктор по подразбиране
	void push(const T&); 		// включва елемент в стек
	void pop(T &); 		// изключва елемент от стек
	bool empty() const; 		// проверява дали стек е празен
	bool full() const; 			// проверява дали стек е пълен
	void print(); 			// извежда елементите на стек    
	T getN() {
		return n;
	}
	friend std::ostream& operator<<(std::ostream& os, stack stack);
	friend std::istream& operator>>(std::istream& is, stack stack);

	void quickSort(int low, int high);
	T partition(int low, int high);
private:
	T n; 				// указател към върха на стека
	T arr[NUM]; 			// представяне на стека
};

#endif