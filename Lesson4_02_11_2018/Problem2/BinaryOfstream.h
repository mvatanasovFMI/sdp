#pragma once
<<<<<<< HEAD
class BinaryOfstream
{


public:
	BinaryOfstream(const char*);
	void close();


};
=======
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

class BinaryOfstream : public ofstream
{
public:
	BinaryOfstream(const char* fname) :
		ofstream(fname, ios::binary)
	{
		if (!this->is_open()) {
			cerr << "error: open file for output failed!" << endl;
			abort();
		}

	}

	friend BinaryOfstream& operator << (BinaryOfstream& out, const char* ptr);
};

template <typename DataType>
BinaryOfstream& operator << (BinaryOfstream& out, const DataType& data)
{
	out.write((char*)&data, sizeof(DataType));
	return out;
}

BinaryOfstream& operator << (BinaryOfstream& out, char* ptr)
{
	out.write(ptr, strlen(ptr)+1);
	
	return out;
}
>>>>>>> master
