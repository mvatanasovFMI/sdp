#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
int asdf()
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

		cin.get();
		ifstream fin(filename.c_str());
		if (!fin.is_open())
		{
			cerr << "error: open file for input failed!" << endl;
			abort();
		}
		char readName[MAX_NAME];
		fin.read((char *)&readName, MAX_NAME);
		readName[MAX_NAME - 1] = '\0';
		cout << readName;
		// Read from File
		// To Be implemented
		return 0;
}