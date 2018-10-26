#include<iostream>
#include<fstream>
#include<time.h>
#include "Stack.h"
using namespace std;

int main()
{
	Stack st;
	ifstream myfile;
	myfile.open("text.txt");
	char c1;
	double beg_time, end_time;
	beg_time = clock();
	while (myfile.get(c1))
	{
		while (c1 != ' ')
		{
			st.push(c1);
			if (!myfile.get(c1)) break;
		}
		st.pop();
		cout << endl;
	}
	cout << endl;
	end_time = clock();
	cout << end_time << endl;
	cout << (end_time - beg_time) / CLOCKS_PER_SEC;
	cout << endl;
	system("pause");
}