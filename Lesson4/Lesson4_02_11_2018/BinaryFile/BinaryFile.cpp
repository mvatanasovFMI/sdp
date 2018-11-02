// BinaryFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;



int main()
{
	string filename = "file.bin";

	// Write to File
	ofstream fout(filename, ios::out | ios::binary);
	if (!fout.is_open()) {
		cerr << "error: open file for output failed!" << endl;
		return 0;
	}
	const int MAX_NAME = 256;
	char name[MAX_NAME];
	cout << "Input your name" << endl;
	cin.getline(name, MAX_NAME);

	fout.write((char *)&name, MAX_NAME);

	fout.close();
	cout << "You enter " << name << endl;

	cin.get();
	// Read from File
	// To Be implemented
	ifstream fin(filename, ios::in | ios::binary);
	if (!fin.is_open()) {
		cerr << "error: open file for input failed!" << endl;
		return 0;
	}
	char nameFromFile[MAX_NAME];
	fin.read((char*)&nameFromFile, MAX_NAME);
	cout << "The name is: " << nameFromFile;
	fin.close();
	system("pause");
	return 0;
}

