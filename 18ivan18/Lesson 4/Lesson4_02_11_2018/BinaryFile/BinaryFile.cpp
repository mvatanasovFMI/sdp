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
	ofstream fout(filename.c_str(), ios::out | ios::binary);
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
	//cout << "You enter " << name << endl;

	//cin.get();
	// Read from File
	fstream file; 
	file.open(filename.c_str());
	if (!file.is_open()) {
		cerr << "error: open file for output failed!" << endl;
		abort();
	}
	file.read((char *)&name, MAX_NAME);
	cout << name;
	file.close();
	// To Be implemented
    return 0;
}

