#include <iostream>
#include <fstream>
#include "stack.h"
using namespace std;




int main() {

	
	fstream myFile("C:\\Users\\grade\\source\\repos\\tesk1_group1\\stackData.txt", std::ios_base::in|ios_base::out);
	if (!myFile) {
		cout << "Error";
		return 1;
	}
	double a;
	Stack data_num;
	while (myFile >> a) {
		data_num.push(a);
	}
	data_num.sortStack();
	
	double num;
	ofstream fout("C:\\Users\\grade\\source\\repos\\tesk1_group1\\stackData.txt");
	while (!data_num.empty()) {
		data_num.pop(num);
		fout<<num;
	}
	

	return 0;
}
