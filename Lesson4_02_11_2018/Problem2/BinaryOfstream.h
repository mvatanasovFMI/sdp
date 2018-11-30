#pragma once
#include <fstream>
#include <ostream>
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
	friend BinaryOfstream& operator << (BinaryOfstream& out, char* ptr);
};

template <typename DataType>
BinaryOfstream& operator << (BinaryOfstream& out, DataType& data)
{
	out.write((char*)&data, sizeof(DataType));
	return out;
}

BinaryOfstream& operator << (BinaryOfstream& out, char* ptr)
{
	out.write(ptr, out.m_charSize);
	return out;
}
