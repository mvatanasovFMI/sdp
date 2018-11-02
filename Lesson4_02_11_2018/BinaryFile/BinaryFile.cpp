// BinaryFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string filename = "file.bin";

	//// Write to File
	ofstream fout("file.txt", ios::out | ios::binary);
	if (!fout.is_open()) {
		cerr << "error: open file for output failed!" << endl;
		abort();
	}
	const int MAX_NAME = 256;
	char name[MAX_NAME];
	cout << "Input your name" << endl;
	cin.getline(name, MAX_NAME);

	fout.write((char *)&name, MAX_NAME);

	fout.close();
	cout << "You enter " << name << endl;

	/*cin.get();*/
	// Read from File
	// To Be implemented

	ifstream fin("file.txt", ios::in | ios::binary);
	if (!fin.is_open())
	{
		cerr << "error: open file for input failed!" << endl;
		abort();
	}

	char temp[MAX_NAME];

	fin.read((char*)& temp, MAX_NAME);

	size_t length = strlen(temp);
	for (int i = 0; i < length; i++)
	{
		cout << temp[i];
	}
	fin.close();
	system("pause");
    return 0;
}

