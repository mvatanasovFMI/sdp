// BinaryFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
	string filename = "file.bin";

	// Write to File
	ofstream fout(filename.c_str(), ios::out | ios::binary);
	if (!fout.is_open()) {
		cerr << "error: open file for output failed!" << endl;
		abort();
	}
	const int MAX_NAME = 256;
	char name[MAX_NAME];
	cout << "Input your name" << endl;
	cin.getline(name, MAX_NAME);

	fout.write((char *)&name, strlen(name));

	fout.close();
	cout << "You enter " << name << endl;

	cin.get();
	// Read from File
	// Todo implemented
	ifstream fin(filename.c_str(), ios::in | ios::binary);
	char name2[MAX_NAME];
	fin.read((char *)&name2, strlen(name));
	cout << name2;
	
    return 0;
}

