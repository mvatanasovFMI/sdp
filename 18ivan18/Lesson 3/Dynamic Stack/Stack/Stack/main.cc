#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"

using namespace std;

int main() {
	fstream file;
	char c;
	Stack<char> s;
	file.open("data.txt");
	while (file.get(c))
	{
		s.push(c);
	}
	
	file.close();
	
	s.print();


	return 0;
}