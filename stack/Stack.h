#ifndef STACK_H
#define STACK_H

const int NUM = 300;
template<typename T>
class stack
{
public:
	stack(); 				// ����������� �� ������������
	void push(const T&); 		// ������� ������� � ����
	void pop(T &); 		// �������� ������� �� ����
	bool empty() const; 		// ��������� ���� ���� � ������
	bool full() const; 			// ��������� ���� ���� � �����
	void print(); 			// ������� ���������� �� ����    
	T getN() {
		return n;
	}
	friend std::ostream& operator<<(std::ostream& os, stack stack);
	friend std::istream& operator>>(std::istream& is, stack stack);

	void quickSort(int low, int high);
	T partition(int low, int high);
private:
	T n; 				// �������� ��� ����� �� �����
	T arr[NUM]; 			// ����������� �� �����
};

#endif