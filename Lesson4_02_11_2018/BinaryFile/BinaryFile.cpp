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

	// Write to File
	ofstream fout("filename.txt", ios::out | ios::binary);
	if (!fout.is_open()) {
		cerr << "error: open file for output failed!" << endl;
		return 1;
	}
	const int MAX_NAME = 256;
	char name[MAX_NAME];
	cout << "Input your name" << endl;
	cin.getline(name, MAX_NAME);

	fout.write((char *)&name, MAX_NAME);

	fout.close();
	cout << "You enter " << name << endl;
	
	// Read from File
	// To Be implemented

	ifstream fin("filename.txt", ios::in | ios::binary);
	if (!fin.is_open()) {
		cerr << "error: open file for output failed!" << endl;
		return 1;
	}
	/*char ch;
	while (fin.get(ch)) {
		cout << ch;
	}*/
	char temp[MAX_NAME];
	fin.read((char*)& temp, MAX_NAME);
	int len = strlen(temp);
	for (int i = 0; i < len; i++) {
		cout << temp[i];
	}

	fin.close();
	

    return 0;
}

