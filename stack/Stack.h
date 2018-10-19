#ifndef STACK_H
#define STACK_H

const int NUM = 300;
class stack
{
public:
	stack(); 				// конструктор по подразбиране
	void push(const char&); 		// включва елемент в стек
	void pop(double &); 		// изключва елемент от стек
	bool empty() const; 		// проверява дали стек е празен
	bool full() const; 			// проверява дали стек е пълен
	void print(); 			// извежда елементите на стек    
	char getN() {
		return n;
	}
	void quickSort(double low, double high);
	int partition(double low, double high);
private:
	double n; 				// указател към върха на стека
	double arr[NUM]; 			// представяне на стека
};

#endif