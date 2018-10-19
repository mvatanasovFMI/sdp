#include <iostream>
#include <fstream>
#include "Stack.h"
using namespace std;
/*
int main() {

	int n;
	cout << "Enter number of elements: ";
	cin >> n;
	Stack num_stack;
	for (int i = 0; i < n; i++) {
		cout << "Enter number: ";
		float number;
		cin >> number;
		num_stack.push(number);
		cout << endl << "Pushed element: " << number << endl;
	} 
	num_stack.print();
	system("pause");
	return 0;
}

*/

int main(int argc, char* argv[]) {
fstream myFile("C:\\Users\\grade\\source\\repos\\Stack\\stackData.txt", std::ios_base::in|std::ios_base::out);

float a;
Stack num_stack;
while (myFile >> a) {
   //printf("%f",a);

   
   num_stack.push(a);
   cout << endl << "Pushed element: " << a << endl;
}
//num_stack.print();

num_stack.sort();
//num_stack.print();
ofstream oFile("C:\\Users\\grade\\source\\repos\\Stack\\stackData.txt");
while (!(num_stack.empty())) {
	oFile << num_stack.top();
	cout << num_stack.top() << endl;
	num_stack.pop();
}
system("pause");
return 0;

} 