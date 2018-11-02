#include "stdafx.h"

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>  

using namespace std;

int main()
{
	string filename = "file.bin";

	ofstream fout(filename, ios::out | ios::binary);
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

	char fetched_name[MAX_NAME];
	ifstream fin(filename, ios::in | ios::binary);
	if (!fin.is_open()) {
		cerr << "error: open file for input failed!" << endl;
		abort();
	}

	fin.read((char*)&fetched_name, MAX_NAME);
	fin.close();

	cout << fetched_name << endl;

    return 0;
}

