#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"
using namespace std;

int main() {
	
	fstream myFile("maria.txt");
	//fstream myFile("D:\\a.txt", ios::in);
	if (!myFile) {
		cerr << "File couldn't be opened.\n";
		return 1;
	}
	
    char input;
	Stack<char> str_stack;
	while (myFile.get(input)) {
		str_stack.push(input);
		//cout << endl << "Pushed element: " << input << endl;
	}
	str_stack.print();
	myFile.close();
	system("pause");
	return 0;
}