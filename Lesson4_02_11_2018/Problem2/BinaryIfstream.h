#pragma once
#include <fstream>
#include <iostream>

#include <cstring>

using namespace std;

class BinaryIfstream : public ifstream
{
private:
	int m_charSize;
public:
	BinaryIfstream(const char* fname) :
		ifstream(fname, ios::binary)
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
	friend BinaryIfstream& operator >> (BinaryIfstream& in, char* ptr);
};

template <typename DataType>
BinaryIfstream& operator >> (BinaryIfstream& in, DataType& data)
{
	in.read((char*)&data, sizeof(DataType));
	return in;
}

BinaryIfstream& operator >> (BinaryIfstream& in, char* ptr)
{
	in.read(ptr, in.m_charSize);
	return in;
}