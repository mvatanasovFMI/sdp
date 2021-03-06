// Problem2_Solved.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "BinaryIfstream.h"
#include "BinaryOfstream.h"

int main()
{
	const string fileName = "test.bin";

	BinaryOfstream out(fileName.c_str());
	int length;
	cout << "length: " << endl;
	cin >> length;
	char* name = new char[length+1];
	cout << "Name: " << endl;
	cin >> name;
	
	double pi = 3.14;
	int nameLength = strlen(name) + 1;
	out << nameLength << name << pi;
	out.close();
	delete name;

	BinaryIfstream in(fileName.c_str());
	int lengthFromFile = 0;
	in >> lengthFromFile;
	in.SetSize(lengthFromFile);
	double doubleFromFile = 0.0;
	char * nameFromFile = new char[lengthFromFile];
	in >> nameFromFile >> doubleFromFile;
	in.close();

	cout << "LENGTH = " << lengthFromFile << endl;
	cout << "Name from file = " << nameFromFile << endl;
	cout << "Double from file = " << doubleFromFile << endl;

	delete nameFromFile;
	
	cin.get(); cin.get();
	return 0;
}


