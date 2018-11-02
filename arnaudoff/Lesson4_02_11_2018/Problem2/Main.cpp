// Problem2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryIfstream.h"
#include "BinaryOfstream.h"

int main()
{
	const string fileName = "TestBinaryStream.bin";

	BinaryOfstream out(fileName.c_str());
	int length;
	cout << "length: " << endl;
	cin >> length;
	char* name;
	name = new char[length + 1];
	cout << "Name: " << endl;
	cin >> name;

	double pi = 3.14;
	out.SetSize(strlen(name) + 1);
	out << strlen(name) + 1 << name << pi;
	out.close();
	delete name;

	BinaryIfstream in(fileName.c_str());
	uint32_t lengthFromFile;
	in >> lengthFromFile;
	cout << lengthFromFile << endl;
	in.SetSize(lengthFromFile);
	double doubleFromFile;
	char * nameFromFile = new char[lengthFromFile];
	in >> nameFromFile >> doubleFromFile;
	in.close();

	cout << "Name from file = " << nameFromFile;
	delete nameFromFile;

	cin.get(); cin.get();
	return 0;
}

