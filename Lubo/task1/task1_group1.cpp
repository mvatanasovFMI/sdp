#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;

void swap(double*xp, double *yp)
{
	double temp = *xp;
	*xp = *yp;
	*yp = temp;
}


class stack
{

	double* arr;
public:
	int size;

	stack() 
	{
		double* arr = new double[0];
		size = 0;
	}



	void push(double x)
	{
		double* temp = new double[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		 arr = new double[size + 1];
		for (int i = 0; i < size; i++)
		{
			arr[i] = temp[i];
		}
		arr[size] = x;
		size += 1;
		delete[] temp;
	}

	double pop()
	{
		double x = arr[size - 1];
		double* temp = new double[size - 1];
		for (int i = 0; i < size - 1; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		 arr = new double[size - 1];
		for (int i = 0; i < size - 1; i++)
		{
			arr[i] = temp[i];
		}

		size -= 1;
		delete[] temp;
		return x;
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << endl;
		}
	}

	void sort()
	{
		int i, j;
		for (i = 0; i < size - 1; i++)


			for (j = 0; j < size - i - 1; j++)
				if (arr[j] > arr[j + 1])
					swap(&arr[j], &arr[j + 1]);
	}


	//int size() { return size; }
};


	int main() 
	{

		stack a;
		

		auto start = chrono::steady_clock::now();

		

		string line;
		fstream myfile("stackData.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				double x = stod(line);
				a.push(x);
			}
			
		}

		a.print();


		a.sort();

		cout << endl;

		a.print();

		for (int i = 0; i < a.size; i++)
		{
			myfile << i << endl;
		}
		
	myfile.close();

	
		auto end = chrono::steady_clock::now();

		auto diff = end - start;

		cout << endl << endl;

		cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;

		cout << chrono::duration <double, nano>(diff).count() << " ns" << endl;


		system("pause");
		return 0;
	}
