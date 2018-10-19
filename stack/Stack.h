#ifndef STACK_H
#define STACK_H

const int NUM = 300;
class stack
{
public:
	stack(); 				// ����������� �� ������������
	void push(const char&); 		// ������� ������� � ����
	void pop(double &); 		// �������� ������� �� ����
	bool empty() const; 		// ��������� ���� ���� � ������
	bool full() const; 			// ��������� ���� ���� � �����
	void print(); 			// ������� ���������� �� ����    
	char getN() {
		return n;
	}
	void quickSort(double low, double high);
	int partition(double low, double high);
private:
	double n; 				// �������� ��� ����� �� �����
	double arr[NUM]; 			// ����������� �� �����
};

#endif