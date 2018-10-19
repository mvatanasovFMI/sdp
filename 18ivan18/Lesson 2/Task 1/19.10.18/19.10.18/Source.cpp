#include <iostream>
#include "staticStack.h"
#include <fstream>
using namespace std;

int main() {
	staticStack<double> s;
	fstream file;
	file.open("stackData.txt", ios::in);
	
	double number;
	while (file >> number) {
		s.push(number);
	}
	
	file.close();
	return 0;
}