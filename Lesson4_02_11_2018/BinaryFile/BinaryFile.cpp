

#include "stdafx.h"
#include <iostream>
#include <fstream>

#include <string>
using  std::cout;
using  std::cin;
using  std::string;
using  std::ofstream;
using  std::ifstream;
using  std::ios;
using  std::endl;
using  std::cerr;



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
		cout << "You enter " << name << endl;

		ifstream fin(filename.c_str(), ios::in | ios::binary);
		char nameFrom[256];
		fin.read(nameFrom, 256);
		cin.get();
		return 0;
	}


