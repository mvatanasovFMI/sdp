#pragma once
#include <fstream>
#include <iostream>

#include <cstring>

using namespace std;

class BinaryOfstream : public ofstream
{
private:
	int m_charSize;
public:
	BinaryOfstream(const char* fname) :
		ofstream(fname, ios::binary)
	{
		if (!this->is_open()) {
			cerr << "error: open file for output failed!" << endl;
			abort();
		}
	}
	void SetSize(int size)
	{
		m_charSize = size;
	}
	friend BinaryOfstream& operator >> (BinaryOfstream& in, char* ptr);
};

template <typename DataType>
BinaryOfstream& operator >> (BinaryOfstream& in, DataType& data)
{
	in.read((char*)&data, sizeof(DataType));
	return in;
}

BinaryOfstream& operator >> (BinaryOfstream& in, char* ptr)
{
	in.write(ptr, in.m_charSize);
	return in;
}